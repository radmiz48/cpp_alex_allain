#include <iostream>

using namespace std;

void updateUserInfo(string *p_name, string *p_surname) {
    if (p_name != NULL) {
        cout << "Enter user name: ";
        cin >> *p_name;
    }
    if (p_surname != NULL) {
        cout << "Enter user surname: ";
        cin >> *p_surname;
    }
}

int main()
{
    string name;
    string *p_name = &name;
    // string *p_name = nullptr;

    string surname;
    // string *p_surname = &surname;
    string *p_surname = nullptr;

    updateUserInfo(p_name, p_surname);
    cout << "\nHello" << ((p_name) ? " " + name : "") << ((p_surname) ? " " + surname : "") << "! How are you today?\n\n";

    return 0;
}