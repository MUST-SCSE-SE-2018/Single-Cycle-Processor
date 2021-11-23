# Single-Cycle-Processor

> After learning the single cycle processor in course CO101, Kennard wanted to make a mini-cpu by 
> himself which is simulated by C. This mini-cpu could run MIPS Assembly Language, and Kennard's 
> instructor Yanyan Liang provided him with an efficient testing tool written by Perl.

------

### Test Demo
+ test01

![test](https://kennardwang.github.io/ImageSource/Single-Cycle-Processor/test01.png)

+ test02

![test](https://kennardwang.github.io/ImageSource/Single-Cycle-Processor/test02.png)

+ Test_lw&sw

![test](https://kennardwang.github.io/ImageSource/Single-Cycle-Processor/Test_lw&sw.png)

+ Test_Negative

![test](https://kennardwang.github.io/ImageSource/Single-Cycle-Processor/Test_Negative.png)

+ Test_NOR

![test](https://kennardwang.github.io/ImageSource/Single-Cycle-Processor/Test_NOR.png)

+ Test_Halt

![test](https://kennardwang.github.io/ImageSource/Single-Cycle-Processor/Test_Halt.png)

+ Test_Halt_Outofboundary

![test](https://kennardwang.github.io/ImageSource/Single-Cycle-Processor/Test_Halt_Outofboundary.png)

------

### Development Environment

| Description | Specification |
|:---:|:---:|
| System | Windows 10 |
| Language | C |
| Test Assembly Language | MIPS |
| IDE | Visual Studio 2019 ( Community ) v16.8.3 |

------

### User Manual
1. Download and install [Strawberry Perl](https://strawberryperl.com/).
2. Clone the repository by `git clone https://github.com/KennardWang/Single-Cycle-Processor.git`.
3. Open cmd and enter into the root by `cd Single-Cycle-Processor`.
4. Compile to generate a ***.exe*** file by `gcc -o scp.exe minicpu.c minicpu.h`
5. Open **Perl** terminal and enter into the root `cd Single-Cycle-Processor`.
6. Generate a ***.asc*** file by `perl minicpuasm.pl Test/test01.asm > test.asc`.
7. Start to simulate by `scp.exe test.asc < incommand`.
8. You can also simulate via separated commands by `scp.exe test.asc -r` ( ***incommand*** is an integrated command file ).
9. Type the command which is in the following list

|Command|Description|
|:---:|:---:|
|c|content|
|r|show register|
|m|show memory|
|p|print asc file|
|g|control signal|
|h|state|
|i|capacity ( the unit is **int = 4 bytes** )|
|s|step|
|q|quit|
|x|quit|

![cmd](https://kennardwang.github.io/ImageSource/Single-Cycle-Processor/cmd.png)

------

### License  
+ [MIT License](https://github.com/KennardWang/Single-Cycle-Processor/blob/master/LICENSE)

------

### Author
+ Kennard Wang ( 2020.11.4 )
