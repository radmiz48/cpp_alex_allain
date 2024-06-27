#include <iostream>

int pow( int x, int y ) {
    if( y < 1 ) {
        return 1;
    }
    return x * pow( x, y - 1 );
}

int main()
{
    int x;
    int y;
    
    while( true )
    {
        std::cout << "Enter the base and power factor (stop the program if the base is 0): ";
        std::cin >> x >> y;
        
        if( x == 0 ) {
            break;
        }

        std::cout << x << '^' << y << '=' << pow( x, y ) << '\n';
    };
    
    return 0;
}