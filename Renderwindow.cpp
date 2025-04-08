#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "Renderwindow.h"
#include <iostream>
#include <vector>
#include "graphic.h"
#include <string>
using namespace std;



RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h)\
  :window(NULL),renderer(NULL) //tao bien check loi
{

    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,p_w,p_h, SDL_WINDOW_SHOWN);
    //tao cua so
      if(window == NULL)
      {
          cout<<"Window failed to init. Error: "<<SDL_GetError()<<'\n';
      }
    renderer = SDL_CreateRenderer(window, -1,SDL_RENDERER_ACCELERATED);//SDL_RENDER_ACCELERATED: neu co card do hoa thi dung
        //ket xuat vao window


        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;



}
        if (TTF_Init() == -1) {
        std::cerr << "TTF_Init Error: " << TTF_GetError() << std::endl;

       }
}

void RenderWindow::Text(int Points)
{
string score;
    if(Points<50) score= "Score: "+ to_string(Points)+"/50";
         else score="Score: "+ to_string(Points)+"/50"+"  EAT THE LEVIATHAN!";
    TTF_Font* font = TTF_OpenFont("font/SVN-Cintra.otf", 24);

    SDL_Color textColor = {255, 255, 255, 255};

    SDL_Surface* textSurface = TTF_RenderText_Solid(font, score.c_str(), textColor);

    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

    SDL_Rect textRect = {100, 50, 0, 0};

    SDL_QueryTexture(textTexture, NULL, NULL, &textRect.w, &textRect.h);

    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);



}

void RenderWindow::Textend(int Points)
{

    string score= "Score: "+ to_string(Points);

    TTF_Font* font = TTF_OpenFont("font/SVN-Cintra.otf", 40);

    SDL_Color textColor = {255, 255, 255, 255};

    SDL_Surface* textSurface = TTF_RenderText_Solid(font, score.c_str(), textColor);

    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

    SDL_Rect textRect = {520, 360, 0, 0};

    SDL_QueryTexture(textTexture, NULL, NULL, &textRect.w, &textRect.h);

    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);


}


SDL_Texture* RenderWindow::loadTexture(const char* p_filePath)//tra ve ket cau
{
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer, p_filePath);

    if(texture == NULL)
        cout<< "Failed to load texture. Error: "<<SDL_GetError() <<'\n';
    return texture;

}

void RenderWindow::cleanUp()
{

    SDL_DestroyWindow(window);

}
void RenderWindow::clear()
{
    SDL_RenderClear(renderer);

}

void RenderWindow::renderEntity(Entity& p_entity)
{
    SDL_Rect src;// source: nguon
    src.x = p_entity.getCurrentF().x;
    src.y = p_entity.getCurrentF().y;
    src.w = p_entity.getCurrentF().w;
    src.h = p_entity.getCurrentF().h;

    SDL_Rect dst;// vi tri

    dst.x = p_entity.getX();
    dst.y = p_entity.getY();
    dst.w = p_entity.getCurrentF().w;
    dst.h = p_entity.getCurrentF().h;

    SDL_RenderCopy(renderer, p_entity.getTex(), NULL, &dst);

}

void RenderWindow::render(SDL_Texture* p_tex)
{
    SDL_RenderCopy(renderer, p_tex, NULL, NULL);

}
void RenderWindow::display()
{
    SDL_RenderPresent(renderer);
}

int k2=1;

void RenderWindow::AImove(int &ai_X,int &ai_Y,int &MaxX,int &MaxY,int &Speed,int &Speeda,SDL_Texture* &one,SDL_Texture* &two,SDL_Texture* ca1,SDL_Texture* ca2,SDL_Texture* ca3,SDL_Texture* ca4)
{

    if(ai_X >= MaxX-100)
        {Speed=-Speed;

        }

    if(ai_X <= 0 )
    {
        Speed=-Speed;
        one=ca3;two=ca4;
    }

    if(ai_X+Speed < ai_X )
    {
        one=ca1;two=ca2;
    }
    else {one=ca3;two=ca4;}

    ai_X+=Speed;


    if(ai_Y >= MaxY-100) Speeda=-Speeda;

    if(ai_Y <= 0 ) Speeda=-Speeda;

    ai_Y+=Speeda;

}

void RenderWindow::GenerationFrame(int &timefps,int &timeNow,Entity &frame1,Entity &frame2,bool &caca,int &timepos1,int &timepos2)
{

    if(caca==0)
    {
        renderEntity(frame1);

        if(timeNow+10 - timepos1 >= timefps)
            {caca=1;timepos2=timeNow;}

    }
    else
    if(caca==1)
    {
        renderEntity(frame2);

        if(timeNow+10 - timepos2 >= timefps)
            {caca=0;timepos1=timeNow;}


    }

}

void RenderWindow::Renderstart(bool &gameRunning,SDL_Texture* startgame,SDL_Event &event)
{
    while(gameRunning)
    {
        int x,y;

        clear();

        render(startgame);

        while(SDL_PollEvent(&event))//lay su kien tu ben ngoai
        {

            SDL_GetMouseState(&x, &y);

              const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

               if (currentKeyStates[SDL_SCANCODE_RETURN])gameRunning = 0;

                 if(event.type == SDL_QUIT)//neu nguoi dung dong cua so
              {
                gameRunning = 0;

              }


              if(x>450&&x<740&&y<380&&y>300)
              {
                if (event.type == SDL_MOUSEBUTTONDOWN) gameRunning = 0;
              }


    }
    SDL_Delay(5);

    display();

    }
}

void RenderWindow::Renderendloss(bool &gameRunning,SDL_Texture* gameover,SDL_Event &event,int &Point)
{
    while(gameRunning)
    {   int x,y;
        clear();
        render(gameover);

        while(SDL_PollEvent(&event))//lay su kien tu ben ngoai
        {
            SDL_GetMouseState(&x, &y);


              const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

               if (currentKeyStates[SDL_SCANCODE_ESCAPE])gameRunning = 0;

                if(event.type == SDL_QUIT)//neu nguoi dung dong cua so
              {
                gameRunning = 0;
              }

              if(x>430&&x<780&&y<560&&y>490)
              {
                if (event.type == SDL_MOUSEBUTTONDOWN) gameRunning = 0;
              }


    }
    SDL_Delay(5);

    Textend(Point);

    display();

    }

}

void RenderWindow::Renderendwin(bool &gameRunning,SDL_Texture* gameover,SDL_Event &event,int &Point)
{
    while(gameRunning)
    {   int x,y;
        clear();
        render(gameover);

        while(SDL_PollEvent(&event))//lay su kien tu ben ngoai
        {
            SDL_GetMouseState(&x, &y);

              const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

               if (currentKeyStates[SDL_SCANCODE_ESCAPE])gameRunning = 0;

                if(event.type == SDL_QUIT)//neu nguoi dung dong cua so
              {
                gameRunning = 0;
              }

              if(x>350&&x<830&&y<560&&y>490)
              {
                if (event.type == SDL_MOUSEBUTTONDOWN) gameRunning = 0;
              }


    }
    SDL_Delay(5);

    Textend(Point);

    display();

    }

}


