#include <iostream>
#include <string>

struct Friend
{
    std::string name = "";
    int days = 0;
};

void addFriendToList( Friend* p_friends_list, int& size );
Friend* resizeFriendsList( Friend* p_friends_list, int& size );
void displayFriendsList( Friend* p_friends_list, int& size );
void displayTitleScreen( std::string menu_options[], int size );
int askForNumberInput( int start, int stop );
void updateDaysNumber( Friend* p_friend_list, int& size );
void sortFriendsListByDays( Friend* p_friend_list, int& size );
void sortFriendsListByNames( Friend* p_friend_list, int& size );

// ------------------------------------------------------------------------------------

int main()
{
    // Create a static array with main menu options to choose from
    std::string menu_options[] = {
        "0 - Close the program.",
        "1 - Add a friend to your list.",
        "2 - Update the number of days.",
        "3 - Display the list (by names).",
        "4 - Display the list (by days)."
    };
    // The initial size of the array
    int size = 1;   
    // Create a pointer to an array of structures with your friends list
    Friend* p_friends_list = new Friend[ size ]; 
    // User selection
    int option;
    // MAIN LOOP
    do
    {
        // Display main manu
        displayTitleScreen( menu_options, sizeof( menu_options ) / sizeof( std::string ) );
        // User selection
        option = askForNumberInput( 0, sizeof( menu_options ) / sizeof( std::string ) - 1 );
        // Available options
        std::cout << (( option > 0 ) ? "\n\t" + menu_options[ option ] : "\nClosing the program...") << "\n\n";
        switch ( option )
        {
        case 1:
            // Resize the list if the last item is not empty 
            if( p_friends_list[ size - 1].name != "" )
            {
                p_friends_list = resizeFriendsList( p_friends_list, size );
            }
            // Add an entry to the list
            addFriendToList( p_friends_list, size );
            std::cout << '\n';
            break;
        case 2:
            // Update entry if list contains at least one (first)
            if( p_friends_list[ 0 ].name != "" )
            {
                updateDaysNumber( p_friends_list, size );
            } else {
                std::cout << '\t' << "There are no entries in the list yet." << '\n';
            }
            std::cout << '\n'; 
            break;
        case 3:
            // Update entry if list contains at least one (first)
            if( p_friends_list[ 0 ].name != "" )
            {
                sortFriendsListByNames( p_friends_list, size );
            } else {
                std::cout << '\t' << "There are no entries in the list yet." << '\n';
            }
            std::cout << '\n';   
            break;
        case 4:
            // Update entry if list contains at least one (first)
            if( p_friends_list[ 0 ].name != "" )
            {
                sortFriendsListByDays( p_friends_list, size );
            } else {
                std::cout << '\t' << "There are no entries in the list yet." << '\n';
            }
            std::cout << '\n'; 
            break;
        default:
            break;
        }   
    } while( option != 0 );
    // Free up memory
    delete[] p_friends_list;
    // Close the program successfully
    return 0;
} 

// ------------------------------------------------------------------------------------

void displayTitleScreen( std::string menu_options[], int size )
{
    std::cout << '\n' << "*** LAST CONVERSATIONS ***" << '\n' << '\n';
    std::cout << "The program allows you to save a user's friends ";
    std::cout << "along with the number of days they last talked." << '\n' << '\n';
    for( int i = 0; i < size; i++ )
    {
        std::cout << menu_options[ i ] << '\n';
    }
    std::cout << '\n';
}

Friend* resizeFriendsList( Friend* p_friends_list, int& size )
{
    // Double the size of the array
    size *= 2;
    // Create a new array with a defined size
    Friend* p_friends_list_resize = new Friend[ size ];
    // Append the elements of the smaller array to the new, larger array
    for( size_t i = 0; i < size / 2; ++i )
    {
        p_friends_list_resize[ i ] = p_friends_list[ i ];
    }
    // Delete a smaller array
    delete[] p_friends_list;
    // Return a larger array
    return p_friends_list_resize;
}

void addFriendToList( Friend* p_friends_list, int& size )
{
    std::cin.ignore();
    // Find the first occurrence of an empty space in the list
    for( size_t i = 0; i < size; i++ )
    {
        if( p_friends_list[ i ].name == "" )
        {
            // Ask for the name
            std::string name_input;
            do
            {
                std::cout << '\t' << "Enter your friend's name: ";
                getline( std::cin, name_input );
            } while ( name_input == "" );
            p_friends_list[ i ].name = name_input;
            // Ask for the number of days
            int days_input;
            do
            {
                std::cout << '\t' << "Number of days you last talked: ";
                std::cin >> days_input;
            } while ( days_input < 0 );
            p_friends_list[ i ].days = days_input;
            break;
        }
    } 
}

