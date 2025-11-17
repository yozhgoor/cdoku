#include "sudoku.h"
#include <stdio.h>

int isValid(int board[SIZE][SIZE], int row, int col, int num) {
    for (int x = 0; x < SIZE; x++) {
        if (board[row][x] == num) {
            return FAILURE;
        }
    }

    for (int y = 0; y < SIZE; y++) {
        if (board[y][col] == num) {
            return FAILURE;
        }
    }

    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;

    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            if (board[startRow + y][startCol + x] == num) {
                return FAILURE;
            }
        }
    }

    return SUCCESS;
}

int isBoardValid(int board[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            int num = board[row][col];
            if (num != 0) {
                board[row][col] = 0;
                if (isValid(board, row, col, num) == FAILURE) {
                    board[row][col] = num;
                    return FAILURE;
                }
                board[row][col] = num;
            }
        }
    }
    return SUCCESS;
}

int findEmptyCell(int board[SIZE][SIZE], int *row, int *col) {
    for (int r = 0; r < SIZE; r++) {
        for (int c = 0; c < SIZE; c++) {
            if (board[r][c] == 0) {
                *row = r;
                *col = c;
                return SUCCESS;
            }
        }
    }
    return FAILURE;
}

int solve(int board[SIZE][SIZE]) {
    int row, col;

    if (isBoardValid(board) == FAILURE) {
        return FAILURE;
    }

    if (findEmptyCell(board, &row, &col) == FAILURE) {
        return SUCCESS;
    }

    for (int num = 1; num <= 9; num ++) {
        if (isValid(board, row, col, num) == SUCCESS) {
            board[row][col] = num;

            if (solve(board) == SUCCESS) {
                return SUCCESS;
            }

            board[row][col] = 0;
        }
    }

    return FAILURE;
}

void printBoard(int board[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        if (row % 3 == 0 && row != 0) {
            printf("---------------------\n");
        }
        for (int col = 0; col < SIZE; col++) {
            if (col % 3 == 0 && col != 0) {
                printf("| ");
            }
            printf("%d ", board[row][col]);
        }
        printf("\n");
    }
}
