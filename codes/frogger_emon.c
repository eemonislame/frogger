#include "raylib.h"
#include "raymath.h"
#include<stdlib.h>
#include<time.h>
#define bg_color (Color){144, 246, 144, 255}
#define speed 10
#define LENGTH(arr) (sizeof(arr) / sizeof((arr)[0]))


int rndmpos(int arsize, int carpos[])
{
    int rndm_indx=rand()%arsize;
    int carposx=carpos[rndm_indx];
    return carposx;
}

int main(void)
{
    float gw=1200, gh=1000;
    Texture2D frog[2],car[5];
    Vector2 roadposition = {0.0f, 500};
    Vector2 riverposition = {0, 100};
    Vector2 frogpos = {550, gh-120};
    Vector2 origin= {0,0};
    Vector2 frogspeed = {202, 200};
    float car1posx , car2posx, car3posx, car4posx, car5posx, car6posx, car7posx, car8posx;
    int i=0;
    int carpos1[4]={1200, 900, 600, 300};
    int carpos2[4]={-100, 200, 500, 800};
    srand(time(NULL));
    int arsize = LENGTH(carpos1);
    int rndm_indx, rndm_value;
    car1posx=rndmpos(arsize, carpos1);
    car2posx=rndmpos(arsize, carpos2);
    car3posx=rndmpos(arsize, carpos1);
    car4posx=rndmpos(arsize, carpos2);

    car5posx=rndmpos(arsize, carpos1);
    car6posx=rndmpos(arsize, carpos2);
    car7posx=rndmpos(arsize, carpos1);
    car8posx=rndmpos(arsize, carpos2);

    InitWindow(gw, gh, "Game");
    SetTargetFPS(60);
    frog[0] = LoadTexture("D:/project/raylib_template/asset/frog0000.png");
    frog[1] = LoadTexture("D:/project/raylib_template/asset/frog0001.png");
    car[0] = LoadTexture("D:/project/raylib_template/asset/car_1.png");
    car[1] = LoadTexture("D:/project/raylib_template/asset/car_2.png");
    car[2] = LoadTexture("D:/project/raylib_template/asset/car_3.png");
    car[3] = LoadTexture("D:/project/raylib_template/asset/truck.png");


    while (!WindowShouldClose())
    {
        car1posx-=100*GetFrameTime();
        car2posx+=100*GetFrameTime();
        car3posx-=100*GetFrameTime();
        car4posx+=100*GetFrameTime();
        car5posx-=100*GetFrameTime();
        car6posx+=100*GetFrameTime();
        car7posx-=100*GetFrameTime();
        car8posx+=100*GetFrameTime();
        

        BeginDrawing();
        ClearBackground(bg_color);
        DrawRectangle(0, roadposition.y, gw, 350, GetColor(0x202020FF));
        DrawRectangle(0, 672.5, gw, 5, GetColor(0x606060FF));
        DrawRectangle(riverposition.x, riverposition.y, gw, 350, GetColor(0x5050AAFF));
        DrawTexturePro(frog[i], (Rectangle){0,0, frog[i].width, frog[i].height},(Rectangle){frogpos.x, frogpos.y, 80, 80}, origin, 0, WHITE);
        DrawTexturePro(car[0], (Rectangle){0, 0, car[0].width, car[0].height}, (Rectangle){car1posx, 510, 100, 80}, origin, 0, WHITE);
        DrawTexturePro(car[1], (Rectangle){0, 0, car[1].width, car[1].height}, (Rectangle){car2posx, 670, 100, 80}, origin, 180, WHITE);
        DrawTexturePro(car[2], (Rectangle){0, 0, car[2].width, car[2].height}, (Rectangle){car3posx, 755, 100, 80}, origin, 180, WHITE);
        DrawTexturePro(car[3], (Rectangle){0, 0, car[3].width, car[3].height}, (Rectangle){car4posx, 835, 100, 80}, origin, 180, WHITE);

        
        DrawTexturePro(car[0], (Rectangle){0, 0, car[0].width, car[0].height}, (Rectangle){car5posx, 510, 100, 80}, origin, 0, WHITE);
        DrawTexturePro(car[1], (Rectangle){0, 0, car[1].width, car[1].height}, (Rectangle){car6posx, 670, 100, 80}, origin, 180, WHITE);
        DrawTexturePro(car[2], (Rectangle){0, 0, car[2].width, car[2].height}, (Rectangle){car7posx, 760, 100, 80}, origin, 180, WHITE);
        DrawTexturePro(car[3], (Rectangle){0, 0, car[3].width, car[3].height}, (Rectangle){car8posx, 840, 100, 80}, origin, 180, WHITE);

        

        if(IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))
        {
            i=1;
            frogpos.y-=frogspeed.y*GetFrameTime();
        }
        else
        i=0;
        if(car1posx<-100 )car1posx=1300;
        if(car2posx>=1400)car2posx=-100;
        if(car3posx<-100)car3posx=1300;
        if(car4posx>=1400)car4posx=-100;
        if(car5posx<-100 )car5posx=1300;
        if(car6posx>=1400)car6posx=-100;
        if(car7posx<-100)car7posx=1300;
        if(car8posx>=1400)car8posx=-100;
        
        EndDrawing();
    }

    

    CloseWindow();

    return 0;
}
