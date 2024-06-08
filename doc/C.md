# C

Hardware -> Driver -> Operating_System -> Application

Driver 常由 C 编写。C 提供了对硬件的低级访问，同时也提供了足够的高级抽象，使得代码可以在不同的硬件和操作系统上运行。

Driver 也可能用 Assembly 编写，特别是在需要直接访问特定硬件或 CPU 指令的情况下。

一些现代OS也开始支持使用更高级的语言编写驱动程序，例如 Windows 支持使用 C++ 编写Driver，而 Rust 语言也正在被用于实验性的Driver开发。

驱Driver是一种特殊的计算机程序，它允许OS和Hardware进行交互。它的主要任务是作为Hardware(如打印机、显卡、网络适配器等)和OS之间的“翻译者”。

当App需要访问Hardware时，会通过OS提供的接口发出请求。然后, Driver会将这些请求转换为硬件设备能理解的指令，从而控制硬件设备的行为。

当hardware有数据需要传递给app时，驱动程序也会将硬件设备的信号转换为操作系统和应用程序能理解的数据。

因此，驱动程序是硬件设备和操作系统之间的重要桥梁，它使得各种不同的硬件设备可以在同一操作系统下工作。

操作系统通常使用多种编程语言进行开发，但最主要的是 C 语言和汇编语言。

1. C language：C 语言是操作系统开发中最常用的语言。它是一种高级语言，但同时提供了许多低级功能，如直接访问内存，这对于操作系统开发来说非常重要。大多数现代操作系统，包括 Linux 和 Windows，都有大部分代码是用 C 语言编写的。

2. Assembly : 汇编语言是一种低级语言，它直接对应于机器代码。在操作系统开发中，汇编语言通常用于编写启动代码（boot code）、中断处理程序和其他需要直接操作硬件或特定 CPU 指令的部分。

此外，一些现代操作系统也开始使用更高级的语言进行某些部分的开发，例如 C++、Rust 或 Python，但这些语言通常用于操作系统的高级功能，而不是核心部分。

## environment

1. GCC（GNU 编译器集合）：这是最常用的 C 语言编译器之一，它是开源的，可以在几乎所有的平台上运行，包括 Linux、Mac OS 和 Windows。

2. Clang：这是 LLVM 项目的一部分，它是一个开源的编译器，支持 C、C++ 和 Objective-C。Clang 以其出色的诊断信息（错误和警告消息）而闻名。

3. MSVC（Microsoft Visual C++）：这是 Microsoft 提供的编译器，它是 Visual Studio 的一部分，主要用于 Windows 平台。

4. MinGW（Minimalist GNU for Windows）：这是一个将 GCC 编译器和 GNU 工具链移植到 Windows 平台的项目。

5. Intel C++ Compiler：这是 Intel 提供的编译器，它为 Intel 的处理器提供了优化。

6. TinyCC：这是一个小型的 C 语言编译器，它的目标是生成尽可能小的可执行文件。

7. C51 是 Keil 公司为 8051 微控制器提供的一个 C 语言编译器。8051 微控制器是一种常见的 8 位微控制器，广泛应用于嵌入式系统和微型计算机系统。

    C51 编译器可以将 C 语言代码编译成 8051 微控制器可以执行的机器代码。它包含了一些特殊的关键字和功能，以支持 8051 微控制器的特性，例如中断处理、位操作等。

    Keil 公司还提供了一个集成开发环境（IDE），叫做 Keil μVision，它包含了 C51 编译器、宏汇编器、链接器、调试器等工具，可以方便地进行 8051 微控制器的开发和调试。

### gcc

#### MinGW

```sh
gcc main.c -o main && main
```

### vscode

c_cpp_properties.json

编译器路径和智能感知设置(compiler path and IntelliSense settings)

```json
{
    "configurations": [
        {
            "name": "Win32",
            "includePath": [
                "${workspaceFolder}/**",
                "D:/msys64/ucrt64/include"
            ],
            "defines": [
                "_DEBUG",
                "UNICODE",
                "_UNICODE"
            ],
            // "windowsSdkVersion": "10.0.17763.0",
            "compilerPath": "D:\\msys64\\ucrt64\\bin\\gcc",
            "cStandard": "c11",
            // -std=c11
            "cppStandard": "c++17",
            // -std=c++17
            "intelliSenseMode": "gcc-x64"
        }
    ],
    "version": 4
}
```

tasks.json (build instructions)  tasks.json （构建说明）
launch.json (debugger settings)  launch.json （调试器设置）

## variable, constant, data type

| K&R | C90 | C99 |
| --- | --- | --- |
| int | signed | _Bool |
| long | void | _Complex |
| short |   | _Imaginary |
| unsigned |   |   |
| char |   |   |
| float |   |   |
| double |   |   |

| Type | Description | Size | Range |
| --- | --- | --- | --- |
| int | Integer | 4 Bytes | -2,147,483,648 to 2,147,483,647 |
| long | Long integer | 4 Bytes | -2,147,483,648 to 2,147,483,647 |
| short | Short integer | 2 Bytes | -32,768 to 32,767 |
| unsigned | 0 to 255 | 1 Byte | 0 to 255 |
| signed | -128 to 127 | 1 Byte | -128 to 127 |
| char | Character or small integer | 1 Byte | -128 to 127 or 0 to 255 |
| float | Single-precision floating point | 4 Bytes | 1.2E-38 to 3.4E+38 |
| double | Double-precision floating point | 8 Bytes | 2.3E-308 to 1.7E+308 |
| long double | Extended-precision floating point | 10 Bytes | 3.4E-4932 to 1.1E+4932 |
| _Bool | Boolean | 1 Byte | 0 to 1 |
| void | No value | 0 Bytes | N/A |
| _Complex | Complex number | 8 Bytes | N/A |
| _Imaginary | Imaginary number | 4 Bytes | N/A |
