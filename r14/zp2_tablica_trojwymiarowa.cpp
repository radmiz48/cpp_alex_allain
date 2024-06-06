#include <iostream>

void getArrayDimensions( int& x, int& y, int& z );
void updateMultiplicationTable( int*** arr, int& x, int& y, int& z );
void displayMultiplicationTable( int*** arr, int& x, int& y, int& z );

int main()
{
    // Create a 3D array using pointers
        // x – rows of a single array (width)
        // y – columns of a single array (height)
        // z – number of all 2D arrays (depth)
    int x, y, z;
    int ***ppp_multabs;

    // Ask the user for the dimensions of the board
    getArrayDimensions( x, y, z );
    // ---------------------------------------------------------------------------

    // Allocates memory blocks for the number of 2D arrays
    ppp_multabs = new int**[ z ];
    for( size_t i = 0; i < z; i++ ) 
    {
        // Allocates memory blocks for the number of rows in each 2D array
        ppp_multabs[ i ] = new int*[ x ];
        for( size_t j = 0; j < x; j++ )
        {
            // Allocates memory blocks for the number of columns in each 2D array
            ppp_multabs[ i ][ j ] = new int[ y ];
        }
    }
    // ---------------------------------------------------------------------------

    // Fill the 3D array with 2D multiplication tables of the given dimensions
    updateMultiplicationTable( ppp_multabs, x, y, z );
    // ---------------------------------------------------------------------------

    // Display a 3D array
    displayMultiplicationTable( ppp_multabs, x, y, z );
    // ---------------------------------------------------------------------------

    // Free up memory when the program ends
    for( size_t i = 0; i < z; i++ )
    {
        for( size_t j = 0; j < x; j++ )
        {
            // Delete the entire array by dimension y
            delete[] ppp_multabs[ i ][ j ];
        }
        // Delete the entire array by dimension x
        delete[] ppp_multabs[ i ];
    }
    // Delete the entire array by dimension z
    delete[] ppp_multabs;
    // ---------------------------------------------------------------------------

    return 0;
}

void getArrayDimensions( int& x, int& y, int& z )
{
    do
    {
        std::cout << "Enter 3D array dimensions (x, y, z): ";
        std::cin >> x >> y >> z;
    } while ( x < 0 || y < 0 || z < 0 );
}

void updateMultiplicationTable( int*** arr, int& x, int& y, int& z ) 
{
    // Iterate by number of 2D arrays ('z' dimension)
    for( size_t i = 0; i < z; i++ )
    {
        // Iterate over the number of rows in each 2D array ('x' dimension)
        for( size_t j = 0; j < x; j++ )
        {
            // Iterate over the number of columns in each 2D array ('y' dimension)
            for( size_t k = 0; k < y; k++ )
            {
                // Assign a value
                arr[ i ][ j ][ k ] = (j + 1) * (k + 1);
            }
        }
    }
}

void displayMultiplicationTable( int*** arr, int& x, int& y, int& z )
{
    std::cout << '\n';
    for( size_t i = 0; i < z; i++ )
    {
        std::cout << '#' << i;
        // Print column numbers
        for( int c = 0; c < y; c++ )
        {
            std::cout << '\t' << '[' << c + 1 << ']';
        }
        std::cout << '\n' << '\n';
        // Print row numbers with array values
        for( size_t j = 0; j < x; j++ )
        {
            std::cout << '[' << j + 1 << ']' << '\t';
            for( size_t k = 0; k < y; k++ )
            {
                // std::cout << *(*(*(ppp_multabs + i) + j) + k) << '\t';
                std::cout << arr[ i ][ j ][ k ] << '\t';
            }
            std::cout << '\n' << '\n';
        }
        std::cout << std::string( 8 * (y + 1), '-' ) << '\n' << '\n';
    }
}