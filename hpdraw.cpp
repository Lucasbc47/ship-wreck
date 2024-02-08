#include "raylib.h"
#include "hpdraw.hpp"
#include <iostream>

Hp::Hp(int hp) : hp(hp)
{
    hpUnitTexture = LoadTexture("img/hpunit.png");
    initialHp = hp;
}
Hp::~Hp()
{
    UnloadTexture(hpUnitTexture);
}

void Hp::Reset()
{
    hp = initialHp;
}

void Hp::Draw()
{
    for (int i = 0; i < hp; ++i)
    {
        DrawTexture(hpUnitTexture, 5 + i * 9, 5, WHITE);
    }
}

void Hp::decHp()
{
    hp -= 1;
}

void Hp::incHp()
{
    hp += 1;
}

int Hp::getHp()
{
    return hp;
}