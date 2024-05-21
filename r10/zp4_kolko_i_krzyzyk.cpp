#include <iostream>

using namespace std;

void printBoard(char board[][3], int size);
void title();
bool isMovePossible(char board[][3], int size, int choice);
void fillEmptyBoardsSquare(char board[][3], int choice, char player);
bool isWinner(char board[][3], char player);

int main()
{
    // VARIABLES
    char board[3][3] {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    }; 
    char player;    // active player
    int choice;     // choice of square by the active player
    int turn = 0;   // active turn
    
    // MAIN LOOP
    title();
    while (turn++ < 9) {
        // print the active game board
        printBoard(board, 3);
        // change player each turn, player "X" starts
        player = (turn % 2 == 0) ? 'O': 'X';
        cout << "TURN " << turn << ", PLAYER " << player << '\n';
        do
        {
            cout << "Select an empty square (1-9): ";
            cin >> choice;
        } while (!isMovePossible(board, 3, choice));
        fillEmptyBoardsSquare(board, choice, player);
        cout << "\n";
        // check if the active player is the winner and leave the program if so
        if (turn >= 5 && isWinner(board, player)) {
            cout << "Player \"" << player << "\" wins the game. Congratulations!\n\n";
            break;
        } else if (turn == 9) {
            cout << "We have a draw. It was a challenge!\n\n";
        }
    }
    // print the latest board status
    printBoard(board, 3);
    cout << "Thank you for the game!\n";
    return 0;
}

void printBoard(char board[][3], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << ' ' << board[i][j] << ' ' << ((j < size - 1) ? '|' : '\n');
        }
        cout << ((i < size - 1) ? "---+---+---\n" : "\n");
    }
}

void title() {
    cout << "\n\nTIC-TAC-TOE\n\n";
    cout << "Welcome to the game of tic-tac-toe! The player who crosses 3 squares horizontally,\n";
    cout << "vertically or diagonally wins. Player \"X\" starts the turn. Good luck!\n\n";
}

bool isMovePossible(char board[][3], int size, int choice) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board[i][j] == choice + 48) {
                // the user selected an empty square
                return true;
            }
        }
    }
    // the user selected an occupied square
    return false;
}

void fillEmptyBoardsSquare(char board[][3], int choice, char player) {
    // match the user's selection to the square of the board number
    switch (choice)
    {
        case 1 ... 3:   board[0][choice - 1] = player;  break;
        case 4 ... 6:   board[1][choice - 4] = player;  break;
        case 7 ... 9:   board[2][choice - 7] = player;  break;
    }
}

bool isWinner(char board[][3], char player) {
    if ( 
        // check horizontally
        (board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][2] == player) || 
        (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][2] == player) || 
        (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][2] == player) ||
        // check vertically
        (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[2][0] == player) ||
        (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[2][1] == player) ||
        (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[2][2] == player) ||
        // check diagonally
        (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == player) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] == player)
    ) {
        return true;
    } else {
        return false;
    }
}