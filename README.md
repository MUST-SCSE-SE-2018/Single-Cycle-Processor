# Single-Cycle-Processor

### Development Environment
+ System : **Windows 10 64bits**
+ Language : **C, C++**
+ IDE : **Visual Studio Community 2019 v16.8.3**
------

### How to Test
1. Download and install [Strawberry Perl](https://strawberryperl.com/)
2. Clone this repository to desktop
3. Start perl terminal and enter the root
4. Copy a **.asm** file from **Test** or write one by yourself ( ***Assembly Code*** ) under the root
5. Use command `perl minicpuasm.pl example.asm > example.asc` to generate a **.asc** file
6. `CO101Project.exe example.asc < incommand` to show the result
7. You can check the result with those provided demo under the **demo** file

------
### Command List
Start : `CO101Project.exe example.asc -r`

|Command|Meaning|
|:---:|---|
|c|content|
|r|show register|
|m|show memory|
|p|print asc file|
|g|control signal|
|h|state|
|i|capacity (in int 4)|
|s|step|
|q|quit|
|x|quit|

------

### License  
+ [MIT License](https://github.com/KennardWang/Single-Cycle-Processor/blob/master/LICENSE)
------

### Author
+ Kennard Wang ( 2020.11.4 )
------
