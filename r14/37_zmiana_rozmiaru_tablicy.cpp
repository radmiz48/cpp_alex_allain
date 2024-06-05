#include <iostream>

using namespace std;

int *zwiekszTablice(int *w_wartosci, int *rozmiar);
void drukujTablice(int *w_wartosci, int rozmiar, int zajete_pola);

int main()
{
    int nastepny_element = 0;
    int rozmiar = 10;
    int *w_wartosci = new int[rozmiar];
    int wart;
    cout << "Podaj liczbę: ";
    cin >> wart;
    while (wart > 0) {
        if (rozmiar == nastepny_element + 1) {
            // Wszystko, co musimy teraz zrobić, to zaimplementować
            // funkcję zwiekszTablice. Zauważ, że rozmiar musimy
            // przekazać jako wskaźnik, ponieważ w każdej chwili 
            // powinniśmy znać na bieżąco wielkość roznącej tablicy!
            w_wartosci = zwiekszTablice(w_wartosci, &rozmiar);
        }
        w_wartosci[nastepny_element] = wart;
        nastepny_element++;
        cout << "Oto bieżące parametry tablicy: " << endl;
        drukujTablice(w_wartosci, rozmiar, nastepny_element);
        cout << "Podaj liczbę (0 - wyjście z programu): ";
        cin >> wart;
    }
    delete[] w_wartosci;
}

void drukujTablice(int *w_wartosci, int rozmiar, int zajete_pola) {
    cout << "Całkowity rozmiar tablicy: " << rozmiar << endl;
    cout << "Liczba zajetych pól tablicy: " << zajete_pola << endl;
    cout << "Wartości tablicy: " << endl;
    for (int i = 0; i < zajete_pola; i++) {
        cout << "w_wartosci[" << i << "] = " << w_wartosci[i] << endl;
    }
}

int *zwiekszTablice(int *w_wartosci, int *rozmiar) {
    *rozmiar *= 2;
    int *w_nowe_wartosci = new int[*rozmiar];
    for (int i = 0; i < *rozmiar; ++i) {
        w_nowe_wartosci[i] = w_wartosci[i];
    }
    delete[] w_wartosci;
    return w_nowe_wartosci;
}