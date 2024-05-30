#include <iostream>

using namespace std;

double product1(double &a, double &b, double &sum) {
    sum = a + b;
    return a * b;
}

double product2(double *ptr_a, double *ptr_b, double *ptr_sum) {
    *ptr_sum = *ptr_a + *ptr_b;
    return *ptr_a * *ptr_b;
}

int main()
{
    double a, b, sum, mul;

    cout << "Enter the first number: ";     cin >> a;
    cout << "Enter the second number: ";    cin >> b;
    cout << '\n';

    // mul = product1(a, b, sum);
    // cout << a << " * " << b << " = " << mul << '\n';
    // cout << a << " + " << b << " = " << sum << '\n';
    // cout << '\n\n';

    mul = product2(&a, &b, &sum);
    cout << a << " * " << b << " = " << mul << '\n';
    cout << a << " + " << b << " = " << sum << '\n';
    cout << '\n';

    return 0;
}