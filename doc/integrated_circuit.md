# integrated circuit

## semiconductor

常温下导电性能介于导体和绝缘体之间的材料

最简单的半导体: 二极管

![20240604190921](https://raw.githubusercontent.com/Nahida-aa/picgo/main/images/20240604190921.png)

硅原子

![20240604191612](https://raw.githubusercontent.com/Nahida-aa/picgo/main/images/20240604191612.png)

纯洁的硅晶体不导电

![20240604191802](https://raw.githubusercontent.com/Nahida-aa/picgo/main/images/20240604191802.png)

![20240604191901](https://raw.githubusercontent.com/Nahida-aa/picgo/main/images/20240604191901.png)

将磷原子放入其中

![20240604192008](https://raw.githubusercontent.com/Nahida-aa/picgo/main/images/20240604192008.png)

这个自由电子称为多子

这样掺杂出来的就是N型半导体

```
Negative 负的
```

![20240604192436](https://raw.githubusercontent.com/Nahida-aa/picgo/main/images/20240604192436.png)

![20240604192621](https://raw.githubusercontent.com/Nahida-aa/picgo/main/images/20240604192621.png)

白圈那里是空的，没有电子

P型半导体

```
Positive 正的
```

![20240604192845](https://raw.githubusercontent.com/Nahida-aa/picgo/main/images/20240604192845.png)

形成PN结，N中磷原子失去电子所以带正电

![20240604193105](https://raw.githubusercontent.com/Nahida-aa/picgo/main/images/20240604193105.png)

![20240604193322](https://raw.githubusercontent.com/Nahida-aa/picgo/main/images/20240604193322.png)

电子才会源源不断从N流向P

### MOSFET (MOS管)

#### PMOS

#### NMOS

![20240604210119](https://raw.githubusercontent.com/Nahida-aa/picgo/main/images/20240604210119.png)
![20240604210953](https://raw.githubusercontent.com/Nahida-aa/picgo/main/images/20240604210953.png)

栅极通电后，N沟道取代原来半导体中的空穴

## logic gate

### NOT gate

```
as. 非门、反相器、倒相器
```

非门的制作工艺有CMOS、TTL、ECL等，其中CMOS非门是最常用的一种。

CMOS非门由一对互补的金属-氧化物-半导体场效应晶体管（MOSFET）组成，可以实现高速、低功耗的逻辑反相功能

![20240604220537](https://raw.githubusercontent.com/Nahida-aa/picgo/main/images/20240604220537.png)

| in | out |
| ---- | ---- |
| 0    | 1    |
| 1    | 0    |

$in: A$

$out: F=\overline{A}$

## ALU

### adder

### latch

$in: Din[data\ in], WE[write\ enable]$

$out: Dout[data\ out]$

![20240605001955](https://raw.githubusercontent.com/Nahida-aa/picgo/main/images/20240605001955.png)

当$WE$=1时，修改$Din$的值，$Dout$会随之变化

当$WE$=0时，修改$Din$的值，$Dout$的值不变

### clock

带有边缘触发的latch

上升沿latch(信号上升时触发)

![20240605004007](https://raw.githubusercontent.com/Nahida-aa/picgo/main/images/20240605004007.png)

下降沿latch

![20240605003905](https://raw.githubusercontent.com/Nahida-aa/picgo/main/images/20240605003905.png)

$in: Din[data\ in], clock
$

$out: Dout[data\ out]$

当$clock$信号发生下降变化时，$Din$的值传递到$Dout$

### Registers

![20240605005940](https://raw.githubusercontent.com/Nahida-aa/picgo/main/images/20240605005940.png)

#### +enable

给clock增加一个开关$En[enable]$

![20240605011306](https://raw.githubusercontent.com/Nahida-aa/picgo/main/images/20240605011306.png)

给输出也增加一个开关，并增加一个用于显示data的输出(用于便于实验观察，实际不存在)

![20240605013308](https://raw.githubusercontent.com/Nahida-aa/picgo/main/images/20240605013308.png)

#### Regs_nxm/Memory[RAM+ROM+cache]

##### Reg8rc

$in: Din[data\ in], row, column, Str[store, En], clock, Ld[load, OE]$

$out: Dout[data\ out]$

![20240605020137](https://raw.githubusercontent.com/Nahida-aa/picgo/main/images/20240605020137.png)

##### RAM(16x8bit)

![20240605035357](https://raw.githubusercontent.com/Nahida-aa/picgo/main/images/20240605035357.png)

EEPROM=效率比RAM低，但是不易丢失数据

#### RegA、RegB

临时通用寄存器

![20240606195837](https://raw.githubusercontent.com/Nahida-aa/picgo/main/images/20240606195837.png)

申请一块内存，如果不赋值就会是一个随机的值

#### MBR

内存缓冲寄存器(Memory Buffer Register)(一级缓存、二级缓存、三级缓存)

真实计算机中可能有几M个MBR

是计算机系统中的一种重要组件，它的主要功能是作为CPU与内存之间数据传输的桥梁。以下是内存缓冲寄存器的工作原理和重要性的介绍：

1. **数据缓存**：内存缓冲寄存器可以暂时存储从内存或CPU传来的数据，减少CPU直接访问慢速内存的次数，从而提高数据处理速度。
2. **匹配速度**：由于CPU的处理速度远高于内存的访问速度，内存缓冲寄存器的存在可以缓解这一速度差异，提高整体系统效率。
3. **数据预取**：内存缓冲寄存器可以实现数据的预取功能，根据程序访问模式提前加载数据，减少等待时间。
4. **地址转换**：内存缓冲寄存器在处理虚拟内存时，帮助进行地址映射和转换，将虚拟地址转换为物理地址，使内存管理更为高效。
5. **控制信号**：内存缓冲寄存器还负责协调控制信号，确保数据在CPU与内存间的同步传输。
6. **降低功耗**：通过减少CPU对内存的直接访问，内存缓冲寄存器还可以在一定程度上降低系统的功耗。
7. **提高可靠性**：内存缓冲寄存器可以提高数据传输的可靠性，防止数据丢失或错误。
8. **系统性能**：内存缓冲寄存器的效率直接影响到整个计算机系统的性能，是评价系统性能的关键指标之一。

总的来说，内存缓冲寄存器在计算机系统中扮演着至关重要的角色，它不仅提高了数据处理速度，还增强了系统的稳定性和可靠性。通过优化内存缓冲寄存器的设计和实现，可以进一步提升计算机系统的整体性能。

#### Instruction_Register(IR)

例如, 定义:

```assembly
0000
LOAD_A
将内存地址[]的值load to RegA

0001
LOAD_B
将内存地址[]的值load to RegB

0010
ADD
RegA + RegB to OutReg

0011
STORE
```

#### MAR

内存地址寄存器(Memory Address Register)

![20240606221141](https://raw.githubusercontent.com/Nahida-aa/picgo/main/images/20240606221141.png)

#### Program_Counter(PC)

让程序按顺序依次执行

![20240606233018](https://raw.githubusercontent.com/Nahida-aa/picgo/main/images/20240606233018.png)

Fetch -> Decode -> Execute -> Fetch -> ...

Fetch Cycles(T):

```c
1. 把PC(程序计数器)的值放入到MAR(内存地址寄存器)
2. PC+1, 指向下一条指令
3. 从内存中读取MAR中地址对应的指令(操作码和操作数)到MBR(内存缓冲寄存器)
4. 把MBR中的指令放入到IR(指令寄存器)
```

Execute Cycles(T) (Decode + Execute):

```c
1. 从IR中取出操作码
2. 根据操作码执行相应的操作
```

```c
// 变量 a 和 b 都是在栈上分配的局部变量。当 main 函数返回时，这些局部变量会自动被销毁，它们占用的内存会被释放
// 需要注意的是，这只适用于在栈上分配的局部变量。如果你在堆上动态分配内存（例如，使用 malloc 或 calloc 函数），那么你需要手动释放这些内存（使用 free 函数），否则会导致内存泄漏
int main(void) {
    int a = 3;
    int b = 5;
    b = a + b;
    return 0;
}
```

## CU

时序手册, 时序图
```c
0 PC_OE
1 PC_WE
2 MAR_WE
3 MAR_OE
4 IR_WE
5 IR_OE
6 MBR_WE
7 MBR_OE
8 RegA_WE
9 RegA_OE
10 RegB_WE
11 RegB_OE
12 OutReg_WE
13 OutReg_OE
14 Men_WE
15 Men_OE
```

Fetch Cycles(T) (全部相同)(Oper, Addr):

```c
0. 把PC(程序计数器)的值放入到MAR(内存地址寄存器)
清除全部状态，打开PC的OE, 打开MAR的WE
0b0000000000000101
1. PC+1, 指向下一条指令
清除全部状态，打开PC的WE(En)
0b0000000000000010
2. 从内存中读取MAR中地址对应的指令(操作码和操作数)到MBR(内存缓冲寄存器)
清除全部状态，打开MAR的OE, 打开Men的OE, 打开MBR的WE
0b1000000001001000
3. 把MBR中的指令放入到IR(指令寄存器)
清除全部状态，打开MBR的OE, 打开IR的WE
0b0000000010010000
```

Execute Cycles(T) (Decode + Execute):

```c
LOAD_A [addr]
0. 把IR中的操作数(addr)放入到MAR
清除全部状态，打开IR的OE, 打开MAR的WE
0b0000000000100100
1. 从内存中读取MAR中地址对应的值到MBR
清除全部状态，打开MAR的OE, 打开Men的OE, 打开MBR的WE
0b1000000001001000
2. 把MBR中的值放入到RegA
清除全部状态，打开MBR的OE, 打开RegA的WE
0b0000000110000000
```

```c
LOAD_B [addr]
0. 把IR中的操作数(addr)放入到MAR
清除全部状态，打开IR的OE, 打开MAR的WE
0b0000000000100100
1. 从内存中读取MAR中地址对应的值到MBR
清除全部状态，打开MAR的OE, 打开Men的OE, 打开MBR的WE
0b1000000001001000
2. 把MBR中的值放入到RegB
清除全部状态，打开MBR的OE, 打开RegB的WE
0b0000010010000000
```

```c
Add
0. 把RegA和RegB的值 to OutReg
清除全部状态，打开RegA的OE, 打开RegB的OE, 打开OutReg的WE
0b0001101000000000
```

```c
STORE [addr]
0. 把IR中的操作数(addr)放入到MAR
清除全部状态, 打开IR的OE, 打开MAR的WE
0b0000000000100100
1. 把OutReg的值放入到MBR
清除全部状态, 打开OutReg的OE, 打开MBR的WE
0b0010000001000000
2. 把MBR的值放入到Men的对应地址中(MAR中的地址)
清除全部状态, 打开MBR的OE, 打开MAR的OE, 打开Men的WE
0b0100000010001000
```

那么:

```c
Fetch
0b0000000000000101
0b0000000000000010
0b1000000001001000
0b0000000010010000
LOAD_A [addr]
0b0000000000100100
0b1000000001001000
0b0000000110000000
Fetch
0b0000000000000101
0b0000000000000010
0b1000000001001000
0b0000000010010000
LOAD_B [addr]
0b0000000000100100
0b1000000001001000
0b0000010010000000
Fetch
0b0000000000000101
0b0000000000000010
0b1000000001001000
0b0000000010010000
Add
0b0001101000000000
Fetch
0b0000000000000101
0b0000000000000010
0b1000000001001000
0b0000000010010000
STORE [addr]
0b0000000000100100
0b0010000001000000
0b0100000010001000
```

```c
LOAD_A [addr]
0b0000000000000101
0b0000000000000010
0b1000000001001000
0b0000000010010000
0b0000000000100100
0b1000000001001000
0b0000000110000000
0b0000000000000000

LOAD_B [addr]
0b0000000000000101
0b0000000000000010
0b1000000001001000
0b0000000010010000
0b0000000000100100
0b1000000001001000
0b0000010010000000
0b0000000000000000

Add
0b0000000000000101
0b0000000000000010
0b1000000001001000
0b0000000010010000
0b0001101000000000
0b0000000000000000
0b0000000000000000
0b0000000000000000

STORE [addr]
0b0000000000000101
0b0000000000000010
0b1000000001001000
0b0000000010010000
0b0000000000100100
0b0010000001000000
0b0100000010001000
0b0000000000000000
```

### LUT

**Look-Up Table(查找表), 可用于数据的快速查找和转换**。LUT的功能和实现方式可以依据其应用场景的不同而有所差异，但核心思想是通过预先计算并存储数据的方式，来加速数据处理过程，提高系统效率。以下是LUT的几个主要应用方面：

1. **FPGA中的LUT应用**：在FPGA（现场可编程门阵列）中，LUT用于实现逻辑功能，代替传统的逻辑门电路。通过将输入信号的组合映射到对应的输出结果上，LUT能够实现复杂的逻辑运算，同时保持较快的处理速度和较低的延迟。
2. **色彩校正与视频处理**：在图像处理和视频制作领域，LUT被用来进行色彩校正和风格化处理。通过定义一组特定的色彩转换规则，LUT可以将原始图像或视频的色彩转换为目标色彩空间，或者应用某种视觉风格，如模仿特定电影的色调。
3. **数据转换优化**：在数据处理和网络通信等领域，LUT用于优化数据包的路由选择，通过查找表快速决定数据包的下一步转发路径，提高数据传输的效率和响应速度。
4. **缓存与存储器设计**：在硬件设计中，LUT的概念也被应用于缓存和存储器的设计，尤其是在FPGA设计中。通过使用LUT，设计师可以在硬件层面实现灵活的逻辑控制和数据处理，提高系统的灵活性和性能。

此外，了解LUT的工作原理和应用场景不仅有助于人们更好地利用这项技术进行日常的数据处理和设计工作，还可以帮助人们在未来的技术选型和优化中做出更明智的决策。例如，在选择FPGA或其他可编程硬件时，了解其内部LUT的配置和性能可以为人们提供重要的参考信息。同样，在图像和视频处理领域，掌握如何正确应用LUT进行色彩校正和创意表达，可以帮助人们提升作品的质量和视觉效果。

## BUS

bus wire logic 上分为data bus, ddress bus, control bus

## Clock_pulse

超频: 修改时钟速度，加快CPU的速度，会导致电脑发热或产生乱码

降频: 常用于在关闭屏幕时，省电，对笔记本、手机等移动设备很重要
