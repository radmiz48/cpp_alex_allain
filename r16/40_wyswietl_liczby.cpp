#include <iostream>

void wyswietlLiczby( int liczba ) {
    // Dwa wywolania tej funkcji w instrukcji cout otocza wewnetrzna
    // sekwencje zawierajaca liczby (liczba+1)...99...(liczba+1)
    std::cout << liczba;
    // Poniewaz zaczynamy od wartosci mniejszej od 9, musimy rekurencyjnie wyswietlac
    // sekwencje dla wartosci (liczba+1)...99...(liczba+1)
    if( liczba < 9 ) {
        wyswietlLiczby( liczba + 1 );
    }
    std::cout << liczba; 
}

int main() {
    wyswietlLiczby( 1 );
    return 0;
}