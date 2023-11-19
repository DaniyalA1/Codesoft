#include <iostream>
using namespace std;

// Function to display the Tic-Tac-Toe board
void displayBoard(char gameBoard[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << gameBoard[i][j];
            if (j == 0 || j == 1) cout << " | ";
        }
        cout << endl;
        if (i == 0 || i == 1) cout << "---------\n";
    }
    cout << endl;
}

// Function to check if a player has won
bool checkWin(char gameBoard[3][3], char currentPlayer) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (gameBoard[i][0] == currentPlayer && gameBoard[i][1] == currentPlayer && gameBoard[i][2] == currentPlayer) return true; // Rows
        if (gameBoard[0][i] == currentPlayer && gameBoard[1][i] == currentPlayer && gameBoard[2][i] == currentPlayer) return true; // Columns
    }
    // Check diagonals
    if (gameBoard[0][0] == currentPlayer && gameBoard[1][1] == currentPlayer && gameBoard[2][2] == currentPlayer) return true; // Diagonal from top-left to bottom-right
    if (gameBoard[0][2] == currentPlayer && gameBoard[1][1] == currentPlayer && gameBoard[2][0] == currentPlayer) return true; // Diagonal from top-right to bottom-left
    return false;
}

// Function to check if the game is a draw
bool checkDraw(char gameBoard[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (gameBoard[i][j] == ' ') return false; // If there is an empty cell, the game is not a draw
        }
    }
    return true; // All cells are filled, and no player has won
}

int main(int argc, char** argv) {
    char gameBoard[3][3] = { { ' ', ' ', ' ' }, { ' ', ' ', ' ' }, { ' ', ' ', ' ' } };
    char currentPlayer = 'X'; // Start with player X
    bool gameEnded = false;

    cout << "Tic-Tac-Toe Game" << endl;
    displayBoard(gameBoard);

    while (!gameEnded) {
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        if (row < 1 || row > 3 || col < 1 || col > 3 || gameBoard[row - 1][col - 1] != ' ') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        gameBoard[row - 1][col - 1] = currentPlayer;
        displayBoard(gameBoard);

        if (checkWin(gameBoard, currentPlayer)) {
            cout << "Player " << currentPlayer << " wins!" << endl;
            gameEnded = true;
        } else if (checkDraw(gameBoard)) {
            cout << "It's a draw!" << endl;
            gameEnded = true;
        }

        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
