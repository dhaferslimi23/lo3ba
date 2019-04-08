#include<stdio.h>
#include<stdlib.h>
#include"SDL/SDL.h"
#include<SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "jeux.h"
int main(void)
{
sec se; 
sco s;
obj o;
objet ob;
int state;
int v;
int intermin;
int intermax;
int done=1;
SDL_Surface* imagevie1;
SDL_Surface* imagevie2;
SDL_Surface* imagevie3;
SDL_Surface* imagedep;
SDL_Rect positionecran,positionecran1,positionsp,positionvieA,positionvieB,positionvieC;
SDL_Event event;
SDL_Init(SDL_INIT_VIDEO);

if( SDL_Init(SDL_INIT_VIDEO)!=0)
{
printf("unabel to initialize SDL:%s\n",SDL_GetError());
return (-1);
}

se.screen=SDL_SetVideoMode(1800,400,32, SDL_HWSURFACE |SDL_DOUBLEBUF);
se.image=SDL_LoadBMP("background.bmp");

imagevie1=IMG_Load("imagevie1.png");
imagevie2=IMG_Load("imagevie2.png");
imagevie3=IMG_Load("imagevie3.png");
imagedep=IMG_Load("imagedep.png");

se.positionecran.x=0;
se.positionecran.y=0;
se.positionecran.w=se.image->w;
se.positionecran.h=se.image->h;
se.positionecran1.x=0;
se.positionecran1.y=0;
se.positionecran1.w=se.image->w;
se.positionecran1.h=se.image->h;

positionsp.x=100;
positionsp.y=263;

intermin=600;
intermax=150;

positionvieA.x=340;
positionvieA.y=0;
positionvieB.x=390;
positionvieB.y=0;
positionvieC.x=440;
positionvieC.y=0;

s.position_score.x=60;
s.position_score.y=0;
ob.position_objet.x=900;
ob.position_objet.y=273;
o.postime.x=0;
o.postime.y=0;
SDL_FillRect(se.screen, NULL, SDL_MapRGB(se.screen->format, 255, 255, 255));


while(done)
{
 SDL_PollEvent(&event);
   switch(event.type) 
    {
       case SDL_QUIT: 
         done = 0; 
        SDL_Quit();
          break;
          case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
                {
                    case SDLK_UP:
                        state++;
                          break;
                                                
                    case SDLK_DOWN:                                                 
                        state--;                                                   
                          break;                                               
                    case SDLK_LEFT: 
                       s.sscore=s.sscore+2;
                         break;
                    case SDLK_RIGHT: 
                       s.sscore=s.sscore-2;
                        break;
                 }
     break;
  }
initialiser_score(&s,se);
v=vie(state,v);
DepAlea(&positionsp,intermin,intermax);
switch(v)
{
case 1: 
SDL_BlitSurface(se.image,&se.positionecran1,se.screen,&se.positionecran);
SDL_BlitSurface(imagevie1,NULL,se.screen,&positionvieA);
SDL_BlitSurface(imagevie2,NULL,se.screen,&positionvieB);
SDL_BlitSurface(imagevie3,NULL,se.screen,&positionvieC);
SDL_BlitSurface(imagedep,NULL,se.screen,&positionsp);
break;
case 2:
SDL_BlitSurface(se.image,&se.positionecran1,se.screen,&se.positionecran);
SDL_BlitSurface(imagevie1,NULL,se.screen,&positionvieA);
SDL_BlitSurface(imagevie2,NULL,se.screen,&positionvieB);
SDL_BlitSurface(imagedep,NULL,se.screen,&positionsp);
break;
case 3:
SDL_BlitSurface(se.image,&se.positionecran1,se.screen,&se.positionecran);
SDL_BlitSurface(imagevie1,NULL,se.screen,&positionvieA);
SDL_BlitSurface(imagedep,NULL,se.screen,&positionsp);
break;
}
}
init_obj(se,&ob);
SDL_Quit();
return 0;
}
