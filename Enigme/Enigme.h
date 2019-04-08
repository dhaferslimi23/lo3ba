#include<stdio.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#ifndef Main_H_INCLUDED
#define MAin_H_INCLUDED

int affichEnigme(int x,SDL_Surface*screen,SDL_Surface*image , SDL_Rect positionecran);
int ReponseEnigme(SDL_Event test , int x);


#endif
