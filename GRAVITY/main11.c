/**
*@file main11.c
*/



#include "SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_mixer.h"
#include <math.h>
#include "f.h"
#include <stdio.h>

#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 480
#define SPRITE_SIZE    32
#define FPS 60

int main ( )
{ 
  ttimage allin;
  SDL_Surface *screen,*test;
  SDL_Event event;
  int  gameover;
 

  
 

  /* initialize SDL */
  SDL_Init(SDL_INIT_VIDEO);

  /* set the title bar */
  SDL_WM_SetCaption("WHELL'S TOWN", "WHELL'S TOWN");

  /* create window */
  screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);


  /* load fn */

initialiser_image_position(&allin);


  gameover = 0;
  /* loop game */
  while (!gameover)
  {

 SDL_PollEvent(&event);      

move(&allin ,event,screen ,&gameover);
   

afficheall(&allin,screen);
   
 
  }

  /* clean up */
 
  SDL_Quit();


  return 0;
}
