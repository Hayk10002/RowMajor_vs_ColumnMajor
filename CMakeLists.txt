cmake_minimum_required(VERSION 3.10)

project(RowMajor_vs_ColumnMajor)

set(CMAKE_CXX_STANDARD 23)
set(LLVM_CXX_STD c++23)
add_executable(main main.cpp)


# Add the main executable as a test
enable_testing()
add_test(NAME MainTest1 COMMAND main 1000 1000)
add_test(NAME MainTest2 COMMAND main 2000 500)
add_test(NAME MainTest3 COMMAND main 3000 100)