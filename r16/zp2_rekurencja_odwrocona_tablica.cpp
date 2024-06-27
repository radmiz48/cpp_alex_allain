#include <iostream>

// // Usual approach
// void printArrRev( int fib[], int size ) {
//     std::cout << fib[ size - 1 ] << ' ';
//     if( size > 1 ) {
//         printArrRev( fib, size - 1 );
//     }
// }

// // Using array arithmetic
// void printArrRev( int fib[], int size ) {
//     std::cout << *(fib + size - 1) << ' ';
//     if( size > 1 ) {
//         printArrRev( fib, size - 1 );
//     }
// }

// Using pointers
void printArrRev( int* ptr, int size ) {
    std::cout << *(ptr + size - 1) << ' ';
    if( size > 1 ) {
        printArrRev( ptr, size - 1 );
    }
}

int main()
{
    int fib[] { 1, 1, 2, 3, 5, 8, 13, 21 };
    int size = sizeof(fib) / sizeof (int);
    int *p_fib = fib;

    std::cout << "Fibonacci numbers: ";
    for( size_t i = 0; i < size; i++ ) {
        std::cout << fib[ i ] << ' ';
    }
    std::cout << '\n';

    std::cout << "Fibonacci numbers (reverse order): ";
    printArrRev( p_fib, size );
    std::cout << '\n';

    return 0;
}