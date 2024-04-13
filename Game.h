#ifndef GAME_H
#define GAME_H

#include <vector>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include "Player.h"
#include "Goal.h"
#include "Obstacle.h"
#include "Hunter.h"

class Game {
private:
    int level;
    const int WIDTH;
    const int HEIGHT;
    std::vector<std::vector<char>> grid;
    Player player;
    Goal goal;
    std::vector<Obstacle> obstacles;
    std::vector<Hunter> hunters;

public:
    Game(int width, int height);
    void initializeLevel();
    void displayGrid() const;
    void movePlayer(char direction);
};

#endif