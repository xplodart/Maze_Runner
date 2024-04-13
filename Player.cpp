#include "Player.h"

Player::Player(int x, int y, int width, int height) : Entity('O', x, y, width, height), health(5), initialX(x), initialY(y) {}

    void Player::moveDirection(char direction) {
        switch (direction) {
            case 'w':
                if (y > 0)
                    y--;
                break;
            case 's':
                if (y < HEIGHT - 1)
                    y++;
                break;
            case 'a':
                if (x > 0)
                    x--;
                break;
            case 'd':
                if (x < WIDTH - 1)
                    x++;
                break;
            default:
                break;
        }
    }

    void Player::resetPosition()  {
        x = initialX;
        y = initialY;
    }

    void Player::move() {}

    int Player::getHealth () const { return health; }

    void Player::decreaseHealth () {
        health--;
    }

    void Player::resetHealth() {
        health = 5;
    }