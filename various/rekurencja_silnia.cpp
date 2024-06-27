#include <iostream>

int fac( int n ) {
    if( n < 2 ) {

        return 1;
    }
    return n * fac( n - 1 );
}

int main() 
{
    int n;

    do
    {
        std::cout << "Enter a number (0-10) to calculate its factorial: ";
        std::cin >> n;
    } while ( n < 0 || n > 10 );
    
    std::cout << '\n' << n << "! = " << fac(n) << '\n';

    return 0;
}