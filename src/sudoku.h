#ifndef SUDOKU_H
#define SUDOKU_H

#define SIZE 9
#define FAILURE 1
#define SUCCESS 0

int isValid(int board[SIZE][SIZE], int row, int col, int num);
int isBoardValid(int board[SIZE][SIZE]);
int findEmptyCell(int board[SIZE][SIZE], int *row, int *col);
int solve(int board[SIZE][SIZE]);
void printBoard(int board[SIZE][SIZE]);

#endif
