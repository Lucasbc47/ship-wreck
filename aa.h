// aa.h
#ifndef AA_H
#define AA_H

#include "raylib.h"

class PlayerObj {
public:
    Texture2D texture;
    PlayerObj(int x, int y, int speed);
    ImgRender();

    void Draw();
    void Movement();

private:
    int x;
    int y;
    int speed;
};

#endif
