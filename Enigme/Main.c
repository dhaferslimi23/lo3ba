#include<stdio.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include "Enigme.h"
int main (){
SDL_Surface *screen;
SDL_Surface *image;
SDL_Rect positionecran;
int x;
SDL_Event test;
positionecran.x=0;
positionecran.y=0;

if(SDL_Init(SDL_INIT_VIDEO)!=0)
{
printf("Unable to initialize SDL: %s\n",SDL_GetError());
return 1;
}

screen= SDL_SetVideoMode(1600,400,0,SDL_HWSURFACE | SDL_DOUBLEBUF);
if(screen==NULL)
{
printf("Unable to set video mode: %s\n",SDL_GetError());
return 1;
}
x=rand()%3;
affichEnigme(x,screen,image,positionecran);
ReponseEnigme(test,x);
if (ReponseEnigme)
  {// Win(screen,image, positionecran);
  }
  else {
    //Lose(screen,image,positionecran);
}
return 0;
}
