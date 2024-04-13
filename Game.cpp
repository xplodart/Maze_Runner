#include "Game.h"
#include <iostream>

using namespace std;

const char EMPTY = ' ';

Game::Game(int width, int height) : level(1), WIDTH(width), HEIGHT(height), player(0, 1, width, height), goal(width - 1, height - 2) {
    grid.assign(HEIGHT, vector<char>(WIDTH, EMPTY));
    srand(time(nullptr));
    initializeLevel();
}

void Game::initializeLevel() {
     // Resets player position
        player.resetPosition();


        // Initialize obstacles
        obstacles.clear();
        for (int i = 0; i < 10 * level; ++i) {
        int obstacleX, obstacleY;
        bool duplicatePosition;
    do {
        duplicatePosition = false; 
        obstacleX = rand() % WIDTH;
        obstacleY = rand() % HEIGHT;
        
        // Check if player position
        if (obstacleX == player.getX() && obstacleY == player.getY()) {
            duplicatePosition = true;
            continue; 
        }
        
        // Check if goal position
        if (obstacleX == goal.getX() && obstacleY == goal.getY()) {
            duplicatePosition = true;
            continue; 
        }
        
        // Check if obstacle position
        for (const auto& obstacle : obstacles) {
            if (obstacle.getX() == obstacleX && obstacle.getY() == obstacleY) {
                duplicatePosition = true;
                break;
            }
        }
    } while (duplicatePosition);
    
    obstacles.emplace_back(obstacleX, obstacleY);
    }

        // Initialize hunters
        hunters.clear();
        for (int i = 0; i < 5 * level; ++i) {
    int hunterX, hunterY;
    bool duplicatePosition;
    do {
        duplicatePosition = false; 
        hunterX = rand() % WIDTH;
        hunterY = rand() % HEIGHT;
        
        // Check if player position
        if (hunterX == player.getX() && hunterY == player.getY()) {
            duplicatePosition = true;
            continue; 
        }
        
        // Check if goal position
        if (hunterX == goal.getX() && hunterY == goal.getY()) {
            duplicatePosition = true;
            continue;
        }
        
        // Check if obstacle position
        for (const auto& obstacle : obstacles) {
            if (obstacle.getX() == hunterX && obstacle.getY() == hunterY) {
                duplicatePosition = true;
                break;
            }
        }
        
        // Check if hunter position
        for (const auto& otherHunter : hunters) {
            if (otherHunter.getX() == hunterX && otherHunter.getY() == hunterY) {
                duplicatePosition = true;
                break;
            }
        }
    } while (duplicatePosition);
    
    hunters.emplace_back(hunterX, hunterY, WIDTH, HEIGHT);
}
}

void Game::displayGrid() const {
    system("cls");

        cout << "--------   M A Z E   R U N N E R   --------\n";

        // Print top border
        cout << (char)219u; //top left corner
        for (int i = 0; i < (2 * WIDTH) + 1; ++i) {
            cout << (char)254u;
        }
        cout << (char)219u << endl; //top right corner


        // Left border  
        for (int i = 0; i < HEIGHT; ++i) {
            cout << (char)219u << ' ';

            for (int j = 0; j < WIDTH; ++j) {
                char symbol = EMPTY;
                if (i == player.getY() && j == player.getX()) {
                    symbol = player.getSymbol();
                } else if (i == goal.getY() && j == goal.getX()) {
                    symbol = goal.getSymbol();
                } else {
                    // Check if there's a hunter at this position
                    bool isHunter = false;
                    for (const auto &hunter : hunters) {
                        if (i == hunter.getY() && j == hunter.getX()) {
                            symbol = hunter.getSymbol();
                            isHunter = true;
                            break;
                        }
                    }
                    // If there's no hunter at this position, check for obstacles
                    if (!isHunter) {
                        for (const auto &obstacle : obstacles) {
                            if (i == obstacle.getY() && j == obstacle.getX()) {
                                symbol = obstacle.getSymbol();
                                break;
                            }
                        }
                    }
                }

                cout << symbol << ' ';
            }

            // Right border
            cout << (char)219u << endl;
        }

        // Print bottom border
        cout << (char)219u; //bottom left corner
        for (int i = 0; i < (2 * WIDTH) + 1; ++i) {
            cout << (char)254u;
        }
        cout << (char)219u << endl; // bottom right corner

        // Display game information
        cout << endl;
        cout << "Level:  " << level << "    Obstacles: " << obstacles.size() << endl;
        cout << "Health: " << player.getHealth() << "    Hunters: " << hunters.size() << endl;
}

void Game::movePlayer(char direction) {
     int newX = player.getX();
        int newY = player.getY();

        // Calculate the new position based on the direction
        switch (direction) {
            case 'w':
                newY -= 1;
                break;
            case 's':
                newY += 1;
                break;
            case 'a':
                newX -= 1;
                break;
            case 'd':
                newX += 1;
                break;
            default:
                break;
        }

        // Check if the new position is within the bounds of the maze
        if (newX >= 0 && newX < WIDTH && newY >= 0 && newY < HEIGHT) {
            // Check if the new position is not blocked by an obstacle
            bool isObstacle = false;
            for (const auto &obstacle : obstacles) {
                if (obstacle.getX() == newX && obstacle.getY() == newY) {
                    isObstacle = true;
                    break;
                }
            }

            // If the new position is not blocked by an obstacle, move the player
            if (!isObstacle) {
                player.moveDirection(direction);
            }

            // Move hunters after player movement
            for (auto &hunter : hunters) {
                hunter.move();
            }

            // Check if the player is caught by a hunter
            for (const auto &hunter : hunters) {
                if (hunter.getX() == newX && hunter.getY() == newY) {
                    cout << "------------------------------------------" << endl;
                    cout << "Ouch! You got caught by a hunter!" << endl;
                    player.decreaseHealth();

                    if (player.getHealth() == 0) {
                        cout << "Game Over! You ran out of lives." << endl;
                        exit(0);
                    } else {
                        cout << "Remaining lives: " << player.getHealth() << endl;
                        system("pause");
                    }
                }
            }
        }

        // Check if player reached the goal
        if (player.getX() == goal.getX() && player.getY() == goal.getY()) {
            int thislevel = level;
            level++;
            player.resetHealth();
            // Reset obstacles and hunters for the next level
            initializeLevel();
            displayGrid();

            cout << "------------------------------------------" << endl;
            cout << "Congratulations! You completed level " << thislevel << endl;
            cout << "Press any key to continue..." << endl;
            _getch();
        }
    }