#include <iostream>
#include <vector>
using namespace std;

const int N = 6; // Change this value for different board sizes

// Function to print the board
void printBoard(const vector<vector<int>>& board) {
    for (const auto& row : board) {
        for (int cell : row) {
            cout << (cell ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << "-------------------" << endl;
}

// Check if it's safe to place a queen at board[row][col]
bool isSafe(const vector<vector<int>>& board, int row, int col) {
    // Check column
    for (int i = 0; i < row; i++)
        if (board[i][col]) return false;

    // Check upper-left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return false;

    // Check upper-right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++)
        if (board[i][j]) return false;

    return true;
}

// Backtracking function
bool solveNQueens(vector<vector<int>>& board, int row) {
    if (row == N) {
        printBoard(board);  // print each solution
        return true;        // return true if you want only one solution
    }

    bool res = false;
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;
            res = solveNQueens(board, row + 1) || res;
            board[row][col] = 0; // backtrack
        }
    }
    return res;
}

int main() {
    vector<vector<int>> board(N, vector<int>(N, 0));
    if (!solveNQueens(board, 0)) {
        cout << "No solution exists for N = " << N << endl;
    }
    return 0;
}
