#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <vector>
#include "renderwindow.h"
#include "graphic.h"
#include <string>
#include <cmath>
using namespace std;

int window_h = 700,window_w = 1200;
int window_h1 = 900,window_w1 = 1400;
char* points;


const int FPS = 60;
const int frameDelay = 1000 / FPS;

int main (int argv, char* args[])
{

    if(SDL_Init(SDL_INIT_VIDEO)>0)
    {
    cout<<"Hey sdl_Init has fail"<< SDL_GetError()<<'\n';
    }

    if(!(IMG_Init(IMG_INIT_PNG)))
    {
    cout<<"SDL IMG_Init has fail"<<SDL_GetError()<<'\n';
    }

    RenderWindow window("GAME 1.0",window_w,window_h);

    if (Mix_Init(MIX_INIT_MP3) == 0) {
        std::cerr << "Mix_Init failed: " << Mix_GetError() << std::endl;
        SDL_Quit();
        return -1;
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cerr << "Mix_OpenAudio failed: " << Mix_GetError() << std::endl;
        Mix_Quit();
        SDL_Quit();
        return -1;
    }

    Mix_Music* backgroundMusic = Mix_LoadMUS("Music/videoplayback.mp3");

    Mix_Chunk* Soundeat = Mix_LoadWAV("Music/eat.mp3");

    if (backgroundMusic == nullptr) {
        std::cerr << "Mix_LoadMUS failed: " << Mix_GetError() << std::endl;

    }

    Mix_PlayMusic(backgroundMusic, -1);

    SDL_Texture* ca1 = window.loadTexture("images/ca1.png");
    SDL_Texture* ca2 = window.loadTexture("images/ca2.png");
    SDL_Texture* ca3 = window.loadTexture("images/ca3.png");
    SDL_Texture* ca4 = window.loadTexture("images/ca4.png");

    SDL_Texture* startgame = window.loadTexture("images/startgame2.jpg");

    SDL_Texture* lms1 = window.loadTexture("images/ca11.png");
    SDL_Texture* lms11 = window.loadTexture("images/ca22.png");

    SDL_Texture* nengame1 = window.loadTexture("images/bien.jpg");
    SDL_Texture* nengame2 = window.loadTexture("images/bien2.jpg");

    SDL_Texture* gameover = window.loadTexture("images/gameover.jpg");
    SDL_Texture* gamewin = window.loadTexture("images/gamewin.jpg");

    SDL_Texture* camap1 = window.loadTexture("images/camap1.png");
    SDL_Texture* camap2 = window.loadTexture("images/camap2.png");
    SDL_Texture* camap3 = window.loadTexture("images/camap3.png");
    SDL_Texture* camap4 = window.loadTexture("images/camap4.png");

    SDL_Texture* thuyquai1 = window.loadTexture("images/quaithu1.png");
    SDL_Texture* thuyquai2 = window.loadTexture("images/quaithu2.png");

    SDL_Texture* quai1 = window.loadTexture("images/quaithu1.png");
    SDL_Texture* quai2 = window.loadTexture("images/quaithu2.png");
    SDL_Texture* quai3 = window.loadTexture("images/quaithu3.png");
    SDL_Texture* quai4 = window.loadTexture("images/quaithu4.png");

    SDL_Texture* mosaso1 = window.loadTexture("images/mosa1.png");
    SDL_Texture* mosaso2 = window.loadTexture("images/mosa2.png");

    SDL_Texture* mosa1 = window.loadTexture("images/mosa1.png");
    SDL_Texture* mosa2 = window.loadTexture("images/mosa2.png");
    SDL_Texture* mosa3 = window.loadTexture("images/mosa3.png");
    SDL_Texture* mosa4 = window.loadTexture("images/mosa4.png");



    bool gameRunning = 1;

    int timestart = SDL_GetTicks();

    SDL_Event event;// bien su kien

    window.Renderstart(gameRunning,startgame,event);

    gameRunning = 1;

    int Point=0,d=0;
    bool check = 1;
    float posX=400,posY=400;
    int aiX1=100,aiY1=400;
    int aiX2=500,aiY2=200;
    int aiX3=100,aiY3=100;
    int aiX4=130,aiY4=300;
    int aiXquai=600,aiYquai=100;
    int aiXquai2=200,aiYquai2=100;

    int speed1 = 3,speed11 = 2 ;
    int speed2 = 2,speed22 = 1 ;
    int speed3 = 2,speed33 = 3 ;
    int speed4 = 2,speed44 = 2 ;
    int speedquai = 3,speedquai2 = 1 ;
    int speedmosa1 = 4,speedmosa2 = 1 ;


    bool iv1=0,iv2=0,iv3=0,iv4=0;

    int hide1,hide2,hide3,hide4;
    int hideDuration1=1000,hideDuration2=2000,hideDuration3=2000,hideDuration4=2000;
    int timefps=200,timefps2=300;

    int timenow;

    bool caca = 0;
    int timepos1=0,timepos2=0;

    SDL_Texture* lms2 = lms1;
    SDL_Texture* lms22 = lms11;
    SDL_Texture* lms3 = lms1;
    SDL_Texture* lms33 = lms11;
    SDL_Texture* lms4 = lms1;
    SDL_Texture* lms44 = lms11;

    int main_w=200,main_h=150;
    int main_w1=100,main_h1=70;

    int win = 0;


    SDL_ShowCursor(SDL_DISABLE);
    SDL_SetRelativeMouseMode(SDL_TRUE);

    while(gameRunning)
    {

        int x,y;

        window.clear();

        window.render(nengame1);

        timenow = SDL_GetTicks()+100;
        gameRunning = check;

        while(SDL_PollEvent(&event))//lay su kien tu ben ngoai
        {
            SDL_GetMouseState(&x, &y);

               const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

               if (currentKeyStates[SDL_SCANCODE_ESCAPE])gameRunning = 0;

                if(event.type == SDL_QUIT)//neu nguoi dung dong cua so
              {

                gameRunning = 0;

              }

      }
        float dx = x - posX;
        float dy = y - posY;
        float distance = std::sqrt(dx * dx + dy * dy);

        // Điều chỉnh tốc độ theo khoảng cách (tối đa)
        float maxSpeed = 8.0f;
        float minSpeed = 1.0f;
        float speed = distance * 0.05f; // tăng 5% theo khoảng cách
        if (speed > maxSpeed) speed = maxSpeed;
        if (speed < minSpeed) speed = minSpeed;

        // Nếu còn xa thì tiếp tục di chuyển
        if (distance > 1.0f) {
            float angle = std::atan2(dy, dx);
            posX += std::cos(angle) * speed;
            posY += std::sin(angle) * speed;
        }


                window.AImove(aiX1,aiY1,window_w,window_h,speed1,speed11,lms1,lms11,ca1,ca2,ca3,ca4);

                window.AImove(aiX2,aiY2,window_w,window_h,speed2,speed22,lms2,lms22,ca1,ca2,ca3,ca4);

                window.AImove(aiX3,aiY3,window_w,window_h,speed3,speed33,lms3,lms33,ca1,ca2,ca3,ca4);

                window.AImove(aiX4,aiY4,window_w,window_h,speed4,speed44,lms4,lms44,ca1,ca2,ca3,ca4);


                 if(iv1==1)
                 {
                     if(timenow - hide1 >= hideDuration1) iv1 = 0;
                 }
                 if(iv2==1)
                 {
                     if(timenow - hide2 >= hideDuration2) iv2 = 0;
                 }
                 if(iv3==1)
                 {
                     if(timenow - hide3 >= hideDuration3) iv3 = 0;
                 }
                 if(iv4==1)
                 {
                     if(timenow - hide4 >= hideDuration4) iv4 = 0;
                 }


                Entity lmss1(aiX1,aiY1,80,40,lms1);
                Entity lmss11(aiX1,aiY1,80,40,lms11);

                    int hide11 = hide1,iv11 = iv1;
                    lmss1.CheckImpact(posX,posY,aiX1,aiY1,hide11,iv11,Point,main_w,main_h);
                    hide1=hide11;iv1=iv11;


                Entity lmss2(aiX2,aiY2,80,40,lms2);
                Entity lmss22(aiX2,aiY2,80,40,lms22);

                    int hide22 = hide2,iv22 = iv2;
                    lmss1.CheckImpact(posX,posY,aiX2,aiY2,hide22,iv22,Point,main_w,main_h);
                    hide2=hide22;iv2=iv22;


                Entity lmss3(aiX3,aiY3,80,40,lms3);
                Entity lmss33(aiX3,aiY3,80,40,lms33);

                    int hide33 = hide3,iv33 = iv3;
                    lmss1.CheckImpact(posX,posY,aiX3,aiY3,hide33,iv33,Point,main_w,main_h);
                    hide3=hide33;iv3=iv33;


                Entity lmss4(aiX4,aiY4,80,40,lms4);
                Entity lmss44(aiX4,aiY4,80,40,lms44);

                    int hide44 = hide4,iv44 = iv4;
                    lmss1.CheckImpact(posX,posY,aiX4,aiY4,hide44,iv44,Point,main_w,main_h);
                    hide4=hide44;iv4=iv44;


                if(iv1==0)window.GenerationFrame(timefps,timenow,lmss1,lmss11,caca,timepos1,timepos2);

                if(iv2==0)window.GenerationFrame(timefps,timenow,lmss2,lmss22,caca,timepos1,timepos2);

                if(iv3==0)window.GenerationFrame(timefps,timenow,lmss3,lmss33,caca,timepos1,timepos2);

                if(iv4==0)window.GenerationFrame(timefps,timenow,lmss4,lmss44,caca,timepos1,timepos2);


                if(Point > d ){d++;

                    Mix_PlayChannel(-1, Soundeat, 0);
                    main_w =int(double(main_w)*1.022);
                    main_h =int(double(main_h)*1.022);
                    main_w1 =int(double(main_w1)*1.022);
                    main_h1 =int(double(main_h1)*1.022);
                }


                Entity thuyquaia(aiXquai,aiYquai,400,200,thuyquai1);
                Entity thuyquaib(aiXquai,aiYquai,400,200,thuyquai2);

                    thuyquaia.CheckImpact2(posX,posY,aiXquai,aiYquai,check,main_w,main_h,Point,win);

                    window.GenerationFrame(timefps2,timenow,thuyquaib,thuyquaia,caca,timepos1,timepos2);

                    window.AImove(aiXquai,aiYquai,window_w,window_h,speedquai,speedquai2,thuyquai1,thuyquai2,quai1,quai2,quai3,quai4);


                Entity mosaA(aiXquai2,aiYquai2,700,250,mosaso1);
                Entity mosaB(aiXquai2,aiYquai2,700,250,mosaso2);

                    thuyquaia.CheckImpact3(posX,posY,aiXquai2,aiYquai2,check,main_w,main_h,Point,win);

                    window.GenerationFrame(timefps2,timenow,mosaA,mosaB,caca,timepos1,timepos2);

                    window.AImove(aiXquai2,aiYquai2,window_w1,window_h1,speedmosa1,speedmosa2,mosaso1,mosaso2,mosa1,mosa2,mosa3,mosa4);



               if(x<posX)
               {
                    Entity camapboi1(posX-main_w1,posY-main_h1,main_w,main_h,camap3);

                    Entity camapboi2(posX-main_w1,posY-main_h1,main_w,main_h,camap4);

                    window.GenerationFrame(timefps,timenow,camapboi1,camapboi2,caca,timepos1,timepos2);
               }
               else

               {    Entity camapboi1(posX-main_w1,posY-main_h1,main_w,main_h,camap1);

                    Entity camapboi2(posX-main_w1,posY-main_h1,main_w,main_h,camap2);

                    window.GenerationFrame(timefps,timenow,camapboi1,camapboi2,caca,timepos1,timepos2);

               }


        SDL_Delay(3);

        window.Text(Point);

        if(gameRunning==0) {Mix_PlayChannel(-1, Soundeat, 0);}

        window.display();

    }

    SDL_ShowCursor(SDL_ENABLE);
    SDL_SetRelativeMouseMode(SDL_FALSE);


    gameRunning = 1;


   if(win==1)window.Renderendwin(gameRunning,gamewin,event,Point);

        else  window.Renderendloss(gameRunning,gameover,event,Point);

    window.cleanUp();
    SDL_Quit();
    Mix_Quit();

return 0;
}
