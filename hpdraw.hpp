#pragma once

#include "raylib.h"

class Hp
{
public:
    Hp(int hp);
    ~Hp();
    void Draw();
    void Reset();
    void decHp();
    void incHp();
    int getHp();

private:
    int initialHp;
    int hp;
    Texture2D hpUnitTexture;
};