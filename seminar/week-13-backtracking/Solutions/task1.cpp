#include <iostream>

const int MAX = 100;

void backtracking(int matrix[MAX][MAX], int r, int c, int N, int M) {
    if (r < 0 || r >= N || c < 0 || c >= M || matrix[r][c] == 0) {
        return;
    }

    matrix[r][c] = 0;

    backtracking(matrix, r - 1, c, N, M);
    backtracking(matrix, r + 1, c, N, M);
    backtracking(matrix, r, c - 1, N, M);
    backtracking(matrix, r, c + 1, N, M);
}

int countRegions(int matrix[MAX][MAX], int N, int M) {
    int regionsCount = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (matrix[i][j] == 1) {
                regionsCount++;
                backtracking(matrix, i, j, N, M);
            }
        }
    }

    return regionsCount;
}

int main() {
    // Задаваме конкретните размери на използваната част от масива
    int N = 4;
    int M = 5;

    // Създаваме статичен двумерен масив с фиксиран максимален капацитет MAX
    int matrix[MAX][MAX] = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 1},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0}
    };

    // Намираме броя на свързаните области чрез подаване на масива и реалните му размери
    int result = countRegions(matrix, N, M);

    // Отпечатваме намерения брой области на стандартния изход
    std::cout << "Броят на областите в масива е: " << result << std::endl;

    return 0;
}
