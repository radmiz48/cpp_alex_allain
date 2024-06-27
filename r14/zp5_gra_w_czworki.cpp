#include <iostream>

void updateGridDimensions( int& size_x, int& size_y );
void displayGrid( char** game_grid, int& size_x, int& size_y );
void displayMainMenu();
int getPlayerMove( char** game_grid, int& size_y );
void updateGridWithToken( char** game_grid, int& size_x, int& col, char& token );
bool checkGridHorizontally( char** game_grid, int& size_x, int& size_y, char& token );
bool checkGridVertically( char** game_grid, int& size_x, int& size_y, char& token );
bool checkGridDiagonally( char** game_grid, int& size_x, int& size_y, char& token );

// ------------------------------------------------------------------------------------

int main()
{
    // Variables
    char player;
    int turn = 0;
    int move;
    int x;
    int y;
    bool is_winner;
    displayMainMenu();
    updateGridDimensions( x, y ); 

    // Create a grid for the Connect 4 game 
    char** grid = new char*[ x ];
    for( size_t i = 0; i < x; i++ )
    {
        grid[ i ] = new char[ y ];
    } 
    // Fill the grid with empty spaces '_'
    for( size_t i = 0; i < x; i++ )
    {
        for( size_t j = 0; j < y; j++ )
        {
            grid[ i ][ j ] = '_';
        }
    }
    // Display the newly created empty game grid
    displayGrid( grid, x, y );

    //MAIN LOOP
    while ( ++turn < x * y )
    {
        // Change active player each round. The "+" player starts the game
        player = ( turn % 2 != 0 ) ? '+' : 'x' ;
        std::cout << "TURN " << turn << " / " << "PLAYER '" << player << "'\n";

        // Get player movement (column number) and update game grid
        move = getPlayerMove( grid, y );
        updateGridWithToken( grid, x, move, player );
        displayGrid( grid, x, y );

        // Check if the active player is the winner
        if ( turn >= 7 )
        {
            is_winner = checkGridHorizontally( grid, x, y, player ) || 
                        checkGridVertically( grid, x, y, player ) || 
                        checkGridDiagonally( grid, x, y, player );
            if( is_winner )
            {
                std::cout << "Congratulations! Player '" << player << "' wins the game!\n\n";
                break;
            }
        }    
    }  

    // Free up memory
    for( size_t i = 0; i < x; i++ )
    {
        delete[] grid[ i ];
    }
    delete[] grid;

    // Close the program successfully
    std::cout << "Thank you both for playing!\n\n";
    return 0;
}

// ------------------------------------------------------------------------------------

void updateGridDimensions( int& size_x, int& size_y )
{   
    do
    {
        std::cout << "Enter the dimensions of the grid: ";
        std::cin >> size_x >> size_y;
    } while ( size_x < 6 || size_y < 7 );
}

void displayGrid( char** game_grid, int& size_x, int& size_y )
{
    // Print column numbers
    std::cout << "\n  ";
    for( size_t i = 0; i < size_y; i++ )
    {
        std::cout << i << "   ";
    }
    std::cout << "\n\n";
    // Print the rows of the grid with their numbers
    for( size_t i = 0; i < size_x; i++ )
    {
        std::cout << "| ";
        for( size_t j = 0; j < size_y; j++ )
        {
            std::cout << game_grid[ i ][ j ] << " | ";
        }
        std::cout << '\t' << i << '\n';
    }
    // Print the base of the grid
    std::cout << std::string( size_y * 4 + 1, 'w' ) << "\n\n";
}

void displayMainMenu()
{
    std::cout << "\n*** CONNECT FOUR ***\n\n";
    std::cout << "Players choose their colors ('+' or 'x') and drops tokens each turn into a suspended grid.\n";
    std::cout << "The dimensions of the game grid can be any, but not smaller than 6 rows in 7 columns.\n";
    std::cout << "The player who drops 4 tokens next to each other (vertically, horizontally or diagonally) wins the game.\n\n";
    std::cout << "The player with the '+' token starts the game. Good luck!\n\n";
}

