#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	Designer: Wang Yuyang, Kennard 
	StuID: 1809853Z-I011-0045
*/

#ifndef MINICPU

typedef struct
{
	char RegDst;
	char Jump;
	char Branch;
	char MemRead;
	char MemtoReg;
	char ALUOp;
	char MemWrite;
	char ALUSrc;
	char RegWrite;

}struct_controls;

void ALU(unsigned A, unsigned B, char ALUControl, unsigned* ALUresult, char* Zero)
{
	// add
	if (ALUControl == 0x0)
		*ALUresult = A + B; 

	// sub
	if (ALUControl == 0x1)
		*ALUresult = A - B; 

	// slt
	if (ALUControl == 0x2) { 
		
		if (A >> 31 == 0x1 && B >> 31 == 0x0) { *ALUresult = 1; }
		else if (A >> 31 == 0x0 && B >> 31 == 0x1) { *ALUresult = 0; }
		else {
			// both negative and positive are the same
			if (A < B)
				*ALUresult = 1;
			else
				*ALUresult = 0;
		}
	}

	// sltu
	if (ALUControl == 0x3) { 
		if (A < B)
			*ALUresult = 1;
		else
			*ALUresult = 0;
	}

	// and
	if (ALUControl == 0x4)
		*ALUresult = A & B;

	// or
	if (ALUControl == 0x5)
		*ALUresult = A | B;

	// lui
	if (ALUControl == 0x6)
		*ALUresult = B << 16;

	// nor
	if (ALUControl == 0x7)
		*ALUresult = ~(A | B);

	if (*ALUresult == 0)
		*Zero = 1;
	else
		*Zero = 0;
}

/* instruction fetch */
int instruction_fetch(unsigned PC, unsigned* Mem, unsigned* instruction)
{
	// jump address check
	if (PC % 4 != 0) { return 1; }

	// Memory address range: 4*16*16*16=16384 ~ 16*16*16*16-1=65535
	if (PC >= 0x4000 && PC <= 0xffff) {
		*instruction = Mem[PC >> 2];
		return 0;
	}
	else { return 1; }
}

/* instruction partition */
void instruction_partition(unsigned instruction, unsigned* op, unsigned* r1, unsigned* r2, unsigned* r3, unsigned* funct, unsigned* offset, unsigned* jsec)
{
	*op = instruction >> 26;
	*r1 = (instruction << 6) >> 27; // rs 5 bits
	*r2 = (instruction << 11) >> 27; // rt 5 bits
	*r3 = (instruction << 16) >> 27; // rd 5 bits
	*funct = (instruction << 26) >> 26; // 6 bits
	*offset = (instruction << 16) >> 16; // 16 bits
	*jsec = (instruction << 6) >> 6; // 26 bits
}

/* instruction decode */
int instruction_decode(unsigned op, struct_controls* controls)
{
	if (op == 0x00) {//R-format
		controls->RegWrite = 1;
		controls->RegDst = 1;
		controls->ALUOp = 7;
		controls->ALUSrc = 0;
		controls->Branch = 0;
		controls->Jump = 0;
		controls->MemRead = 2;
		controls->MemWrite = 0;
		controls->MemtoReg = 0;
	}
	else if (op == 0x08) { // addi
		controls->RegWrite = 1;
		controls->RegDst = 0;
		controls->ALUOp = 0;
		controls->ALUSrc = 1;
		controls->Branch = 0;
		controls->Jump = 0;
		controls->MemRead = 2;
		controls->MemWrite = 0;
		controls->MemtoReg = 0;
	}

	else if (op == 0x23) { // lw
		controls->RegWrite = 1;
		controls->RegDst = 0;
		controls->ALUOp = 1;
		controls->ALUSrc = 1;
		controls->Branch = 0;
		controls->Jump = 0;
		controls->MemRead = 1;
		controls->MemWrite = 0;
		controls->MemtoReg = 1;
	}

	else if (op == 0x2b) { // sw
		controls->RegWrite = 0;
		controls->RegDst = 2;
		controls->ALUOp = 2;
		controls->ALUSrc = 1;
		controls->Branch = 0;
		controls->Jump = 0;
		controls->MemRead = 2;
		controls->MemWrite = 1;
		controls->MemtoReg = 2;
	}

	else if (op == 0x0f) { // lui
		controls->RegWrite = 1;
		controls->RegDst = 0;
		controls->ALUOp = 3;
		controls->ALUSrc = 1;
		controls->Branch = 0;
		controls->Jump = 0;
		controls->MemRead = 2;
		controls->MemWrite = 0;
		controls->MemtoReg = 0;
	}

	else if (op == 0x0a) { // slti
		controls->RegWrite = 1;
		controls->RegDst = 0;
		controls->ALUOp = 4;
		controls->ALUSrc = 1;
		controls->Branch = 0;
		controls->Jump = 0;
		controls->MemRead = 2;
		controls->MemWrite = 0;
		controls->MemtoReg = 0;
	}

	else if (op == 0x0b) { // sltiu
		controls->RegWrite = 1;
		controls->RegDst = 0;
		controls->ALUOp = 5;
		controls->ALUSrc = 1;
		controls->Branch = 0;
		controls->Jump = 0;
		controls->MemRead = 2;
		controls->MemWrite = 0;
		controls->MemtoReg = 0;
	}

	else if (op == 0x04) { // beq
		controls->RegWrite = 0;
		controls->RegDst = 2;
		controls->ALUOp = 6;
		controls->ALUSrc = 0;
		controls->Branch = 1;
		controls->Jump = 0;
		controls->MemRead = 2;
		controls->MemWrite = 0;
		controls->MemtoReg = 2;
	}

	else if (op == 0x02) { // jump
		controls->RegWrite = 0;
		controls->RegDst = 2;
		controls->ALUOp = 8;  
		controls->ALUSrc = 2;
		controls->Branch = 0; 
		controls->Jump = 1;
		controls->MemRead = 2;
		controls->MemWrite = 0;
		controls->MemtoReg = 2;
	}

	else return 1;	//invalid instruction
	return 0;
}

