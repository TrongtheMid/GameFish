#include <SDL.h>
#include <SDL_image.h>
#include "Renderwindow.h"
#include <vector>
#include <iostream>
#include <SDL_mixer.h>

using namespace std;
Entity::Entity(double p_x, double p_y,double p_w,double p_h, SDL_Texture* p_tex)
:x(p_x), y(p_y),w(p_w),h(p_h),tex(p_tex)
{
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = p_w;
    currentFrame.h = p_h;
}

double Entity::getX() // cap quyen X trong private
{
    return x;
}

double Entity::getY()
{
    return y;
}

SDL_Texture* Entity::getTex()
{
    return tex;
}

SDL_Rect Entity::getCurrentF()
{
    return currentFrame;
}

void Entity::CheckImpact(int posX,int posY,int aiX,int aiY, int &hide, int &iv,int &point,int main_w,int main_h)
{
    if(iv==0)
    if(posX>=aiX-main_w/4&&posX<=aiX+main_w/4+30&&posY>=aiY-main_h/4&&posY<=aiY+main_h/4+30)
        {
            hide=SDL_GetTicks();
            iv=1;
            point++;
        }

}

void Entity::CheckImpact2(int posX,int posY,int aiX,int aiY,bool &point,int main_w,int main_h,int Point,int &win)
{

    if(posX>=aiX-main_w/4&&posX<=aiX+100+main_w/4&&posY-70>=aiY-main_h/4&&posY<=aiY+120+main_h/4)
        {point = 0;

            if(Point>=50)win = 1;

        }

}

void Entity::CheckImpact3(int posX,int posY,int aiX,int aiY,bool &point,int main_w,int main_h,int Point,int &win)
{

    if(posX>=aiX-main_w/4&&posX<=aiX+100+main_w/4&&posY-70>=aiY-main_h/4+70&&posY<=aiY+120+main_h/4)
        {
            point = 0;

            if(Point>=50)win = 1;

        }

}



