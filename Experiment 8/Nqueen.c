#include <stdio.h>
#include <stdbool.h>
#define N 4
void printBoard(char board[N][N]) {
for (int i = 0; i < N; i++) {
for (int j = 0; j < N; j++)
printf("%c ", board[i][j]);
printf("\n");
}
printf("\n");
}
bool isSafe(char board[N][N], int row, int col) {int i, j;
for (i = 0; i < col; i++)
if (board[row][i] == 'Q')
return false;
for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
if (board[i][j] == 'Q')
return false;
for (i = row, j = col; j >= 0 && i < N; i++, j--)
if (board[i][j] == 'Q')
return false;
return true;
}
bool solveNQueens(char board[N][N], int col) {
if (col >= N) {
printBoard(board);
return true;
}
for (int i = 0; i < N; i++) {
if (isSafe(board, i, col)) {
board[i][col] = 'Q';
solveNQueens(board, col + 1);
board[i][col] = '.';
}
}
return false;
}
void solveQueens() {
char board[N][N];
for (int i = 0; i < N; i++) {for (int j = 0; j < N; j++) {
board[i][j] = '.';
}
}
solveNQueens(board, 0);
}
int main() {
printf("Vinit Shah C3-2 C183 60004220097\n");
printf("The solution for 4 Queen problem through backtracing is given as:\n");
solveQueens();
return 0;
}