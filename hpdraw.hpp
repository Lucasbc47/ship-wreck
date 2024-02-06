#pragma once

#include "raylib.h"

class Hp{
    public:
    Hp(int hp);
    ~Hp();
    void Draw();

    private:
    int hp;
    Texture2D hpUnitTexture;

};