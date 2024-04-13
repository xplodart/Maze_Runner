#ifndef HUNTER_H
#define HUNTER_H

#include "Entity.h"
#include <cstdlib>

const char HUNTER = 'X';

class Hunter : public Entity {
public:
    Hunter(int x, int y, int width, int height);

    void move() override;
    
private:
    char direction;
};

#endif