/* Read Register */
void read_register(unsigned r1, unsigned r2, unsigned* Reg, unsigned* data1, unsigned* data2)
{
	*data1 = Reg[r1];
	*data2 = Reg[r2];
}

/* Sign Extend */
void sign_extend(unsigned offset, unsigned* extended_value)
{
	if (offset >> 15 == 0x0) { *extended_value = offset; }
	else {
		*extended_value = (signed)0xffff0000 + offset; // sign-extension
	}
}

/* ALU operations */
int ALU_operations(unsigned data1, unsigned data2, unsigned extended_value, unsigned funct, char ALUOp, char ALUSrc, unsigned* ALUresult, char* Zero)
{
	switch (ALUOp) {
		// R-type
	case 7:
		if (funct == 0x20)
			ALU(data1, data2, 0x0, ALUresult, Zero);	//add
		else if (funct == 0x22)
			ALU(data1, data2, 0x1, ALUresult, Zero);	//sub
		else if (funct == 0x2a)
			ALU(data1, data2, 0x2, ALUresult, Zero);	//slt
		else if (funct == 0x2b)
			ALU(data1, data2, 0x3, ALUresult, Zero);	//sltu
		else if (funct == 0x24)
			ALU(data1, data2, 0x4, ALUresult, Zero);	//and
		else if (funct == 0x25)
			ALU(data1, data2, 0x5, ALUresult, Zero);	//or
		else if (funct == 0x27)
			ALU(data1, data2, 0x7, ALUresult, Zero);	//nor
		else return 1;	//invalid funct

		break;

	// addi
	case 0:
		if (ALUSrc == 1) 
			ALU(data1, extended_value, 0x0, ALUresult, Zero);
		break;

	// lw
	case 1:
		if (ALUSrc == 1)
			ALU(data1, extended_value << 2, 0x0, ALUresult, Zero);
		break;

	// sw
	case 2:
		if (ALUSrc == 1)
			ALU(data1, extended_value << 2, 0x0, ALUresult, Zero);
		break;

	// lui (without rs)
	case 3:
		if (ALUSrc == 1)
			ALU(data1, extended_value, 0x6, ALUresult, Zero);
		break;

	// slti
	case 4:
		if (ALUSrc == 1)
			ALU(data1, extended_value, 0x2, ALUresult, Zero);
		break;

	// sltiu
	case 5:
		if (ALUSrc == 1)
			ALU(data1, extended_value, 0x3, ALUresult, Zero);
		break;

	// beq branch
	case 6:
		ALU(data1, data2, 0x1, ALUresult, Zero);
		break;

	// jump (do nothing)
	case 8:
		break;

	// invalid ALUop
	default:
		return 1;		
	}

	return 0;
}

/* Read / Write Memory */
int rw_memory(unsigned ALUresult, unsigned data2, char MemWrite, char MemRead, unsigned* memdata, unsigned* Mem)
{
	if (MemRead == 1) {
		if (ALUresult >= 0x0000 && ALUresult < 0x4000 && ALUresult % 4 == 0)  // memory address
			*memdata = Mem[ALUresult >> 2];
		else
			return 1;	
	}

	if (MemWrite == 1) {
		if (ALUresult >= 0x0000 && ALUresult < 0x4000 && ALUresult % 4 == 0)
			Mem[ALUresult >> 2] = data2;
		else
			return 1;
	}

	return 0;
}

/* Write Register */
void write_register(unsigned r2, unsigned r3, unsigned memdata, unsigned ALUresult, char RegWrite, char RegDst, char MemtoReg, unsigned* Reg)
{
	if (RegWrite == 1) {
		// R-Type
		if (RegDst == 1 && MemtoReg == 0) {
			memdata = ALUresult;
			Reg[r3] = memdata;
		}

		// addi & lui & slti % sltiu
		if (RegDst == 0 && MemtoReg == 0) {
			memdata = ALUresult;
			Reg[r2] = memdata;
		}

		// lw
		if (RegDst == 0 && MemtoReg == 1) {
			Reg[r2] = memdata;
		}

	}
}

/* PC update */
void PC_update(unsigned jsec, unsigned extended_value, char Branch, char Jump, char Zero, unsigned* PC)
{
	if (Jump == 1) { *PC = jsec << 2; }
	else {
		*PC += 4;
		if (Branch == 1 && Zero == 1) { *PC += 4 * extended_value; }
	}
}
#define MINICPU
#endif
