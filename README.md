# x86-to-C Interface Programming Project
The purpose of this project is to analyze the execution time difference between a function called from x86-64 assembly to C (**Kernel A**) and a function purely implemented in C (**Kernel C**).

---

## I. Average Execution Time Per Vector Sizes in each Kernel (30 Runs)
### Debug Mode

![debug](https://github.com/Tasha1403/x86-to-C_HarwL_CabuM/assets/115960087/054db7d4-8a5f-431c-b291-4cf20e205c38)
| Vector Size | Kernel A | Kernel C |
| --- | --- | --- |
| 2^20 | 1.000 ms |  2.333 ms |
| 2^24 | 16.500 ms |  36.900 ms |
| 2^28 | 263.933 ms |  612.000 ms |

### Release Mode

![release](https://github.com/Tasha1403/x86-to-C_HarwL_CabuM/assets/115960087/32cddd8f-8daf-4cb4-8e05-2ca3c61e447e)
| Vector Size | Kernel A | Kernel C |
| --- | --- | --- |
| 2^20 | 0.933 ms | 0.667 ms |
| 2^24 | 16.233 ms | 13.433 ms |
| 2^28 | 258.600  ms | 235.933 ms |

**Note:**
- Kernel A => x86-64 assembly language
- Kernel C => C programming language

### Analysis
After analyzing the comparison between the execution times of Kernel A and C across different vector sizes, it was observed that ***Kernel A***, the function written in assembly language, ***runs twice as fast*** as **Kernel C**, which was a function implemented purely in C. However, this only applies to ***Debug Mode***. 

In contrast, under the ***Release Mode***, it seems that ***Kernel C runs slightly faster*** than **Kernel A** because the compiler implements optimization techniques to the code in order to produce optimized machine code. However, within **Debug Mode**, there is no optimization applied to the C code to facilitate easier debugging, resulting in Kernel A executing faster than Kernel C.

---

## II. Correctness Checking
### Debug Mode


### Release Mode

---

