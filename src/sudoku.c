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

int solve(int board[SIZE][SIZE]) {
    int row = -1, col = -1;
    int foundEmpty = 0;

    for (int r = 0; r < SIZE; r++) {
        for (int c = 0; c < SIZE; c++) {
            if (board[r][c] == 0) {
                row = r;
                col = c;
                foundEmpty = 1;
                break;
            }
        }
        if (foundEmpty) break;
    }

    if (!foundEmpty) return 1;

    for (int num = 1; num <= SIZE; num++) {
        if (isValid(board, row, col, num)) {
            board[row][col] = num;

            if (solve(board)) {
                return 1;
            }

            board[row][col] = 0;
        }
    }

    return 0;
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
