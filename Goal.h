#ifndef GOAL_H
#define GOAL_H

#include "Entity.h"

class Goal : public Entity {
public:
    Goal(int x, int y);

    void move() override;
};

#endif
