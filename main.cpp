#include <iostream>
#include <vector>
#include <chrono>
#include <random>

int generateRandomNumber(int min, int max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(min, max);
    return dis(gen);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <matrix_size> <iteration_count>" << std::endl;
        return 1;
    }

    const int MATRIX_SIZE = std::stoi(argv[1]);
    const int ITERATION_COUNT = std::stoi(argv[2]);

    std::vector matrix(MATRIX_SIZE * MATRIX_SIZE, 0);

    for (int i = 0; i < MATRIX_SIZE; ++i) 
        for (int j = 0; j < MATRIX_SIZE; ++j) 
            matrix[i * MATRIX_SIZE + j] = generateRandomNumber(0, 100);
    auto start = std::chrono::high_resolution_clock::now();

    volatile int x;
    for (int k = 0; k < ITERATION_COUNT; ++k)
        for (int i = 0; i < MATRIX_SIZE; ++i)
            for (int j = 0; j < MATRIX_SIZE; ++j)
                x = matrix[i * MATRIX_SIZE + j];

    auto row_major_time = (std::chrono::high_resolution_clock::now() - start) / ITERATION_COUNT;

    start = std::chrono::high_resolution_clock::now();

    for (int k = 0; k < ITERATION_COUNT; ++k)
        for (int j = 0; j < MATRIX_SIZE; ++j)
            for (int i = 0; i < MATRIX_SIZE; ++i)
                x = matrix[i * MATRIX_SIZE + j];

    auto column_major_time = (std::chrono::high_resolution_clock::now() - start) / ITERATION_COUNT;

    std::cout << std::format(
        "Row-major:    {:>6}\n"
        "Column-major: {:>6}\n",
        std::chrono::duration_cast<std::chrono::microseconds>(row_major_time), 
        std::chrono::duration_cast<std::chrono::microseconds>(column_major_time)
    );
    return 0;
}