#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Spaceship
{
    int x;
    int y;
    bool is_out_of_range;
};

void displaySpaceshipsPositions(Spaceship spaceships[], int size) {
    cout << "\n\t*** POSITIONS OF THE SPACESHIPS (x, y) ***\n";
    for (int i = 0; i < size; i++) {
        cout << "\tSpaceship " << i << ": ";
        if (spaceships[i].is_out_of_range) {
            cout << "/err/ OUT OF RANGE /err/\n";
        } else {
            cout << "(" << spaceships[i].x << ", " << spaceships[i].y << ")\n";
        }
    }
}

Spaceship updateSpaceshipPosition(Spaceship spaceship, int screen_width, int screen_height) {
    spaceship.x = (rand() % 1280) + 1;
    spaceship.y = (rand() % 960) + 1;
    spaceship.is_out_of_range = (spaceship.x > screen_width || spaceship.y > screen_height) ? true : false;
    return spaceship;
}

int main()
{  
    srand(time(NULL));

    int screen_width = 1024;
    int screen_height = 768;
    int size = 5;
    int spaceships_out_of_range;
    Spaceship spaceships[5];

    // Assign random x and y coordinates to each spaceship
    for (int i = 0; i < size; i++) {
        spaceships[i].x = (rand() % screen_width) + 1;
        spaceships[i].y = (rand() % screen_height) + 1;
        spaceships[i].is_out_of_range = false;
    }

    // Main loop
    do {
        displaySpaceshipsPositions(spaceships, size); 

        spaceships_out_of_range = 0;  

        for (int i = 0; i < size; i++)
            if (spaceships[i].is_out_of_range)
                spaceships_out_of_range++;
            else
                spaceships[i] = updateSpaceshipPosition(spaceships[i], screen_width, screen_height);
    } while (spaceships_out_of_range < 5);

    return 0;
}