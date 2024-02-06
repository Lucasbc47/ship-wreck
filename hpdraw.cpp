#include "raylib.h"
#include "hpdraw.hpp"
#include <iostream>

Hp::Hp(int hp) : hp(hp){
    hpUnitTexture = LoadTexture("img/hpunit.png");
}
Hp::~Hp(){
    UnloadTexture(hpUnitTexture);
}

void Hp::Draw(){
    for(int i = 0; i < hp; ++i){
        DrawTexture(hpUnitTexture, 5 + i * 9, 5, WHITE);
    }

}
