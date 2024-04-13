#ifndef ENTITY_H
#define ENTITY_H

class Entity {
public:
    Entity(char symbol, int x, int y, int width, int height);
    virtual ~Entity();

    char getSymbol() const;
    int getX() const;
    int getY() const;

    virtual void move() = 0;

protected:
    char symbol;
    int x, y;
    const int WIDTH;
    const int HEIGHT;
};

#endif
