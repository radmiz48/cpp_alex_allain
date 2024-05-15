#include <iostream>

using namespace std;

int sumujTablice(int wartosci[], int rozmiar) 
{
    int suma = 0;
    // P?tla zatrzyma si?, gdy i == rozmiar. Dlaczego? Bo ostatni element ma warto?? rozmiar - 1
    for (int i = 0; i < rozmiar; i ++) {
        suma += wartosci[i];
    }
    return suma;
}

int main() 
{
    int wartosci[10];
    for (int i = 0; i < 10; i++) {
        cout << "Podaj warto?? " << i << ": ";
        cin >> wartosci[i];
    }
    cout << sumujTablice(wartosci, 10) << endl;

    return 0;
}