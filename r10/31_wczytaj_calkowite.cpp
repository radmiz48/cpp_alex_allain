#include <iostream>

using namespace std;

int main()
{
    int wartosci[100];
    for (int i = 0; i < 100; i++) {
        cout << "Podaj wartość: " << i << ": ";
        cin >> wartosci[i];
    }
}