int getPlayerMove( char** game_grid, int& size_y )
{
    int col;
    while( true )
    {
        std::cout << "\nSelect a column with empty space ( 0 - " << size_y - 1 << " ): ";
        std::cin >> col;
        // Check that the column number entered is correct
        if( col < 0 || col > size_y - 1 )
        {
            std::cout << "Wrong column number. Try again.\n";
        } 
        // Check if the selected column has empty spaces
        else if( game_grid[ 0 ][ col ] != '_' )
        {
            std::cout << "The selected column is full. Try again.\n";
        }
        else 
        {
            return col;
        }
    }
}

void updateGridWithToken( char** game_grid, int& size_x, int& col, char& token )
{
    for( size_t i = size_x - 1; i >= 0; i-- )
    {
        if( game_grid[ i ][ col ] == '_' )
        {
            game_grid[ i ][ col ] = token;
            break;
        }
    }
}

bool checkGridHorizontally( char** game_grid, int& size_x, int& size_y, char& token )
{
    // Start checking horizontally from the bottom of the game grid
    // The <size_t> type does not work for backward iteration
    for( int i = size_x - 1; i >= 0; i-- )
    {
        for( size_t j = 0; j <= size_y - 4; j++ )
        {
            // Auxiliary prints
            // std::cout << "game_grid[ " << i << " ][ " << j << " ] = " << game_grid[ i ][ j ] << '\n';
            // std::cout << "game_grid[ " << i << " ][ " << j + 1 << " ] = " << game_grid[ i ][ j + 1 ] << '\n';
            // std::cout << "game_grid[ " << i << " ][ " << j + 2 << " ] = " << game_grid[ i ][ j + 2 ] << '\n';
            // std::cout << "game_grid[ " << i << " ][ " << j + 3 << " ] = " << game_grid[ i ][ j + 3 ] << '\n';
            // std::cout << "token = " << token << '\n';
            if ( 
                game_grid[ i ][ j ] == token && 
                game_grid[ i ][ j + 1 ] == token && 
                game_grid[ i ][ j + 2 ] == token &&
                game_grid[ i ][ j + 3 ] == token
                ) 
            {
                return true;
            }
        }
    }
    return false;
}

bool checkGridVertically( char** game_grid, int& size_x, int& size_y, char& token )
{
    // The <size_t> type does not work for backward iteration
    for( size_t i = 0; i < size_y; i++ )
    {
        // Start checking vertically from the bottom of the game grid
        for( int j = size_x - 1; j > size_x - 4; j-- )
        {
            // Auxiliary prints
            // std::cout << "game_grid[ " << j << " ][ " << i << " ] = " << game_grid[ j ][ i ] << '\n';
            // std::cout << "game_grid[ " << j - 1 << " ][ " << i << " ] = " << game_grid[ j - 1 ][ i ] << '\n';
            // std::cout << "game_grid[ " << j - 2 << " ][ " << i << " ] = " << game_grid[ j - 2 ][ i ] << '\n';
            // std::cout << "game_grid[ " << j - 3 << " ][ " << i << " ] = " << game_grid[ j - 3 ][ i ] << '\n';
            // std::cout << "token = " << token << '\n';
            if ( 
                game_grid[ j ][ i ] == token && 
                game_grid[ j - 1 ][ i ] == token && 
                game_grid[ j - 2 ][ i ] == token &&
                game_grid[ j - 3 ][ i ] == token
                ) 
            {
                return true;
            }
        }
    }
    return false;
}

bool checkGridDiagonally( char** game_grid, int& size_x, int& size_y, char& token )
{
    // Check starting from the bottom of the game grid upwards
    for( int i = size_x - 1; i > size_x - 4; i-- )
    {
        for( size_t j = 0; j <= size_y - 4; j++ )
        {
            if (
                game_grid[ i ][ j ] == token && 
                game_grid[ i - 1 ][ j + 1 ] == token && 
                game_grid[ i - 2 ][ j + 2 ] == token &&
                game_grid[ i - 3 ][ j + 3 ] == token
            )
            {
                return true;
            }
        }
    }
    // Check from the top of the game grid down
    for( size_t i = 0; i <= size_x - 4; i++ )
    {
        for( size_t j = 0; j <= size_y - 4; j++ )
        {
            if (
                game_grid[ i ][ j ] == token && 
                game_grid[ i + 1 ][ j + 1 ] == token && 
                game_grid[ i + 2 ][ j + 2 ] == token &&
                game_grid[ i + 3 ][ j + 3 ] == token
            )
            {
                return true;
            }
        }
    }
    return false;
}