#include <iostream>

int main()
{
    int x = 3, y = 3;

    int **pp_arr = new int*[ x ];

    for( size_t i = 0; i < x; i++ )
    {
        pp_arr[ i ] = new int[ y ];
    }

    // ------------------------------

    int count = 0;
    for( size_t i = 0; i < x; i++ )
    {
        for( size_t j = 0; j < y; j++ )
        {
            // #1
            std::cout << &pp_arr[ i ][ j ] << '\t';
            // #2
            // std::cout << std::addressof(pp_arr[ i ][ j ]) << '\t';
        }
        std::cout << '\n';
    }
    std::cout << '\n';

    // ------------------------------

    for( size_t i = 0; i < x; x++ )
    {
        delete[] pp_arr[ i ];
    }
    delete[] pp_arr;

    return 0;
}