#include <iostream>

using namespace std;

struct UserData
{
    string name;
    string surname;
};

UserData updateUserData1() {
    UserData user;
    cout << "Enter user name: ";
    cin >> user.name;
    cout << "Enter user surname: ";
    cin >> user.surname;
    return user;
}

void updateUserData2(UserData &user) {
    cout << "Enter user name: ";
    cin >> user.name;
    cout << "Enter user surname: ";
    cin >> user.surname;
}

void updateUserData3(string *name, string *surname) {
    cout << "Enter user name: ";
    cin >> *name;
    cout << "Enter user surname: ";
    cin >> *surname;
}

int main()
{
    // 1) Update the user information using the return function (no pointers or references)
    UserData user1;
    user1 = updateUserData1();
    cout << "Hello, " << user1.name << " " << user1.surname << "! How are you today?\n\n";

    // 2) Update user information using the reference
    UserData user2;
    updateUserData2(user2);
    cout << "Hello, " << user2.name << " " << user2.surname << "! How are you today?\n\n";

    // 3) Update user information using the pointers
    UserData user3 {"n/a", "n/a"};
    updateUserData3(&user3.name, &user3.surname);
    cout << "Hello, " << user3.name << " " << user3.surname << "! How are you today?\n\n";

    return 0;
}