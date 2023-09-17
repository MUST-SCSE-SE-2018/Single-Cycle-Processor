# Single-Cycle-Processor

<div align="center">

  [![description](https://img.shields.io/badge/project-Individual-1F1F1F?style=for-the-badge)](https://github.com/KennardWang/Single-Cycle-Processor)
  &nbsp;
  [![stars](https://img.shields.io/github/stars/KennardWang/Single-Cycle-Processor?style=for-the-badge&color=FDEE21)](https://github.com/KennardWang/Single-Cycle-Processor/stargazers)
  &nbsp;
  [![forks](https://img.shields.io/github/forks/KennardWang/Single-Cycle-Processor?style=for-the-badge&color=white)](https://github.com/KennardWang/Single-Cycle-Processor/forks)
  &nbsp;
  [![contributors](https://img.shields.io/github/contributors/KennardWang/Single-Cycle-Processor?style=for-the-badge&color=8BC0D0)](https://github.com/KennardWang/Single-Cycle-Processor/graphs/contributors)
  
  <img src="https://img.shields.io/badge/windows-0078D6?logo=windows&logoColor=white&style=for-the-badge" />
  &nbsp;
  <img src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white" />
  &nbsp;
  <img src="https://img.shields.io/badge/Visual_Studio-5C2D91?style=for-the-badge&logo=visual%20studio&logoColor=white" />
</div>

<br>

It is a project of MUST course ***CO101-Computer Organization***, which is a mini-CPU that could run MIPS.



## Table of Contents

- [Development Environment](#development-environment)
- [Install](#install)
- [Usage](#usage)
- [Tests](#tests)
- [Maintainers](#maintainers)
- [Contributing](#contributing)
- [License](#license)



## Development Environment

| <!-- --> | <!-- --> |
|:---:|:---:|
| System | Windows 10 x64 |
| Language | C |
| Test Assembly Language | MIPS |
| IDE | Visual Studio 2019 Community v16.8.3 |



## Install

+ Install the [Strawberry Perl](https://strawberryperl.com/).
+ Clone the repos:

  ```
  git clone https://github.com/KennardWang/Single-Cycle-Processor.git
  ```



## Usage

1. Open the command line and enter the root.
   ```
   cd Single-Cycle-Processor
   ```
2. Build a `.exe` file with **GCC**.
   ```
   gcc -o scp.exe minicpu.c minicpu.h
   ```
3. Generate a `.asc` file by **Perl** command.
   ```
   perl minicpuasm.pl Test/test01.asm > test.asc
   ```
4. Run the simulation, `incommand` is an integrated command file.
   ```
   scp.exe test.asc < incommand
   ```
5. Run the simulation via separate commands.
   ```
   scp.exe test.asc -r
   ``` 

   <div align=center>
     <img src="https://kennardwang.github.io/ImageSource/Single-Cycle-Processor/cmd.png" width="70%" />
   </div>
   
   Types of commands are shown in the following list.

   |Command|Description|
   |:---:|:---:|
   |c|content|
   |r|show register|
   |m|show memory|
   |p|print asc file|
   |g|control signal|
   |h|state|
   |i|capacity (unit: **int = 4 bytes**)|
   |s|step|
   |q|quit|
   |x|quit|



## Tests

+ test01 & test02

  <div align=center>
    <img src="https://kennardwang.github.io/ImageSource/Single-Cycle-Processor/test01.png" height="220px" />
    &nbsp;
    <img src="https://kennardwang.github.io/ImageSource/Single-Cycle-Processor/test02.png" height="220px" />
  </div>

+ Test_lw&sw

  <div align=center>
    <img src="https://kennardwang.github.io/ImageSource/Single-Cycle-Processor/Test_lw&sw.png" width="70%" />
  </div>

+ Test_Negative

  <div align=center>
    <img src="https://kennardwang.github.io/ImageSource/Single-Cycle-Processor/Test_Negative.png" width="70%" />
  </div>

+ Test_NOR

  <div align=center>
    <img src="https://kennardwang.github.io/ImageSource/Single-Cycle-Processor/Test_NOR.png" width="70%" />
  </div>

+ Test_Halt

  <div align=center>
    <img src="https://kennardwang.github.io/ImageSource/Single-Cycle-Processor/Test_Halt.png" width="70%" />
  </div>

+ Test_Halt_Outofboundary

  <div align=center>
    <img src="https://kennardwang.github.io/ImageSource/Single-Cycle-Processor/Test_Halt_Outofboundary.png" width="70%" />
  </div>



## Maintainers

![badge](https://img.shields.io/badge/maintenance-NO-EF2D5E) [@KennardWang](https://github.com/KennardWang)



## Contributing

Feel free to [open an issue](https://github.com/KennardWang/Single-Cycle-Processor/issues) or submit [PRs](https://github.com/KennardWang/Single-Cycle-Processor/pulls).



## License

[![license](https://img.shields.io/github/license/KennardWang/Single-Cycle-Processor)](LICENSE) © Kennard Wang ( 2020.11.4 )
