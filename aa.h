// aa.h
#ifndef AA_H
#define AA_H

#include "raylib.h"

class PlayerObj {
public:
    PlayerObj(int x, int y, int speed);
    ~PlayerObj(); // Declare the destructor
    void Draw();
    void Movement();

private:
    int x;
    int y;
    int speed;
    Texture2D playerTexture; 
};

#endif
