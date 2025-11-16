#include "sudoku.h"
#include <stdio.h>

int assertTrue(int condition, const char *msg) {
    if (condition) {
        printf("[PASS] %s\n", msg);
        return 0;
    } else {
        printf("[FAIL] %s\n", msg);
        return 1;
    }
}

int run() {
    int board[SIZE][SIZE] = {0};

    if (assertTrue(isValid(board, 0, 0, 5) == 1, "Empty board accepts new value")) return 1;

    board[0][0] = 5;

    if (assertTrue(isValid(board, 0, 1, 5) == 0, "Row conflict detected")) return 1;
    if (assertTrue(isValid(board, 1, 0, 5) == 0, "Column conflict detected")) return 1;
    if (assertTrue(isValid(board, 1, 1, 5) == 0, "Subgrid conflict detected")) return 1;
    if (assertTrue(isValid(board, 4, 4, 5) == 1, "Safe placement allowed")) return 1;

    return 0;
}

int main(void) {
    printf("Running tests...\n");
    if (run()) {
        printf("test failed.\n");
    } else {
        printf("test succeeded.\n");
    }

    return 0;
}
