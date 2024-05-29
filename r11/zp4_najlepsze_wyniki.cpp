#include <iostream>

using namespace std;

struct PlayerScores
{
    string player_name = "";
    int player_scores_size = 5;
    int player_scores[5] = {0, 0, 0, 0, 0};
};

void showMainMenu(string menu_options[], int size_menu);
int getUserInput(string msg, int begin, int end);
void showAllScores(PlayerScores players_best_scores[], int size_all_scores);
void showPlayerList(PlayerScores players_best_scores[], int size_all_scores);
PlayerScores getPlayerTopScore(PlayerScores players_best_score[], int size_all_scores, string player_name);

int main()
{
    PlayerScores players_best_scores[5];
    
    int size_all_scores = 5;
    int size_menu = 7;
    int input_menu;
    int entry_to_update;            // option 1
    string input_player_name;       // option 1, 2 and 3
    bool player_exists;             // option 1
    int lowest_score;               // option 1
    int lowest_score_idx;           // option 1
    int input_score;                // option 1  
    PlayerScores player_top_score;  // option 3 and 4
    
    string menu_options[7] = {
        "0. Close the program.\n",
        "1. Add score.\n",
        "2. Remove score.\n",
        "3. Show player's top score.\n",
        "4. Show top scores.\n",
        "5. Show all scores.\n",
        "6. Show player list.\n",
    };
    
    do {
        showMainMenu(menu_options, size_menu);
        input_menu = getUserInput("Your choice (0-6): ", 0, 6);
        cout << ((input_menu == 0) ? "\nClosing the program...\n" : "\n\t" + menu_options[input_menu]) << "\n";
        
        switch (input_menu)
        {
            // 1. Add score
            case 1:
                // Ask for the player's name or nickname
                cout << "\tEnter player's name or nickname: ";
                cin.ignore();
                getline(cin, input_player_name);
                entry_to_update = -1;
                player_exists = false;
                // Check if there is a player or any empty space and return the appropriate index
                for (int i = 0; i < size_all_scores; i++) {
                    if (players_best_scores[i].player_name == input_player_name) {
                        entry_to_update = i;
                        player_exists = true;
                        break;
                    } else if (players_best_scores[i].player_name == "" && entry_to_update < 0) {
                        entry_to_update = i;
                    }
                }
                // When a player does not exist and there are no empty spaces, send an appropriate message
                if (!player_exists && entry_to_update < 0) {
                    cout << "\n\tThe score list is full. Delete some entries to add new ones.\n";
                } else {                
                    // Add a new player or overwrite their name
                    players_best_scores[entry_to_update].player_name = input_player_name;
                    // Add a new score
                    cout << "\tEnter player's score: ";
                    cin >> input_score;
                    // Find a player's lowest score
                    lowest_score_idx = 0;
                    for (int i = 1; i < players_best_scores[entry_to_update].player_scores_size; i++) {
                        if (players_best_scores[entry_to_update].player_scores[i] < 
                            players_best_scores[entry_to_update].player_scores[lowest_score_idx]) {
                            lowest_score_idx = i;
                        }
                    }
                    // Update the player's score list if the given value is not lower than the remaining scores
                    lowest_score = players_best_scores[entry_to_update].player_scores[lowest_score_idx];
                    if (input_score > lowest_score) {
                        players_best_scores[entry_to_update].player_scores[lowest_score_idx] = input_score;
                        cout << "\n\tThe update was successful.\n";
                    } else {
                        cout << "\n\tThe given value is lower than the player's other scores.\n";
                    }
                }
                cout << "\n";
                break;
            // 2. Remove score
            case 2:
                // Ask for the player's name or nickname
                cout << "\tEnter player's name or nickname: ";
                cin.ignore();
                getline(cin, input_player_name);
                // If the player is on the list, remove the entry
                for (int i = 0; i < size_all_scores; i++) {
                    if (players_best_scores[i].player_name == input_player_name) {
                        players_best_scores[i].player_name = "";
                        for (int j = 0; j < players_best_scores[i].player_scores_size; j++) {
                            players_best_scores[i].player_scores[j] = 0;
                        }
                        cout << "\n\tThe player has been successfully removed from the list.\n";
                        break;
                    } else if (i == size_all_scores - 1) {
                        cout << "\n\tA player with this name is not on the list.\n";
                    }
                }
                cout << "\n";
                break;
            // 3. Show player's top score
            case 3:
                // Ask for the player's name or nickname
                cout << "\tEnter player's name or nickname: ";
                cin.ignore();
                getline(cin, input_player_name);
                // Check if the player's name is on the list
                player_top_score = getPlayerTopScore(players_best_scores, size_all_scores, input_player_name);
                if (player_top_score.player_name != "") {
                    cout << "\n\t" << player_top_score.player_name << " {" << player_top_score.player_scores[0] << "}\n";
                } else {
                    cout << "\n\tA player with this name is not on the list.\n";
                }
                cout << "\n";
                break;
            // 4. Show top scores
            case 4:
                for (int i = 0; i < size_all_scores; i++) {
                    // Check if the player's name is on the list
                    player_top_score = getPlayerTopScore(players_best_scores, size_all_scores, players_best_scores[i].player_name);
                    if (player_top_score.player_name != "") {
                        cout << "\t" << player_top_score.player_name << " {" << player_top_score.player_scores[0] << "}\n";
                    } else {
                        cout << "\tN/A\n";
                    }
                }
                cout << "\n";
                break;
            // 5. Show all scores
            case 5:
                showAllScores(players_best_scores, size_all_scores);
                cout << "\n";
                break;
            // 6. Show player list
            case 6:
                showPlayerList(players_best_scores, size_all_scores);
                cout << "\n";
                break;
            default:
                break;
        }
    } while (input_menu);
    
    return 0;
}

