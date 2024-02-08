#include "raylib.h"
#include "spaceship.hpp"
#include "asteroids.hpp"
#include "hpdraw.hpp"

#include <iostream>
#include <cmath>
#include <vector>

#define TITLE "Ship Wreck"
#define HEIGHT 600
#define WIDTH 800

// - pontos adicionar ao destroir um asteroid
#define PONTOC 50

void startGame();
bool CheckCollisionSprite(Texture2D sprite1, Vector2 pos1, Texture2D sprite2, Vector2 pos2);

int main(void)
{
    startGame();
    return 0;
}

void startGame()
{
    int pontuacao = 0;

    bool fim_jogo = false;
    bool jogo_comecou = false;
    bool mostrar_texto = true;
    bool pode_atirar = true;

    float fundo_pos_y = 0;
    float fundo_velocidade = 3.0f;
    float tempo_passado = 0;
    float tempo_texto = 0.0f;

    const float intervalo_piscar = 0.5f;

    InitWindow(WIDTH, HEIGHT, TITLE);
    InitAudioDevice();
    SetTargetFPS(60);

    // musicas
    Music musica_fundo = LoadMusicStream("./sound/tema.ogg");
    // imagens
    Image img_projetil = LoadImage("./img/bullet.png");
    Image img_fundo = LoadImage("./img/background.png");
    // texturas
    Texture2D img_titulo_tex = LoadTexture("./img/Shipwrecktitle.png");
    Texture2D img_projetil_tex = LoadTextureFromImage(img_projetil);
    // sons
    Sound som_dano = LoadSound("./sound/damage.wav");
    Sound som_lazer = LoadSound("./sound/lazer.wav");
    Sound som_colisao = LoadSound("./sound/asteroid_explode.mp3");

    ImageResize(&img_fundo, WIDTH, HEIGHT);
    Texture2D img_fundo_tex = LoadTextureFromImage(img_fundo);
    UnloadImage(img_fundo);
    UnloadImage(img_projetil);

    Hp hp(5);
    Ship ship(400, 400, 2, 0);
    std::vector<Shoot> municao(100);

    InitAsteroids();

    while (!WindowShouldClose())
    {

        if (IsKeyPressed(KEY_F))
        {
            ToggleFullscreen();
        }

        tempo_texto += GetFrameTime();

        if (tempo_texto >= intervalo_piscar)
        {
            mostrar_texto = !mostrar_texto;
            tempo_texto = 0.0f;
        }

        UpdateMusicStream(musica_fundo);
        PlayMusicStream(musica_fundo);
        BeginDrawing();
        ClearBackground(RAYWHITE);

        fundo_pos_y += fundo_velocidade;

        if (fundo_pos_y >= HEIGHT)
            fundo_pos_y = 0;

        DrawTextureEx(img_fundo_tex, {0, fundo_pos_y}, 0.0f, 1.0f, WHITE);
        DrawTextureEx(img_fundo_tex, {0, fundo_pos_y - HEIGHT}, 0.0f, 1.0f, WHITE);

        if (jogo_comecou && !fim_jogo)
        {
            UpdateAsteroids();
            DrawAsteroids();

            float frameTime = GetFrameTime();
            tempo_passado += frameTime;
            DrawText(("Score: " + std::to_string(pontuacao)).c_str(), 10, 37, 20, LIGHTGRAY);

            if (IsKeyDown(KEY_SPACE) && pode_atirar)
            {
                pode_atirar = false;
                for (auto &capsula : municao)
                {
                    if (!capsula.active)
                    {
                        capsula.active = true;
                        Vector2 correctPos = ship.GetPosition();
                        correctPos.x -= 18;
                        correctPos.y -= 60;
                        capsula.position = correctPos;
                        PlaySound(som_lazer);
                        break;
                    }
                }
            }

            if (tempo_passado >= 0.1)
            {
                pontuacao++;
                pode_atirar = true;
                tempo_passado = 0;
            }

            for (auto &capsula : municao)
            {
                capsula.update();
                if (capsula.active)
                {
                    DrawTextureV(img_projetil_tex, capsula.position, WHITE);

                    // Check collision with asteroids
                    for (int i = 0; i < MAX_ASTEROIDS; i++)
                    {
                        if (!asteroids[i].hasCollided && CheckCollisionSprite(img_projetil_tex, capsula.position, asteroids[i].texture, asteroids[i].position))
                        {
                            asteroids[i].hasCollided = true;
                            asteroids[i].position = {-1000, -1000};
                            capsula.active = false;
                            PlaySound(som_colisao);
                            pontuacao += PONTOC;
                            break;
                        }
                    }
                }
            }

            hp.Draw();
            ship.Movement();
            ship.Draw();

            for (int i = 0; i < MAX_ASTEROIDS; i++)
            {
                if (!asteroids[i].hasCollided && CheckCollisionSprite(ship.GetTexture(), ship.GetPosition(), asteroids[i].texture, asteroids[i].position))
                {
                    PlaySound(som_dano);
                    hp.decHp();

                    if (hp.getHp() <= 0)
                    {
                        fim_jogo = true;
                        hp.Reset();
                        pontuacao = 0;
                    }
                    asteroids[i].hasCollided = true;
                }
            }
        }

        for (int i = 0; i < MAX_ASTEROIDS; i++)
        {
            if (asteroids[i].hasCollided)
            {
                asteroids[i].position = {-1000, -1000};
                asteroids[i].hasCollided = false;
            }
        }

        if (fim_jogo)
        {
            DrawText("GAME OVER!", GetScreenWidth() / 2 - MeasureText("GAME OVER!", 20) / 2, GetScreenHeight() / 2 - 50, 20, RED);
            if (IsKeyPressed(KEY_ENTER))
            {
                fim_jogo = false;
                jogo_comecou = false;
                ship.Reset();
                hp.Reset();
                ResetAsteroids();
            }
        }

        else if (!jogo_comecou)
        {
            int posX = GetScreenWidth() / 2 - img_titulo_tex.width / 2;
            int posY = GetScreenHeight() / 2 - 50 - img_titulo_tex.height / 2;

            DrawTexture(img_titulo_tex, posX, posY, WHITE);
            if (mostrar_texto)
            {
                DrawText("PRESS [ENTER]! ", GetScreenWidth() / 2 - MeasureText("PRESS [ENTER]! ", 20) / 2, posY + img_titulo_tex.height + 8, 20, GRAY);
            }
            if (IsKeyPressed(KEY_ENTER))
            {
                jogo_comecou = true;
            }
        }
        EndDrawing();
    }

    UnloadTexture(img_fundo_tex);
    UnloadTexture(img_titulo_tex);

    UnloadSound(som_dano);
    UnloadSound(som_lazer);
    UnloadSound(som_colisao);
    UnloadMusicStream(musica_fundo);
    CloseAudioDevice();

    CloseWindow();
}

bool CheckCollisionSprite(Texture2D sprite1, Vector2 pos1, Texture2D sprite2, Vector2 pos2)
{
    // Cria 2 retângulos delimitadores com propiedades do sprite.
    Rectangle rect1 = {pos1.x, pos1.y, static_cast<float>(sprite1.width), static_cast<float>(sprite1.height)};
    Rectangle rect2 = {pos2.x, pos2.y, static_cast<float>(sprite2.width), static_cast<float>(sprite2.height)};

    // Verificar intersecção de retângulos (colisão)
    return CheckCollisionRecs(rect1, rect2);
}