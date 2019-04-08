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

screen= SDL_SetVideoMode(950,600,0,SDL_HWSURFACE | SDL_DOUBLEBUF);
if(screen==NULL)
{
printf("Unable to set video mode: %s\n",SDL_GetError());
return 1;
}
x=rand()%3;
affichEnigme(x,screen,image,positionecran);

ReponseEnigme(test,x);
SDL_FreeSurface(image);
if (ReponseEnigme)
  {	
	image=SDL_LoadBMP("Winner.bmp");
	SDL_BlitSurface(image,NULL,screen,&positionecran);
	SDL_Flip(screen);
  }
  else {
    image=SDL_LoadBMP("Loser.bmp");
    SDL_BlitSurface(image,NULL,screen,&positionecran);
    SDL_Flip(screen);
}
return 0;
}
