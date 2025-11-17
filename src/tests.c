#include "sudoku.h"
#include <stdio.h>
#include <string.h>

int assertTest(int condition, const char *msg) {
    if (condition) {
        printf("[PASS] %s\n", msg);
        return SUCCESS;
    } else {
        printf("[FAIL] %s\n", msg);
        return FAILURE;
    }
}

int boardsEqual(int a[SIZE][SIZE], int b[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++)
        for (int col = 0; col < SIZE; col++)
            if (a[row][col] != b[row][col])
                return FAILURE;
    return SUCCESS;
}

int testIsValid() {
    int failures = 0;
    int board[SIZE][SIZE] = {0};

    failures += assertTest(isValid(board, 0, 0, 5) == SUCCESS, "Empty board accepts new value");

    board[0][0] = 5;

    failures += assertTest(isValid(board, 0, 1, 5) == FAILURE, "Row conflict detected");
    failures += assertTest(isValid(board, 1, 0, 5) == FAILURE, "Column conflict detected");
    failures += assertTest(isValid(board, 1, 1, 5) == FAILURE, "Subgrid conflict detected");
    failures += assertTest(isValid(board, 4, 4, 5) == SUCCESS, "Safe placement allowed");

    return failures;
}

int testSolveSuccess() {
    int puzzle[SIZE][SIZE] = {
        {5,3,0, 0,7,0, 0,0,0},
        {6,0,0, 1,9,5, 0,0,0},
        {0,9,8, 0,0,0, 0,6,0},

        {8,0,0, 0,6,0, 0,0,3},
        {4,0,0, 8,0,3, 0,0,1},
        {7,0,0, 0,2,0, 0,0,6},

        {0,6,0, 0,0,0, 2,8,0},
        {0,0,0, 4,1,9, 0,0,5},
        {0,0,0, 0,8,0, 0,7,9},
    };

    int expected[SIZE][SIZE] = {
        {5,3,4, 6,7,8, 9,1,2},
        {6,7,2, 1,9,5, 3,4,8},
        {1,9,8, 3,4,2, 5,6,7},

        {8,5,9, 7,6,1, 4,2,3},
        {4,2,6, 8,5,3, 7,9,1},
        {7,1,3, 9,2,4, 8,5,6},

        {9,6,1, 5,3,7, 2,8,4},
        {2,8,7, 4,1,9, 6,3,5},
        {3,4,5, 2,8,6, 1,7,9}
    };

    int failures = 0;

    failures += assertTest(solve(puzzle) == SUCCESS, "solving puzzle...");
    failures += assertTest(boardsEqual(puzzle, expected) == SUCCESS, "puzzle solved successfully.");

    return failures;
}

int testSolveFailure() {
    int puzzle[SIZE][SIZE] = {
        {1,1,0, 0,0,0, 0,0,0},
        {0,0,0, 0,0,0, 0,0,0},
        {0,0,0, 0,0,0, 0,0,0},

        {0,0,0, 0,0,0, 0,0,0},
        {0,0,0, 0,0,0, 0,0,0},
        {0,0,0, 0,0,0, 0,0,0},

        {0,0,0, 0,0,0, 0,0,0},
        {0,0,0, 0,0,0, 0,0,0},
        {0,0,0, 0,0,0, 0,0,0},
    };

    return assertTest(solve(puzzle) == FAILURE, "failed to solve puzzle successfully");
}

int testAlreadySolved() {
    int puzzle[SIZE][SIZE] = {
        {1,2,3, 4,5,6, 7,8,9},
        {4,5,6, 7,8,9, 1,2,3},
        {7,8,9, 1,2,3, 4,5,6},

        {2,3,4, 5,6,7, 8,9,1},
        {5,6,7, 8,9,1, 2,3,4},
        {8,9,1, 2,3,4, 5,6,7},

        {3,4,5, 6,7,8, 9,1,2},
        {6,7,8, 9,1,2, 3,4,5},
        {9,1,2, 3,4,5, 6,7,8},
    };

    int copy[SIZE][SIZE];
    memcpy(copy, puzzle, sizeof(puzzle));

    int failures = 0;

    failures += assertTest(solve(puzzle) == SUCCESS, "solving puzzle...");
    failures += assertTest(boardsEqual(puzzle, copy) == SUCCESS, "solved puzzle unchanged");

    return failures;
}

int main(void) {
    int failures = 0;

    printf("Running tests...\n");
    failures += testIsValid();
    failures += testSolveSuccess();
    failures += testSolveFailure();
    failures += testAlreadySolved();

    if (failures > 0) {
        printf("Tests failed! (%d failure(s))\n", failures);
        return FAILURE;
    }

    printf("test succeeded!\n");
    return SUCCESS;
}
