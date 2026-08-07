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
    int carw=75, carh=60;

    Texture2D frog[2],car[5], log[5];
    Vector2 roadposition = {0.0f, 500};
    Vector2 riverposition = {0, 80};
    Vector2 frogpos = {550, gh-120};
    Vector2 origin= {0,0};
    Vector2 frogspeed = {202, 200};
    Vector2 center = {carw/2, carh/2};;

    float car1posx , car2posx, car3posx, car4posx, car5posx, car6posx, car7posx, car8posx, car9posx, car10posx;
    float car1posy=505, car2posy=575, car3posy=645, car4posy=715, car5posy=785;
    float log1posy=85, log2posy=155, lo3posy=225, log4posy=295, log5posy=365;
    int i=0;
    int carpos1[4]={1200, 900, 600, 300};
    int carpos2[4]={-100, 200, 500, 800};
    srand(time(NULL));
    int arsize = LENGTH(carpos1);
    int rndm_indx, rndm_value;
    double delay=.3;


    car1posx=rndmpos(arsize, carpos1);
    car2posx=rndmpos(arsize, carpos2);
    car3posx=rndmpos(arsize, carpos1);
    car4posx=rndmpos(arsize, carpos2);
    car5posx=rndmpos(arsize, carpos1);

    car6posx=rndmpos(arsize, carpos2);
    car7posx=rndmpos(arsize, carpos1);
    car8posx=rndmpos(arsize, carpos2);
    car9posx=rndmpos(arsize, carpos1);
    car10posx=rndmpos(arsize, carpos2);

    InitWindow(gw, gh, "Game");
    SetTargetFPS(60);
    frog[0] = LoadTexture("D:/project/raylib_template/asset/frog0000.png");
    frog[1] = LoadTexture("D:/project/raylib_template/asset/frog0001.png");

    car[0] = LoadTexture("D:/project/raylib_template/asset/car_1.png");
    car[1] = LoadTexture("D:/project/raylib_template/asset/car_2.png");
    car[2] = LoadTexture("D:/project/raylib_template/asset/car_3.png");
    car[3] = LoadTexture("D:/project/raylib_template/asset/truck.png");
    car[4] = LoadTexture("D:/project/raylib_template/asset/tractor.png");

    log[0] = LoadTexture(TextFormat("%sasset/log_left.png", GetApplicationDirectory()));
    log[1] = LoadTexture(TextFormat("%sasset/log_middle.png", GetApplicationDirectory()));
    log[2] = LoadTexture(TextFormat("%sasset/log_right.png", GetApplicationDirectory()));



    while (!WindowShouldClose())
    {
        car1posx-=100*GetFrameTime();
        car2posx+=100*GetFrameTime();
        car3posx-=100*GetFrameTime();
        car4posx+=100*GetFrameTime();
        car5posx-=100*GetFrameTime();

        car6posx-=100*GetFrameTime();
        car7posx+=100*GetFrameTime();
        car8posx-=100*GetFrameTime();
        car9posx+=100*GetFrameTime();
        car10posx-=100*GetFrameTime();

        BeginDrawing();
        ClearBackground(bg_color);
        DrawRectangle(0, roadposition.y, gw, 350, GetColor(0x202020FF));
        DrawRectangle(riverposition.x, riverposition.y, gw, 350, GetColor(0x5050AAFF));

        DrawTexturePro(frog[i], (Rectangle){0, 0, frog[i].width, frog[i].height}, (Rectangle){frogpos.x, frogpos.y, 60, 60}, center, 0, WHITE);
        DrawTexturePro(car[0], (Rectangle){0, 0, car[0].width, car[0].height}, (Rectangle){car1posx+center.x, car1posy+center.y, carw, carh}, center, 0, WHITE);
        DrawTexturePro(car[1], (Rectangle){0, 0, car[1].width, car[1].height}, (Rectangle){car2posx+center.x, car2posy+center.y, carw, carh}, center, 180, WHITE);
        DrawTexturePro(car[2], (Rectangle){0, 0, car[2].width, car[2].height}, (Rectangle){car3posx+center.x, car3posy+center.y, carw, carh}, center, 180, WHITE);
        DrawTexturePro(car[3], (Rectangle){0, 0, car[3].width, car[3].height}, (Rectangle){car4posx+center.x, car4posy+center.y, carw, carh}, center, 180, WHITE);
        DrawTexturePro(car[4], (Rectangle){0, 0, car[4].width, car[4].height}, (Rectangle){car5posx+center.x, car5posy+center.y, carw, carh}, center, 180, WHITE);
        
        DrawTexturePro(car[0], (Rectangle){0, 0, car[0].width, car[0].height}, (Rectangle){car6posx+center.x, car1posy+center.y, carw, carh}, center, 0, WHITE);
        DrawTexturePro(car[1], (Rectangle){0, 0, car[1].width, car[1].height}, (Rectangle){car7posx+center.x, car2posy+center.y, carw, carh}, center, 180, WHITE);
        DrawTexturePro(car[2], (Rectangle){0, 0, car[2].width, car[2].height}, (Rectangle){car8posx+center.x, car3posy+center.y, carw, carh}, center, 180, WHITE);
        DrawTexturePro(car[3], (Rectangle){0, 0, car[3].width, car[3].height}, (Rectangle){car9posx+center.x, car4posy+center.y, carw, carh}, center, 180, WHITE);
        DrawTexturePro(car[4], (Rectangle){0, 0, car[4].width, car[4].height}, (Rectangle){car10posx+center.x, car5posy+center.y, carw, carh}, center, 180, WHITE);

        
        DrawTexturePro(log[0], (Rectangle){0, 0, log[0].width, log[0].height}, (Rectangle){car1posx+center.x, log5posy+center.y, carw, carh}, center, 180, WHITE);
        DrawTexturePro(log[1], (Rectangle){0, 0, log[1].width, log[1].height}, (Rectangle){car1posx+center.x-carw, log5posy+center.y, carw, carh}, center, 180, WHITE);
        DrawTexturePro(log[2], (Rectangle){0, 0, log[2].width, log[2].height}, (Rectangle){car1posx+center.x-carw*2, log5posy+center.y, carw, carh}, center, 180, WHITE);


        DrawTexturePro(log[0], (Rectangle){0, 0, log[0].width, log[0].height}, (Rectangle){car6posx+center.x, log5posy+center.y, carw, carh}, center, 180, WHITE);
        DrawTexturePro(log[1], (Rectangle){0, 0, log[1].width, log[1].height}, (Rectangle){car6posx+center.x-carw, log5posy+center.y, carw, carh}, center, 180, WHITE);
        DrawTexturePro(log[2], (Rectangle){0, 0, log[2].width, log[2].height}, (Rectangle){car6posx+center.x-carw*2, log5posy+center.y, carw, carh}, center, 180, WHITE);

        DrawTexturePro(log[0], (Rectangle){0, 0, log[0].width, log[0].height}, (Rectangle){car2posx+center.x-carw, log2posy+center.y, carw, carh}, center, 0, WHITE);
        DrawTexturePro(log[2], (Rectangle){0, 0, log[2].width, log[2].height}, (Rectangle){car2posx+center.x, log2posy+center.y, carw, carh}, center, 0, WHITE);

        DrawTexturePro(log[0], (Rectangle){0, 0, log[0].width, log[0].height}, (Rectangle){car7posx+center.x-carw, log2posy+center.y, carw, carh}, center, 0, WHITE);
        DrawTexturePro(log[1], (Rectangle){0, 0, log[1].width, log[1].height}, (Rectangle){car7posx+center.x, log2posy+center.y, carw, carh}, center, 0, WHITE);
        DrawTexturePro(log[2], (Rectangle){0, 0, log[2].width, log[2].height}, (Rectangle){car7posx+center.x+carw, log2posy+center.y, carw, carh}, center, 0, WHITE);


        delay-=GetFrameTime();
        if((IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) && (delay<=0))
        {
            i=1;
            frogpos.y-=70;
            delay=.3;
        }
        else
        i=0;

        if(car1posx<-100 )car1posx=1500;
        if(car2posx>=1400)car2posx=-100;
        if(car3posx<-100)car3posx=1500;
        if(car4posx>=1400)car4posx=-100;
        if(car5posx<-100 )car5posx=1500;

        if(car6posx<-100 )car6posx=1500;
        if(car7posx>=1400)car7posx=-100;
        if(car8posx<-100)car8posx=1500;
        if(car9posx>=1400)car9posx=-100;
        if(car10posx<-100 )car10posx=1500;

        EndDrawing();
    }

    

    CloseWindow();

    return 0;
}
