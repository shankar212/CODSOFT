#include <iostream>
using namespace std;

// Function for making board
void displayBoard(char board[3][3]) {
    cout << "Custom Tic-Tac-Toe Board:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) {
                cout << " | ";
            }
        }
        cout << endl;
        if (i < 2) {
            cout << "-----------" << endl;
        }
    }
    cout << endl;
}

// Function to checking if a player has won
bool checkWin(char board[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true; // Check rows
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true; // Check columns
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true; // Check diagonal (top left to bottom right)
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true; // Check diagonal (top right to bottom left)
    }
    return false;
}

bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false; 
            }
        }
    }
    return true; 
}

int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}}; //empty board
    char currentPlayer = 'X'; 
    bool gameover = false;

    cout << "Welcome to Custom Tic-Tac-Toe!" << endl;

    while (!gameover) {
        displayBoard(board);

        int row, col;
        cout << "Player " << currentPlayer << ", enter row (1-3) and column (1-3) separated by a space: ";
        cin >> row >> col;
        row--; // Converting 0based index
        col--;

        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;

            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                cout << "Player " << currentPlayer << " is the Tic-Tac-Toe champion...." << endl;
                gameover = true;
            } else if (checkDraw(board)) {
                displayBoard(board);
                cout << "It's a friendly draw!" << endl;
                gameover = true;
            } else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; // Switch players
            }
        } else {
            cout << "Invalid move. Please try again." << endl;
        }
    }

    cout << "Thanks for playing Custom Tic-Tac-Toe!" << endl;

    return 0;
}
