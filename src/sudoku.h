#ifndef SUDOKU_H
#define SUDOKU_H

#define SIZE 9
#define FAILURE 1
#define SUCCESS 0

int isValid(int board[SIZE][SIZE], int row, int col, int num);
int isBoardValid(int board[SIZE][SIZE]);
int findEmptyCell(int board[SIZE][SIZE], int *row, int *col);
void removeCells(int board[SIZE][SIZE], int emptyCells);
int solve(int board[SIZE][SIZE]);
int generateFullSolution(int board[SIZE][SIZE]);
void generatePuzzle(int board[SIZE][SIZE], int emptyCells);
void printBoard(int board[SIZE][SIZE]);

#endif
