#include <iostream>

using namespace std;

int main()
{
    int x;                      // Zwyk�a zmienna ca�kowita
    int *w_int;                 // Wska�nik do zmiennej ca�kowitej

    w_int = &x;                 // Czytaj: "przypisz adres zmiennej x do wska�nika w_int"
    cout << "Podaj liczb�: ";
    cin >> x;                   // Wczytaj warto�� do x; mo�na tu u�y� tak�e zapisu *w_int
    cout << *w_int << '\n';     // Zwr�� uwag� na u�ycie * w celu odczytania warto�ci
    *w_int = 10;
    cout << x;                  // Znowu wy�wietla 10

    return 0;
}