// hpdraw.hpp
#pragma once
#include "raylib.h"

class Hp
{
public:
    Hp(int hp);     // construtor
    ~Hp();          // desconstrutor 
    
    void Draw();    // desenha as unidades de vida
    void Reset();   // retorna ao valor padrao do HP
    
    void decHp();   // decrementa HP
    void incHp();   // incrementa HP
    int getHp();    // retorna HP

private:
    int initialHp;          // HP padrao
    int hp;                 // HP in-game
    Texture2D hpUnitTexture; // textura unidade do HP
};