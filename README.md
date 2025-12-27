# Josephus-Algorithm-Complexity

This project provides an empirical and theoretical analysis of the **Josephus Problem**, comparing the performance of **Iterative** versus **Recursive** algorithmic approaches.

## Performance Visualization
The following graph illustrates the execution time of both algorithms as the input size ($n$) scales up to 45,000.

![Josephus Performance Graph](performance_chart.png)

## Key Findings

| Metric | Iterative Approach | Recursive Approach |
| :--- | :--- | :--- |
| **Time Complexity** | $O(n)$ | $O(n)$ |
| **Space Complexity** | $O(1)$ | $O(n)$ (Stack Depth) |
| **Performance** | Faster / Stable | Slower / Risk of Stack Overflow |

* **Empirical Observation:** The iterative method consistently outperforms the recursive method. 
* **Hardware Efficiency:** Fluctuations in the iterative line suggest hardware-level optimizations such as CPU cache efficiency or branch prediction accuracy.
* **Memory Constraints:** While both are linear in time, the recursive approach is limited by the system call stack, which can lead to crashes at very high values of $n$.

## Repository Structure
* `josephusProblem.cpp`: The C++ source code containing both implementations and the benchmarking logic.
* `performance_chart.png`: The performance visualization chart.
* `results_Data.xlsx`: The Excel spreadsheet containing raw logs and calculation averages.

## Installation and Execution

```bash
# 1. Compile the source code
g++ josephusProblem.cpp -o josephus_bench

# 2. Run the program
./josephus_bench

# Note on Data Collection:
# The program outputs CSV-formatted data directly to the terminal. 
# The results provided in this repository were averaged over 1,000 
# trials per data point to ensure statistical accuracy.
