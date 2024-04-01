# x86-to-C Interface Programming Project
The purpose of this project is to analyze the execution time difference between a function called from x86-64 assembly to C (**Kernel A**) and a function purely implemented in C (**Kernel C**).

---

## I. Average Execution Time Per Vector Sizes in each Kernel (30 Runs)
### Debug Mode
| Vector Size | Kernel A | Kernel C |
| --- | --- | --- |
| 2^20 | 0.933 ms |  2.467 ms |
| 2^24 | 18.000 ms |  41.533 ms |
| 2^28 | 270.200 ms |  655.167 ms |

### Release Mode
| Vector Size | Kernel A | Kernel C |
| --- | --- | --- |
| 2^20 |  ms |  ms |
| 2^24 |  ms |   ms |
| 2^28 |  ms |   ms |

**Note:**
- Kernel A => x86-64 assembly language
- Kernel C => C programming language

### Analysis
After analysing the comparison between the execution times of Kernel A and C across different vector sizes, it was observed that the ***Kernel A***, the function written in assembly language, ***runs twice as fast*** as **Kernel C**, which was a function implemented purely in C.

---

## II. Comparison of Outputs between Kernel A and C
### Debug Mode

### Release Mode
