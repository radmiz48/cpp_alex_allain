#include <iostream>

using namespace std;

struct UserData
{
    string first_name;
    string last_name;
    string phone;
    string address;
};

int main()
{
    UserData user1;

    cout << '\n';
    cout << "Enter your first name: ";      
    cin >> user1.first_name;
    cout << "Enter your last name: ";       
    cin >> user1.last_name;
    cout << "Enter your phone number: ";    
    cin >> user1.phone; 
    cin.ignore();
    cout << "Enter your home address: ";    
    getline(cin, user1.address);
    
    cout << "\n*** USER'S BUSINESS CARD ***\n";
    cout << "FIRST NAME:\t" << user1.first_name << '\n';
    cout << "LAST NAME:\t" << user1.last_name << '\n';
    cout << "PHONE NUMBER:\t" << user1.phone << '\n';
    cout << "HOME ADDRESS:\t" << user1.address << '\n';

    return 0;
}