#include <iostream>

using namespace std;

int main()
{
    int x;                      // Zwykˆa zmienna caˆkowita
    int *w_int;                 // Wska«nik do zmiennej caˆkowitej

    w_int = &x;                 // Czytaj: "przypisz adres zmiennej x do wska«nika w_int"
    cout << "Podaj liczb©: ";
    cin >> x;                   // Wczytaj warto˜† do x; mo¾na tu u¾y† tak¾e zapisu *w_int
    cout << *w_int << '\n';     // Zwr¢† uwag© na u¾ycie * w celu odczytania warto˜ci
    *w_int = 10;
    cout << x;                  // Znowu wy˜wietla 10

    return 0;
}