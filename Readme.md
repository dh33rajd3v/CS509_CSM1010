Compilation and Execution Instructions


To build and run the program:

1. Run the Makefile in the root directory. This will compile the code and generate the common_wrapper.exe executable.

2. Important: The input file paths are currently defined in the source code. Before running the executable, you must specify the target input text file:

    For Simple GEMM: Update the file path on line 8 of \assignment1\src\gemm_simple.cpp.

    For Blocking GEMM: Update the file path on line 12 of \assignment1\src\gemm_blocking.cpp.

3. If you changed the file paths, re-run the Makefile to compile the changes.

4. Execute ./common_wrapper.exe.