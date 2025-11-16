#include "sudoku.h"
#include <stdio.h>

int isValid(int board[SIZE][SIZE], int row, int col, int num) {
    for (int x = 0; x < SIZE; x++)
        if (board[row][x] == num) return 0;

    for (int y = 0; y < SIZE; y++)
        if (board[y][col] == num) return 0;

    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;

    for (int y = 0; y < 3; y++)
        for (int x = 0; x < 3; x++)
            if (board[startRow + y][startCol + x] == num)
                return 0;

    return 1;
}

void printBoard(int board[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        if (row % 3 == 0 && row != 0) printf("---------------------\n");
        for (int col = 0; col < SIZE; col++) {
            if (col % 3 == 0 && col != 0) printf("| ");
            printf("%d ", board[row][col]);
        }
        printf("\n");
    }
}
