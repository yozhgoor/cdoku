#include "sudoku.h"
#include <stdio.h>

#define SIZE 9

void printBoard(int board[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        if (row % 3 == 0 && row != 0)
            printf("---------------------\n");

        for (int col = 0; col < SIZE; col++) {
            if (col % 3 == 0 && col != 0)
                printf("| ");

            printf("%d ", board[row][col]);
        }
        printf("\n");
    }
}

int main(void) {
    int board[SIZE][SIZE] = {0};

    printBoard(board);

    return 0;
}
