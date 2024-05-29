#include <iostream>

using namespace std;

void zamien1(int lewy, int prawy) {
    int tymczas = lewy;
    lewy = prawy;
    prawy = tymczas;
}

void zamien2(int *lewy, int *prawy) {
    int tymczas = *lewy;
    *lewy = *prawy;
    *prawy = tymczas;
}

int main()
{
    int x = 1, y = 2;
    zamien1(x, y);
    cout << x << " " << y << '\n';
    zamien2(&x, &y);
    cout << x << " " << y << '\n';

    return 0;
}