void displayFriendsList( Friend* p_friends_list, int& size )
{
    std::cout << '\t' << "NAME / DAYS" << '\n';
    std::cout << '\t' << std::string( 24, '-' ) << '\n';
    for( size_t i = 0; i < size; i++ )
    {
        if( p_friends_list[ i ].name != "" )
        {
            std::cout << '\t' << p_friends_list[ i ].name << " / " << p_friends_list[ i ].days << '\n';
        }
    }
}

int askForNumberInput( int start, int stop )
{
    int choice;
    do
    {
        std::cout << "Your choice ( " << start << " - " << stop << " ): ";
        std::cin >> choice;
    } while ( choice < start || choice > stop );
    return choice;
}

void updateDaysNumber( Friend* p_friend_list, int& size )
{
    // Ask the user for their friend's name to update
    std::string name_input;
    std::cin.ignore();
    do
    {
        std::cout << '\t' << "Enter your friend's name: ";
        getline( std::cin, name_input );
    } while ( name_input == "" );
    // Check if your friend is on your list
    bool isOnList = false;
    for( size_t i = 0; i < size; i++ )
    {
        if( p_friend_list[ i ].name == name_input ) {
            int days_input;
            do
            {
                std::cout << '\t' << "Number of days you last talked: ";
                std::cin >> days_input;
            } while ( days_input < 0 );
            p_friend_list[ i ].days = days_input;
            isOnList = true;
            break;
        }
    }
    // If the specified friend is not on the list, print the appropriate message
    if ( !isOnList )
    {
        std::cout << '\t' << "The friend's name you entered is not listed." << '\n';
    }
} 

void sortFriendsListByDays( Friend* p_friend_list, int& size )
{
    // Create a copy of the friends list
    Friend* p_friend_list_cp = new Friend[ size ];
    for( size_t i = 0; i < size; i++ )
    {
        p_friend_list_cp[ i ] = p_friend_list[ i ]; 
    }
    // Create a temporary variable for sorting purposes
    Friend tmp;
    // Sort a copy of the friends list
    if( size > 1 ) {    
        for( size_t i = 1; i < size; i++ )
        {
            for( size_t j = i; j > 0; j-- )
            {
                if( p_friend_list_cp[ j - 1 ].days > p_friend_list_cp[ j ].days )
                {
                    tmp = p_friend_list_cp[ j - 1 ];
                    p_friend_list_cp[ j - 1 ] = p_friend_list_cp[ j ];
                    p_friend_list_cp[ j ] = tmp;
                } else {
                    break;
                }
            }
        }
    }
    // Display a copy of the friends list
    displayFriendsList( p_friend_list_cp, size );
    // Delete a copy of the friends list
    delete[] p_friend_list_cp;
}

void sortFriendsListByNames( Friend* p_friend_list, int& size )
{
    // Create a copy of the friends list
    Friend* p_friend_list_cp = new Friend[ size ];
    for( size_t i = 0; i < size; i++ )
    {
        p_friend_list_cp[ i ] = p_friend_list[ i ]; 
    }
    // Create a temporary variable for sorting purposes
    Friend tmp;
    int letter_1, letter_2;
    // Sort a copy of the friends list
    if( size > 1 ) {    
        for( size_t i = 1; i < size; i++ )
        {
            for( size_t j = i; j > 0; j-- )
            {
                // Typecasting of char (lowercase) to int (ascii)
                letter_1 = tolower(p_friend_list_cp[ j - 1 ].name[ 0 ]);
                letter_2 = tolower(p_friend_list_cp[ j ].name[ 0 ]);
                if(  letter_1 > letter_2 )
                {
                    tmp = p_friend_list_cp[ j - 1 ];
                    p_friend_list_cp[ j - 1 ] = p_friend_list_cp[ j ];
                    p_friend_list_cp[ j ] = tmp;
                } else {
                    break;
                }
            }
        }
    }
    // Display a copy of the friends list
    displayFriendsList( p_friend_list_cp, size );
    // Delete a copy of the friends list
    delete[] p_friend_list_cp;
}