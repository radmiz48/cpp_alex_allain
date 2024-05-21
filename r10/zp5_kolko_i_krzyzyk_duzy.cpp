#include <iostream>
#include <string>

using namespace std;

void displayTitle();
void displayBoard(char game_board[][6], int size);
bool checkSquaresHorizontally(char board[][6], int size, int squares_to_cross_out, char player);
bool checkSquaresVertically(char board[][6], int size, int squares_to_cross_out, char player);
bool checkSquaresDiagonallyLower(char board[][6], int size, int squares_to_cross_out, char player);
bool checkSquaresDiagonallyUpper(char board[][6], int size, int squares_to_cross_out, char player);
bool checkWinner(char game_board[][6], int size, int squares_to_cross_out, char player);

int main()
{
    // variables
    char game_board[6][6];      // game board of maximum size
    char player;                // player sign
    int size;                   // mactual size of the game board
    int turn = 0;               // game turn
    int row;                    // row index
    int col;                    // column index
    int squares_to_cross_out;   // squares to be crossed out depending on the size of the board
    
    // display the title screen
    displayTitle();

    // determine the board size from 3 to 6 squares
    do {
        cout << "Enter the size of the game board (3-6): ";
        cin >> size;
    } while (size < 3 || size > 6);

    // specify the number of squares to cross out (valid only for 3x3, 4x4, 5x5 and 6x6 boards)
    squares_to_cross_out = (size > 3) ? 4 : 3;
    cout << '\n';

    // fill the board with empty spaces
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            game_board[i][j] = ' ';
        }
    }

    // display an empty board
    displayBoard(game_board, size);

    // MAIN LOOP
    while (turn++ < size * size) {
        // change player each turn, player "X" starts
        player = (turn % 2 == 0) ? 'o' : 'x';
        cout << "TURN " << turn << ", PLAYER \"" << player << "\"\n";

        // select the row and column number of the board square
        do {
            cout << "Enter row and column numbers of an empty square (0-" << size - 1 << "): ";
            cin >> row >> col;
        } while (!(row >= 0 && row < size && col >= 0 && col < size) || game_board[row][col] != ' ');
        cout << '\n';

        // assign a player to the selected square
        game_board[row][col] = player;

        // display updated game board
        displayBoard(game_board, size);

        // check if the active player wins the game
        if (turn >= (squares_to_cross_out * 2 - 1) && checkWinner(game_board, size, squares_to_cross_out, player)) {
            cout << "Player \"" << player << "\" wins the game. Congratulations!\n\n";
            break;
        } else if (turn == size * size) {
            cout << "We have a draw. It was a challenge!\n\n";
        }
    }

    // print the latest board status
    displayBoard(game_board, size);
    cout << "Thank you for the game!\n";
    
    return 0;
}

void displayTitle() {
    cout << "\n\nTIC-TAC-TOE\n\n";
    cout << "Welcome to the game of tic-tac-toe! The player who cross off the required number of squares\n"; 
    cout << "horizontally, vertically or diagonally wins. You must cross off 3 squares on a 3x3 board\n";
    cout << "or 4 squares on 4x4, 5x5 and 6x6 boards. Player \"X\" starts the turn. Good luck!\n\n";
}

void displayBoard(char game_board[][6], int size) {
    // print column numbers
    cout << ' ';
    for (int i = 0; i < size; i++) {
        cout << i << ((i < size - 1) ? "   " : "\n\n");
    }

    // print the rows with their numbers
    for (int i = 0; i < size; i++) {
        cout << ' ';
        for (int j = 0; j < size; j++) {
            cout << game_board[i][j] << ((j < size - 1) ? " | " : "    " + to_string(i) + '\n');
        }
        // print lines between rows
        if (i < size - 1) {
            cout << string(size * 4 - 1, '-') << '\n';
        }
    }

    // maintain distance in front of each game board display
    cout << '\n';
}

bool checkSquaresHorizontally(char board[][6], int size, int squares_to_cross_out, char player) {
    int squares_crossed_out_in_row = 0;

    // rows
    for (int i = 0; i < size; i++) {
        // columns in each row 
        for (int j = 0; j < size; j++) {
            // adjacent squares in a row
            if (board[i][j] == player) {
                squares_crossed_out_in_row++;
            } else {
                squares_crossed_out_in_row = 0;
            }
            // return true if the active player has crossed off the required number of squares
            if (squares_crossed_out_in_row == squares_to_cross_out) {
                return true;
            }
        }
    }
    // return false if the active player has not crossed the required number of squares
    return false;
}

bool checkSquaresVertically(char board[][6], int size, int squares_to_cross_out, char player) {
    int squares_crossed_out_in_row = 0;

    // columns
    for (int i = 0; i < size; i++) {
        // row in each column
        for (int j = 0; j < size; j++) {
            // adjacent squares in a column
            if (board[j][i] == player) {
                squares_crossed_out_in_row++;
            } else {
                squares_crossed_out_in_row = 0;
            }
            // return true if the active player has crossed off the required number of squares
            if (squares_crossed_out_in_row == squares_to_cross_out) {
                return true;
            }
        }
    }
    // return false if the active player has not crossed the required number of squares
    return false;
}

bool checkSquaresDiagonallyLower(char board[][6], int size, int squares_to_cross_out, char player) {
    int squares_crossed_out_in_row = 0;

    // rows
    for (int i = 0; i < (size - squares_to_cross_out + 1); i++) {
        // column
        for (int j = 0; j < (size - squares_to_cross_out + 1); j++) {

            // temporary indexes used for increment (starting indexes)
            int tmp_i = i;
            int tmp_j = j;
            // counter used to check squares diagonally (left-right)
            int repeat = 0;

            // adjacent squares diagonally
            while (repeat++ < squares_to_cross_out) {
                if (board[tmp_i++][tmp_j++] == player) {
                    squares_crossed_out_in_row++;
                } else {
                    squares_crossed_out_in_row = 0;
                }
            }
            // return true if the active player has crossed off the required number of squares
            if (squares_crossed_out_in_row == squares_to_cross_out) {
                return true;
            }
        }
    }
    // return false if the active player has not crossed the required number of squares
    return false;
}

bool checkSquaresDiagonallyUpper(char board[][6], int size, int squares_to_cross_out, char player) {
    int squares_crossed_out_in_row = 0;

    // rows
    for (int i = 0; i < (size - squares_to_cross_out + 1); i++) {
        // columns
        for (int j = (squares_to_cross_out - 1); j < size; j++) {

            // temporary indexes used for decrement (starting indexes)
            int tmp_i = i;
            int tmp_j = j;
            // counter used to check squares diagonally (right-left)
            int repeat = 0;

            // adjacent squares diagonally
            while (repeat++ < squares_to_cross_out) {
                if (board[tmp_i++][tmp_j--] == player) {
                    squares_crossed_out_in_row++;
                } else {
                    squares_crossed_out_in_row = 0;
                }
            }
            // return true if the active player has crossed off the required number of squares
            if (squares_crossed_out_in_row == squares_to_cross_out) {
                return true;
            }
        }
    }
    // return false if the active player has not crossed the required number of squares
    return false;
}

bool checkWinner(char game_board[][6], int size, int squares_to_cross_out, char player) {
    return  
        checkSquaresHorizontally(game_board, size, squares_to_cross_out, player) || 
        checkSquaresVertically(game_board, size, squares_to_cross_out, player) ||
        checkSquaresDiagonallyLower(game_board, size, squares_to_cross_out, player) ||
        checkSquaresDiagonallyUpper(game_board, size, squares_to_cross_out, player);
}