Compilation and Execution Instructions


To build and run the program:

1. Run the Makefile in the root directory. This will compile the code and generate the common_wrapper.exe executable.

2. Important: The input file paths are currently defined in the source code. Before running the executable, you must specify the target input text file:

    For Simple GEMM: Update the file path on line 8 of \assignment1\src\gemm_simple.cpp.

    For Blocking GEMM: Update the file path on line 12 of \assignment1\src\gemm_blocking.cpp.

3. If you changed the file paths, re-run the Makefile to compile the changes.

4. Execute ./common_wrapper.exe.

RESULTS

# Assignment 1

The following table compares the execution time of the simple matrix multiplication implementation with the blocking implementation for different matrix sizes and block sizes.

| Test File | Matrix Size | Expected Output | Actual Output | Simple Time (ms) | Blocking Time (ms) | Block Size | Status |
|-----------|-------------|-----------------|---------------|-----------------:|-------------------:|-----------:|:------:|
| `gemm_64.txt` | 64 × 64 × 64 × 64 | Result matrix | Result matrix | 0.779 | 0.803 | 4 | Pass |
| `gemm_64.txt` | 64 × 64 × 64 × 64 | Result matrix | Result matrix | 6.291 | 2.223 | 4 | Pass |
| `gemm_256.txt` | 256 × 256 × 256 × 256 | Result matrix | Result matrix | 42.741 | 38.606 | 4 | Pass |
| `gemm_512.txt` | 512 × 512 × 512 × 512 | Result matrix | Result matrix | 278.427 | 209.294 | 4 | Pass |
| `gemm_1024.txt` | 1024 × 1024 × 1024 × 1024 | Result matrix | Result matrix | 1570.087 | 1487.257 | 4 | Pass |
| `gemm_64.txt` | 64 × 64 × 64 × 64 | Result matrix | Result matrix | 6.356 | 1.942 | 16 | Pass |
| `gemm_256.txt` | 256 × 256 × 256 × 256 | Result matrix | Result matrix | 36.822 | 34.202 | 32 | Pass |
| `gemm_512.txt` | 512 × 512 × 512 × 512 | Result matrix | Result matrix | 269.721 | 359.062 | 64 | Pass |
| `gemm_1024.txt` | 1024 × 1024 × 1024 × 1024 | Result matrix | Result matrix | 1506.841 | 1064.335 | 64 | Pass |

# Assignment 2

| Algorithm | Test File | Vertices | Edges | Source | Negative Cycle | Expected Output | Actual Output | Time | Status |
|---|---|---:|---:|---:|---|---|---|---:|---|
| Bellman-Ford | `bf_10.txt` | 5 | 10 | 0 | No | Distances | Distances: `0, 2, 4, 7, -2`<br>Negative cycle: none | `1 × 10⁻³ ms` | Pass |
| Bellman-Ford | `bf_100.txt` | 100 | 1,923 | 3 | No | Distances | — | `31 × 10⁻³ ms` | Pass |
| Bellman-Ford | `bf_10000.txt` | 10,000 | 20,000 | 808 | Yes | Distances | — | `2361.317 ms` | Pass |
| Bellman-Ford | `bf_50000.txt` | 50,000 | 250,000 | 0 | Yes | Distances | — | `109164.991 ms` | Pass |
| Bellman-Ford | `bf_100000.txt` | 100,000 | 500,000 | 0 | Yes | Distances | — | `610757.283 ms` | Pass |
| Floyd-Warshall | `fw_5.txt` | 5 | N/A | N/A | No | Distance matrix | Distance matrix computed<br>Negative cycle: none | `1 × 10⁻³ ms` | Pass |
| Floyd-Warshall | `fw_5.txt` | 5 | N/A | N/A | Yes | Distance matrix | — | `2 × 10⁻³ ms` | Pass |
| Floyd-Warshall | `fw_500.txt` | 500 | N/A | N/A | No | Distance matrix | — | `124.664 ms` | Pass |
| Floyd-Warshall | `fw_1000.txt` | 1,000 | N/A | N/A | No | Distance matrix | — | `927.971 ms` | Pass |
| Floyd-Warshall | `fw_2000.txt` | 2,000 | N/A | N/A | Yes | Distance matrix | — | `6750.685 ms` | Pass |