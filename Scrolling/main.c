#include<stdio.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_mixer.h"
#include <SDL/SDL_ttf.h>



int main(void)
{
SDL_Surface *screen ; //surface est mon fond d'ecran
SDL_Surface *background;
SDL_Surface *texte;
SDL_Surface *texte2;
SDL_Surface *perso;
SDL_Rect positionscreen;
SDL_Rect positionperso; 
SDL_Rect positionfond;
SDL_Rect position; //position du fond
SDL_Rect morceau; //bout de fond a afficher 
SDL_Event event;
positionperso.x=50;
positionperso.y=490;
position.x=0;
position.y=0;
int done=1,limitex=900,limitey=300;


 if(SDL_Init(SDL_INIT_VIDEO)!=0)
{printf("Unable to initialize SDL: %s\n",SDL_GetError());
return 1;}
screen= SDL_SetVideoMode(900,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
if(screen==NULL)
{printf("Unable to set video mode: %s\n",SDL_GetError());
return 1;}
background= SDL_LoadBMP("marche.bmp");
SDL_BlitSurface(background, NULL, screen , &position);
SDL_Flip(screen);
//SDL_BlitSurface(surface, &morceau, ecran, &position);
perso = IMG_Load("perso.png");


while(done==1)
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
                    case SDLK_UP:// Flèche haut
                                                if (limitey >= 600)
                                                {
                                                position.y=position.y-1;
                                                limitey--;

                                                break;
                                                }
                                                else
                                                {
                                                position.y=0;
                                                limitey=600;
                                                break;
                                                }
                    case SDLK_DOWN: // Flèche bas
                                                if (limitey <= 900)
                                                {
                                                position.y=position.y+1;
                                                limitey++;
                                                break;
                                                }
                                                else
                                                {
                                                position.y =300;
                                                limitey=900;
                                                break;
                                                }
                    case SDLK_LEFT: // Flèche gauche
                                  if (limitex >= 900)
                                                {
                                                position.x=position.x-1;
                                                limitex--;
                                                break;
                                                }
                                                else
                                                {
                                                position.x =0;
                                                limitex=900;
                                                break;
                                                }
                              
                 case SDLK_RIGHT: // Flèche droite
                                if (limitex <= 1600)
                                                {
                                                position.x=position.x+1;
                                                limitex++;
                                                break;
                                                }
                                                else
                                                {
                                                position.x = 700;
                                                limitex=1600;
                                                break;
                                                }
        }
break;
}//fin switch keydown
SDL_BlitSurface(background, &position, screen , NULL);
SDL_BlitSurface(perso, NULL, screen , &positionperso);
SDL_Flip(screen);
SDL_Flip(screen);
}//fin while
SDL_Quit();
return 0;
}
