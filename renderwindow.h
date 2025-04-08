#pragma once
#include <SDL.h>
#include <SDL_image.h>

class Entity
{

public:
    Entity(double p_x, double p_y,double p_w,double p_h, SDL_Texture* p_tex);

    Entitymain(double p_x, double p_y, SDL_Texture* p_tex);

    double getX();

    double getY();

    SDL_Texture* getTex();

    SDL_Rect getCurrentF();

    void CheckImpact(int x,int y,int aiX,int aiY, int &hide, int &iv,int &point,int main_w,int main_h);

    void CheckImpact2(int posX,int posY,int aiX,int aiY,bool &point,int main_w,int main_h,int Point,int &win);

    void CheckImpact3(int posX,int posY,int aiX,int aiY,bool &point,int main_w,int main_h,int Point,int &win);

private: // han che quyen truy cap

    double x,y,h,w;

    SDL_Rect currentFrame;
    SDL_Texture* tex;


};


class RenderWindow //to chuc lai ma nguon
{
public:

    RenderWindow(const char* p_title, int p_w, int p_h);

    SDL_Texture* loadTexture(const char* p_filePath);

    void cleanUp();

    void clear();

    void renderEntity(Entity& p_entity);

    void render(SDL_Texture* p_tex);

    void AImove(int &ai_X,int &ai_Y,int &MaxX,int &MaxY,int &Speed,int &Speeda,SDL_Texture* &one,SDL_Texture* &two,SDL_Texture* ca1,SDL_Texture* ca2,SDL_Texture* ca3,SDL_Texture* ca4);

    void GenerationFrame(int &timefps,int &timeNow,Entity &frame1,Entity &frame2,bool &caca,int &timepos1,int &timepos2);

    void display();

    void Renderstart(bool &gameRunning,SDL_Texture* startgame,SDL_Event &event);

    void Renderendloss(bool &gameRunning,SDL_Texture* gameover,SDL_Event &event,int &Point);

    void Renderendwin(bool &gameRunning,SDL_Texture* gameover,SDL_Event &event,int &Point);

    void Text(int Points);

    void Textend(int Points);



private:

    SDL_Window* window;
    SDL_Renderer* renderer;



};






