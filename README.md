# RowMajor_vs_ColumnMajor

## Table of Contents
- [Introduction](#introduction)
- [Build and Run](#build-and-run)
- [Possible Output](#possible-output)
- [How does this work](#how-does-this-work)

## Introduction
The purpose of this project is to compare the performance of row-major and column-major memory access patterns.

## Build and Run
To clone and run this project, you'll need [Git](https://git-scm.com) and [CMake](https://cmake.org/) installed on your computer. From your command line:

```bash
# Clone this repository
$ git clone https://github.com/Hayk10002/RowMajor_vs_ColumnMajor

# Go into the repository
$ cd RowMajor_vs_ColumnMajor

# Generate the build files
$ cmake -DCMAKE_BUILD_TYPE=Release -S . -B build

# Build the project
$ cmake --build build --config Release

# Then, run the executable generated in the `build` directory with the number of iterations to run the test.
$ your/path/to/exe/main.exe {The size of the matrix} {The number of iterations to run the test}
# example - .../main.exe 1000 1000
```

## Possible Output
(for matrix size 1000x1000)

```
Row-major:     279us
Column-major:  483us
```

## How does this work
The project measures the performance difference between row-major and column-major memory access patterns by iterating over a large 2D array. 

In row-major order, the array is accessed row by row, which is cache-friendly. In column-major order, the array is accessed column by column, which can lead to cache misses.

The code creates a large 2D array and measures the time taken to access all elements in row-major and column-major order. The results show the time taken for each access pattern, providing insights into the performance impact of memory access patterns.
