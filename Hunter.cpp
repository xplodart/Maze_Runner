#include "Hunter.h"

Hunter::Hunter(int x, int y, int width, int height) : Entity(HUNTER, x, y, width, height) {
    int randomDirection = rand() % 4;
    switch (randomDirection) {
        case 0:
            direction = 'd';
            break;
        case 1:
            direction = 'a';
            break;
        case 2:
            direction = 's';
            break;
        case 3:
            direction = 'w';
            break;
    }
}

void Hunter::move() {
     switch (direction) {
            case 'd':
                if (x < WIDTH - 1)
                    x++;
                else {
                    x = WIDTH - 2;
                    direction = 'a';
                }
                break;
            case 'a':
                if (x > 0)
                    x--;
                else {
                    x = 1;
                    direction = 'd';
                }
                break;
            case 's':
                if (y < HEIGHT - 1)
                    y++;
                else {
                    y = HEIGHT - 2;
                    direction = 'w';
                }
                break;
            case 'w':
                if (y > 0)
                    y--;
                else {
                    y = 1;
                    direction = 's';
                }
                break;
            default:
                break;
        }
}