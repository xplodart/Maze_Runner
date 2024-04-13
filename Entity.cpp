#include "Entity.h"

Entity::Entity(char symbol, int x, int y, int width, int height) : symbol(symbol), x(x), y(y), WIDTH(width), HEIGHT(height) {}

Entity::~Entity() {}

char Entity::getSymbol() const {
    return symbol;
}

int Entity::getX() const {
    return x;
}

int Entity::getY() const {
    return y;
}
