#include "sudoku.h"
#include <stdio.h>

int main(void) {
    int board[SIZE][SIZE];
    int emptyCells = 40;

    generatePuzzle(board, emptyCells);

    printf("Generated puzzle:\n");
    printBoard(board);

    if (solve(board) == SUCCESS) {
        printf("\nSolved puzzle:\n");
        printBoard(board);
    } else {
        printf("No solution found.\n");
    }

    return SUCCESS;
}
