#include <iostream>
#include "Entity.h"
#include "Player.h"
#include "Obstacle.h"
#include "Goal.h"
#include "Hunter.h"
#include "Game.h"

int main() {
    std::cout << "|||||||||||||||||||||||||||||||||||\n";
    std::cout << std::endl;
    std::cout << "----   M A Z E   R U N N E R   ----\n";
    std::cout << std::endl;
    std::cout << "   Instructions:" << std::endl;
    std::cout << "   Use the following keys to move:" << std::endl;
    std::cout << "   W - Move up" << std::endl;
    std::cout << "   A - Move left" << std::endl;
    std::cout << "   S - Move down" << std::endl;
    std::cout << "   D - Move right" << std::endl;
    std::cout << "----------------------------------" << std::endl;
    std::cout << "   Player symbol - O" << std::endl;
    std::cout << "   Finish symbol - Z" << std::endl;
    std::cout << std::endl;
    std::cout << "   Objective: Reach the 'Z'\n   to advance to the next level." << std::endl;
    std::cout << "----------------------------------" << std::endl;
    std::cout << "   Press 'q' to quit the game." << std::endl;
    std::cout << std::endl;
    std::cout << "   Press any key to start...";
    _getch();

    // Create a game with initial parameters
    Game game(20, 20);

    while (true) {
        game.displayGrid();
        char direction = _getch();

        if (direction == 'q') {
            std::cout << "Exiting..." << std::endl;
            break;
        }

        game.movePlayer(direction);
    }

    return 0;
}
