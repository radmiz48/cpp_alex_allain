#include <iostream>

using namespace std;

struct PhoneBook
{
    string full_name = "";
    string phone_number = "";
};

void showMainMenu(int size) {
    cout << "\n--- PERSONAL PHONE BOOK ---\n\n";
    cout << "The personal phone book is designed to store up to " << size << " contacts.\n\n";
    cout << "* Selection menu *\n";
    cout << "0. Close the program.\n";
    cout << "1. Add contact.\n";
    cout << "2. Remove contact.\n";
    cout << "3. Show all contacts.\n";
    cout << "4. Show specific contact.\n\n";
}

int getInputNumber(string msg, int begin, int end) {
    int choice;
    do {
        cout << msg << " (" << begin << "-" << end <<  "): ";
        cin >> choice;
    } while (choice < begin || choice > end);
    return choice;
}

void showPhoneBookContents(PhoneBook myPhoneBook[], int begin = 0, int end = 0) {
    for (int i = begin; i < end; i++) {
        if (myPhoneBook[i].full_name != "") {
            cout << "\t[" << i + 1 << "]\n";
            cout << "\t\tName:\t" << myPhoneBook[i].full_name << '\n';
            cout << "\t\tPhone:\t" << myPhoneBook[i].phone_number << '\n';
        } else {
            cout << "\t[" << i + 1 << "]\n";
            cout << "\t\tn/a\n";
        }
    }
}

int main()
{
    int choice_main;
    int size = 5;
    int entry_to_remove;
    int entry_to_show;
    PhoneBook myPhoneBook[5];

    do {
        // Show the program's main menu
        showMainMenu(size);

        // Ask the user to enter their data
        choice_main = getInputNumber("Your choice", 0, size - 1);

        // Enter the submenu after the user enters the data
        switch (choice_main)
        {
        case 0:
            cout << "Closing the program...\n\n";
            break;
        case 1:
            cout << "\n\t** Add contact **\n\n";
            for (int i = 0; i < size; i++) {
                // Add a new entry if there is space available
                if (myPhoneBook[i].full_name == "") {
                    cin.ignore();
                    cout << "\tFull name: ";
                    getline(cin, myPhoneBook[i].full_name);
                    cout << "\tPhone number: "; 
                    getline(cin, myPhoneBook[i].phone_number);
                    cout << "\n\tThe new contact has been added to your personal phone book.\n\n\n";
                    break;
                // If there is no free space, inform the user
                } else if (i == size - 1) {
                    cout << "\tThe phone book is full. Delete some contacts to add new ones.\n\n\n";
                }
            }
            break;
        case 2:
            cout << "\n\t** Remove contact **\n\n";
            entry_to_remove = getInputNumber("\tYour choice", 1, size);
            for (int i = 0; i < size; i++) {
                // Delete the selected entry by filling it with blanks
                if (myPhoneBook[i].full_name == myPhoneBook[entry_to_remove - 1].full_name) {
                    myPhoneBook[i].full_name = "";
                    myPhoneBook[i].phone_number = "";
                    cout << "\n\tThe contact you entered has been removed from your personal phone book.\n\n\n";
                    break;
                }
            }
            break;
        case 3:
            cout << "\n\t** Show all contacts **\n\n";
            showPhoneBookContents(myPhoneBook, 0, size);
            cout << "\n\n";
            break;
        case 4:
            cout << "\n\t** Show specific contact **\n\n";
            entry_to_show = getInputNumber("\tYour choice", 1, size);
            showPhoneBookContents(myPhoneBook, entry_to_show - 1, entry_to_show);
            cout << "\n\n";
            break;
        default:
            break;
        }

    } while (choice_main);
    // End of program
    return 0;
}