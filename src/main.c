#include "sudoku.h"
#include <stdio.h>

#define SIZE 9

int main(void) {
    int board[SIZE][SIZE] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {0, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 0, 0},

        {8, 0, 0, 0, 0, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},

        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9},
    };

    printf("Initial puzzle:\n");
    printBoard(board);

    if (solve(board)) {
        printf("\nSolved puzzle:\n");
        printBoard(board);
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}
