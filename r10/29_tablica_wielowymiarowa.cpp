#include <iostream>

using namespace std;

int main()
{      
    int tablica[8][8];  // Deklaracja tablicy, kt?ra wygl?da jak szachownica

    for (int i =0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            tablica[i][j] = i * j;      // Nadanie warto?ci ka?demu elementowi tablicy
        }
    }

    cout << "Tabliczka mno?enia:\n";
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << "[ " << i << " ][ " << j << " ] = " << tablica[i][j] << "\n";
        }
    }

    return 0;
}