void showMainMenu(string menu_options[], int size_menu) {
    cout << string(64, '-') << "\n";
    cout << "\t\t\tBest Gaming Scores\n";
    cout << string(64, '-') << "\n";
    cout << "\nThe program stores the 5 best scores of each of up to 5 players.\n";
    cout << "\nMain menu\n";
    for (int i = 0; i < size_menu; i++) {
        cout << menu_options[i];
    }
    cout << "\n";
}

int getUserInput(string msg, int begin, int end) {
    int choice;
    do {
        cout << msg;
        cin >> choice;
    } while (choice < begin || choice > end);
    return choice;
}

void showAllScores(PlayerScores players_best_scores[], int size_all_scores) {
    for (int i = 0; i < size_all_scores; i++) {
        if (players_best_scores[i].player_name != "") {
            cout << "\t" << players_best_scores[i].player_name << "\t {";
            for (int j = 0; j < players_best_scores[i].player_scores_size; j++) {
                cout << players_best_scores[i].player_scores[j] << ((j < players_best_scores[i].player_scores_size - 1) ? ", " : "}\n"); 
            } 
        } else {
            cout << "\tN/A\n";
        }
    }
}

void showPlayerList(PlayerScores players_best_scores[], int size_all_scores) {
    for (int i = 0; i < size_all_scores; i++) {
        cout << "\t" << ((players_best_scores[i].player_name == "") ? "N/A" : players_best_scores[i].player_name) << "\n";
    }
}

PlayerScores getPlayerTopScore(PlayerScores players_best_score[], int size_all_scores, string input_player_name) {
    PlayerScores player_top_score;
    for (int i = 0; i < size_all_scores; i++) {
        if (input_player_name != "" && input_player_name == players_best_score[i].player_name) {
            player_top_score.player_name = input_player_name;
            // Assign the player's highest score to the first position of the scoreboard
            for (int j = 0; j < players_best_score[i].player_scores_size; j++) {
                if (players_best_score[i].player_scores[j] > player_top_score.player_scores[0]) {
                    player_top_score.player_scores[0] = players_best_score[i].player_scores[j];
                }
            }
            break;
        }
    }
    return player_top_score;
}