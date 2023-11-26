#include <stdio.h>
#include "lib/matrixlib.h"

// Функция для сортировки массива
void sortArray(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (*(arr + i) > *(arr + j)) {
                int temp = *(arr + i);
                *(arr + i) = *(arr + j);
                *(arr + j) = temp;
            }
        }
    }
}

// Функция для проверки, является ли массив перестановкой чисел от 1 до n
int isPermutation(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        if (*(arr + i) != i + 1) {
            return 0;
        }
    }
    return 1;
}

// Функция для проверки свойства латинского квадрата
int isLatinSquare(int **matrix, int n) {
    for (int i = 0; i < n; i++) {
        // Проверка строки
        int sortedRow[n];
        for (int j = 0; j < n; j++) {
            sortedRow[j] = matrix[i][j];
        }
        sortArray(sortedRow, n);
        if (!isPermutation(sortedRow, n)) {
            return 0;
        }

        // Проверка столбца
        int sortedColumn[n];
        for (int j = 0; j < n; j++) {
            sortedColumn[j] = matrix[j][i];
        }
        sortArray(sortedColumn, n);
        if (!isPermutation(sortedColumn, n)) {
            return 0;
        }
    }

    return 1;
}

int main() {
    int n = 3;
    int **matrix = (int **)allocate_matrix(n, n, sizeof(int));

    input_int_matrix(matrix, n, n);

    // Проверка и вывод результата
    if (isLatinSquare(matrix, n)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    // Освобождение выделенной памяти
    deallocate_matrix((void **)matrix, n);

    return 0;
}
