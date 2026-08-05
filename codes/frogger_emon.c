/* it's for me */
#include "raylib.h"
#include "raymath.h"
#define bg_color (Color){144, 246, 144, 255}
#define speed 10
#define LENGTH(arr) (sizeof(arr) / sizeof((arr)[0]))


int main(void)
{
    float gw=1200, gh=1000;
    Texture2D frog[2],car[5];
    Vector2 roadposition = {0.0f, 500};
    Vector2 riverposition = {0, 100};
    Vector2 frogpos = {550, gh-120};
    Vector2 origin= {0,0};
    Vector2 frogspeed = {202, 200};
    float car1posx = 1200, car2posx=-100;
    int i=0;

    InitWindow(gw, gh, "Game");
    SetTargetFPS(60);
    frog[0] = LoadTexture("D:/project/raylib_template/asset/frog0000.png");
    frog[1] = LoadTexture("D:/project/raylib_template/asset/frog0001.png");
    car[0] = LoadTexture("D:/project/raylib_template/asset/car_1.png");
    car[1] = LoadTexture("D:/project/raylib_template/asset/car_2.png");

    while (!WindowShouldClose())
    {
        car1posx-=100*GetFrameTime();
        car2posx+=100*GetFrameTime();

        BeginDrawing();
        ClearBackground(bg_color);
        DrawRectangle(0, roadposition.y, gw, 350, GetColor(0x454545FF));
        DrawRectangle(riverposition.x, riverposition.y, gw, 350, GetColor(0x5050AAFF));
        DrawTexturePro(frog[i], (Rectangle){0,0, frog[i].width, frog[i].height},(Rectangle){frogpos.x, frogpos.y, 80, 80}, origin, 0, WHITE);
        DrawTexturePro(car[0], (Rectangle){0, 0, car[0].width, car[0].height}, (Rectangle){car1posx, 510, 100, 80}, origin, 0, WHITE);
        DrawTexturePro(car[1], (Rectangle){0, 0, car[1].width, car[1].height}, (Rectangle){car2posx, 600, 100, 80}, origin, 0, WHITE);
        

        if(IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))
        {
            i=1;
            frogpos.y-=frogspeed.y*GetFrameTime();
        }
        else
        i=0;
        if(car1posx<-100)
        car1posx=1200;
        EndDrawing();
    }

    

    CloseWindow();

    return 0;
}
