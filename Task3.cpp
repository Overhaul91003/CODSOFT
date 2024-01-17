//Task 3

//TIC-TAC-TOE GAME

//Build a simple console-based Tic-Tac-Toe game that allows two players to play against each other .

#include <iostream>
#include <vector>

using namespace std;

char gameBoard[3][3];

void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            gameBoard[i][j] = ' ';
        }
    }
}

void displayGameBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << gameBoard[i][j] << " ";
            if (j != 2) {
                cout << "|";
            }
        }
        cout << endl;
        if (i != 2) {
            cout << "---+---+---" << endl;
        }
    }
}

int getPlayerMove() {
    int position;
    while (true) {
        cout << "Enter your move (1-9): ";
        cin >> position;
        if (position >= 1 && position <= 9) {
            int row = (position - 1) / 3;
            int col = (position - 1) % 3;
            if (gameBoard[row][col] == ' ') {
                return position;
            } else {
                cout << "Invalid move. Position already occupied." << endl;
            }
        } else {
            cout << "Invalid move. Please enter a number between 1 and 9." << endl;
        }
    }
}

void updateGameBoard(int position, char player) {
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;
    gameBoard[row][col] = player;
}

bool checkPlayerWin(char player) {
    for (int i = 0; i < 3; i++) {
        if (gameBoard[i][0] == player && gameBoard[i][1] == player && gameBoard[i][2] == player) {
            return true;
        }
    }

    for (int j = 0; j < 3; j++) {
        if (gameBoard[0][j] == player && gameBoard[1][j] == player && gameBoard[2][j] == player) {
            return true;
        }
    }

    if (gameBoard[0][0] == player && gameBoard[1][1] == player && gameBoard[2][2] == player) {
        return true;
    }
    if (gameBoard[0][2] == player && gameBoard[1][1] == player && gameBoard[2][0] == player) {
        return true;
    }

    return false;
}

bool checkGameDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (gameBoard[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void switchPlayersTurn(char& currentPlayer) {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

bool askPlayAgain() {
    char choice;
    cout << "Do you want to play again? (y/n): ";
    cin >> choice;
    return (choice == 'y' || choice == 'Y');
}

int main() {
    char currentPlayer = 'X';

    while (true) {
        initializeBoard();

        while (true) {
            displayGameBoard();
            int move = getPlayerMove();
            updateGameBoard(move, currentPlayer);

            if (checkPlayerWin(currentPlayer)) {
                displayGameBoard();
                cout << currentPlayer << " wins!" << endl;
                break;
            } else if (checkGameDraw()) {
                displayGameBoard();
                cout << "It's a draw!" << endl;
                break;
            }

            switchPlayersTurn(currentPlayer);
        }

        if (!askPlayAgain()) {
            cout << "Thanks for playing. Goodbye!" << endl;
            break;
        }
    }

    return 0;
}

