#include <iostream>

void createMulTab( int **pp_mul_tab, int& r, int& c)
{
    for( size_t i = 0; i < r; i++ ) 
    {
        for( size_t j = 0; j < c; j++ )
        {
            // #1
            // *(*(pp_mul_tab + i) + j) = (i + 1) * (j + 1);
            // #2
            pp_mul_tab[ i ][ j ] = (i + 1) * (j + 1);
        }
    }
}

void displayMulTab( int **pp_mul_tab, int& r, int& c)
{
    // Display column numbers
    for( size_t i = 0; i < c; i++ )
    {
        std::cout << '\t' << i + 1;
    }
    std::cout << '\n' << '\n';
    // Display row numbers and array values
    for( size_t i = 0; i < r; i++ ) 
    {
        std::cout << (i + 1) << '\t';
        for( size_t j = 0; j < c; j++ )
        {
            // #1
            // std::cout << *(*(pp_mul_tab + i) + j) << '\t';
            // #2
            std::cout << pp_mul_tab[ i ][ j ] << '\t';
        }
        std::cout << '\n' << '\n';
    }
}

int main()
{
    // Dimensions of the multiplication table (r - rows, c - columns)
    int r, c;

    std::cout << "Enter the dimensions of the multiplication table (rows and columns): ";
    std::cin >> r >> c;
    std::cout << '\n';

    // Declaring a pointer to an array of pointers (two-dimensional array)
    int **pp_mul_tab;
    // Initialize a pointer to an array of pointers (two-dimensional array)
    pp_mul_tab = new int*[ r ];
    // Initialize individual pointers in an array of pointers (two-dimensional array)
    for( size_t i = 0; i < r; i++ )
    {
        pp_mul_tab[ i ] = new int[ c ];
    }
    // Create a multiplication table
    createMulTab( pp_mul_tab, r, c );
    // Display a multiplication table
    displayMulTab( pp_mul_tab, r, c );
    // Free up your computer's memory
    for( size_t i = 0; i < r; i++ )
    {
        delete[] pp_mul_tab[ i ];
    }
    delete[] pp_mul_tab;
}

