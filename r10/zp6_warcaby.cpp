#include <iostream>

using namespace std;

void displayTitle();
void displayGameBoard(char game_board[][8], int size);

int main()
{
    // Specify markers for each player's pawns
    char w = 'o';   // white simple pawn
    char W = 'O';   // white "king" pawn
    char b = '*';   // black simple pawn
    char B = '@';   // black "king" pawn
    
    // Create a checkers board
    int size = 8;
    char game_board[8][8];

    // Fill the checkers board with (w)hite and (b)lack pawns, "dark" squares (" ") and "light" squares ("x")
    for (int i = 0; i < size; i++) {
        char marker = (i == 3 || i == 4) ? ' ': ((i < 3) ? w : b);
        for (int j = 0; j < size; j++) {
            if (i % 2 == 0)
                game_board[i][j] = (j % 2 != 0) ? marker : 'x';
            else 
                game_board[i][j] = (j % 2 == 0) ? marker : 'x';
        }
    }

    // Before starting the game, determine the number of pawns for each player
    int pawns_white = 12;
    int pawns_black = 12;

    // declare the variable for an active polayer
    char player;

    // MAIN LOOP 
    // while (pawns_white && pawns_black) {

    // }

    displayTitle();
    displayGameBoard(game_board, size);

    return 0;
}

void displayTitle() {
    cout << '\n';
    cout << string(100, '-');
    cout << "\n\nCHECKERS (CLASSIC)\n\n";
    cout << "Important rules for moving a pawn:\n";
    cout << "1) Pawns can only move diagonally and forwards (towards the opponent only on \"dark\" squares).\n";
    cout << "2) Pawns can move up and down once they become \"kings\", reaching the last row on the opposite side.\n";
    cout << "3) The game starts with the player with the \"white\" pawns (\"o\" and \"O\").\n";
    cout << "4) The player with the \"black\" pawns (\"*\" and \"@\") starts the game second.\n";
    cout << "5) \"Dark\" squares are marked with empty space, and \"light\" squares are marked with an \"x\" (no movement).\n\n";
    cout << "Good luck!\n\n";
    cout << string(100, '-');
    cout << "\n\n";
}

void displayGameBoard(char game_board[][8], int size) {
    // print column indexes
    cout << " ";
    for (int i = 0; i < size; i++) {
        cout << i << ((i < size - 1) ? "   " : "\n");
    }
    // print the contents of the chessboard
    for (int i = 0; i < size; i++) {
        cout << " ";
        // row
        for (int j = 0; j < size; j++) {
            cout << game_board[i][j] << ((j < size - 1) ? " | " : "  " + to_string(i) + '\n');
        }
        // dividing lines
        if (i < size - 1) {
            cout << string(size * 4 - 1, '-') << '\n';
        }
    }
    // keep your distance to the next exit
    cout << '\n';
}