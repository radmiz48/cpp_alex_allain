#include <iostream>

using namespace std;

int main()
{
    int a;
    int b;
    int c;
    int *ptr_a = &a;
    int *ptr_b = &b;
    int *ptr_c = &c;

    cout << "&a = " << ptr_a << '\n';
    cout << "sizeof(a) = " << sizeof(a) << '\n';
    cout << "&a - 1 = " << ptr_a - 1 << '\n' << '\n';

    cout << "&b = " << ptr_b << '\n';
    cout << "sizeof(b) = " << sizeof(b) << '\n';
    cout << "&b - 1 = " << ptr_b - 1 << '\n' << '\n';

    cout << "&c = " << ptr_c << '\n';
    cout << "sizeof(c) = " << sizeof(c) << '\n';
    cout << "&c - 1 = " << ptr_a - 1 << '\n' << '\n';

    long double d;
    long double *ptr_d = &d;

    cout << "&d = " << ptr_d << '\n';
    cout << "sizeof(d) = " << sizeof(d) << '\n';
    cout << "&d - 1 = " << ptr_d - 1 << '\n' << '\n';

    return 0;
}