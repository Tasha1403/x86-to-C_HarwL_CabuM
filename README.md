# x86-to-C Interface Programming Project
The purpose of this project is to analyze the difference in execution time between a function called from x86-64 assembly to C (**Kernel A**) and a function purely implemented in C (**Kernel C**).

---

## I. Average Execution Time Per Vector Size in each Kernel (30 Runs)
### _Debug Mode_

![debug](https://github.com/Tasha1403/x86-to-C_HarwL_CabuM/assets/115960087/054db7d4-8a5f-431c-b291-4cf20e205c38)
| Vector Size | Kernel A | Kernel C |
| --- | --- | --- |
| 2^20 | 1.000 ms |  2.333 ms |
| 2^24 | 16.500 ms |  36.900 ms |
| 2^28 | 263.933 ms |  612.000 ms |

### _Release Mode_

![release](https://github.com/Tasha1403/x86-to-C_HarwL_CabuM/assets/115960087/32cddd8f-8daf-4cb4-8e05-2ca3c61e447e)
| Vector Size | Kernel A | Kernel C |
| --- | --- | --- |
| 2^20 | 0.933 ms | 0.667 ms |
| 2^24 | 16.233 ms | 13.433 ms |
| 2^28 | 258.600  ms | 235.933 ms |

**Note:**
- Kernel A => x86-64 assembly language
- Kernel C => C programming language

### _Analysis_
After analyzing the comparison between the execution times of Kernel A and C across different vector sizes, it was observed that ***Kernel A***, the function written in assembly language, ***runs twice as fast*** as **Kernel C**, which was a function implemented purely in C. However, this only applies to ***Debug Mode***. 

In contrast, under the ***Release Mode***, it seems that ***Kernel C runs slightly faster*** than **Kernel A** because the compiler implements optimization techniques to the code in order to produce optimized machine code. However, within **Debug Mode**, there is no optimization applied to the C code to facilitate easier debugging, resulting in Kernel A executing faster than Kernel C.

---

## II. Correctness Checking
### _Debug Mode_
![debug1](https://github.com/Tasha1403/x86-to-C_HarwL_CabuM/assets/115960087/053bdae7-25eb-46ba-bf87-8e4a8408b37f)

### _Release Mode_
![release1](https://github.com/Tasha1403/x86-to-C_HarwL_CabuM/assets/115960087/ee2e673c-c783-4d49-a4f8-460cdb7894d7)

**Note:**
- The display of values within X, Y, and Z are limited to the first 10 elements for readability's sake.

---
## How to run the code
**Requirements**
- You must have Visual Studio 2020 and NASM

**How to Run in Visual Studio 2020**
- Download the whole repository as zip file and extract it to your desired folder.
- Open Visual Studio then select ***Open project or solution***.
- Navigate to the ***CabuM_HarwL_x86-to-C*** directory and select the "**CabuM_HarwL_x86-to-C.sln**" file.
- Finally, you may run the code either in debug or release mode.

---
## Important Notes
- This code was run with *Intel(R) Core(TM) i5-10300H CPU @ 2.50GHz* processor with *24GB of RAM*. In case you want to run the code, you might want to decrease the value of *"n3"* depending on how much your machine could handle.
---
