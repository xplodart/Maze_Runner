#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player : public Entity {
public:
    Player(int x, int y, int width, int height);

    void moveDirection(char direction);
    void resetPosition();
    void move() override;

    int getHealth() const;
    void decreaseHealth();
    void resetHealth();

private:
    int health;
    int initialX;
    int initialY;
};

#endif
