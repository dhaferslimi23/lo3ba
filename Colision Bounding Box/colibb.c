#include "SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_mixer.h"

#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 480
#define SPRITE_SIZE    32

typedef struct {
int x;
int y;
int w;
int h;
}aabb;
int colision_b_box(aabb Personnage,aabb Ennemi)
{
if (Personnage.x + Personnage. w< Ennemi. x || Personnage.x> Ennemi. x + Ennemi. w || Personnage.y + Personnage.h< Ennemi. y || Personnage.y> Ennemi. y + Ennemi. h )
return 0 ;// pas de collision
else
return 1;
}




int main ( int argc, char *argv[] )
{
  SDL_Surface *screen, *temp, *sprite, *grass, *ennemi,*test;
  SDL_Rect rcSprite, rcGrass,rcennemi,rctest;
  aabb hero ,ennemii;
  SDL_Event event;
  Uint8 *keystate;
  Uint8 *keystate1;

  int colorkey, gameover;
int z=0,d=0,o;

  /* initialize SDL */
  SDL_Init(SDL_INIT_VIDEO);

  /* set the title bar */
  SDL_WM_SetCaption("SDL Move", "SDL Move");

  /* create window */
  screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);


  /* load sprite et ennemi */
  temp   = SDL_LoadBMP("sprite.bmp");
  sprite = SDL_DisplayFormat(temp);
  temp   = IMG_Load("ennemi.png");
  ennemi = SDL_DisplayFormat(temp);
  temp   = IMG_Load("test.png");
  test = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  /* setup sprite colorkey and turn on RLE */
  colorkey = SDL_MapRGB(screen->format, 255, 0, 255);
  SDL_SetColorKey(sprite, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);

  /* load grass */
  temp  = SDL_LoadBMP("grass.bmp");
  grass = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  /* set sprite position */
  rcSprite.x = 0;
  rcSprite.y = 206;
 
  rcennemi.x = 200;
  rcennemi.y = 206;

  rctest.x=100;
  rctest.y=300;

  gameover = 0;

  /* message pump */
  while (!gameover)
  {
    /* look for an event */
    if (SDL_PollEvent(&event)) {
      /* an event was found */
      switch (event.type) {
        /* close button clicked */
        case SDL_QUIT:
          gameover = 1;
          break;

        /* handle the keyboard */
        case SDL_KEYDOWN:
          switch (event.key.keysym.sym) {
            case SDLK_ESCAPE:
            case SDLK_q:
              gameover = 1;
              break;
          }
          break;
        case SDL_MOUSEBUTTONDOWN :
         if( event.button.button == SDL_BUTTON_LEFT )
        {
         //Get the mouse offsets
          z = event.button.x;
          d = event.button.y;
                rcSprite.x = z;
                rcSprite.y =d;
                SDL_BlitSurface(grass, NULL, screen, &rcGrass);
         SDL_BlitSurface(sprite, NULL, screen, &rcSprite);
            SDL_UpdateRect(screen, 0, 0, 0, 0);
         }

         break;
      }
    }

    /* handle sprite movement */
    keystate = SDL_GetKeyState(NULL);
keystate1 = SDL_GetKeyState(NULL);

if (keystate[SDLK_UP] ) {    
      rcSprite.y -= 10;
sprite = IMG_Load("sprite.png");
SDL_BlitSurface(grass, NULL, screen, &rcGrass);
SDL_BlitSurface(sprite, NULL, screen, &rcSprite);
SDL_UpdateRect(screen, 0, 0, 0, 0);  
SDL_Delay(30);
 rcSprite.y -= 10;
SDL_BlitSurface(grass, NULL, screen, &rcGrass);
SDL_BlitSurface(sprite, NULL, screen, &rcSprite);
SDL_UpdateRect(screen, 0, 0, 0, 0);  
SDL_Delay(30);
rcSprite.y -= 10;
SDL_BlitSurface(grass, NULL, screen, &rcGrass);
SDL_BlitSurface(sprite, NULL, screen, &rcSprite);
SDL_UpdateRect(screen, 0, 0, 0, 0);  
SDL_Delay(30);
rcSprite.y -= 10;
SDL_BlitSurface(grass, NULL, screen, &rcGrass);
SDL_BlitSurface(sprite, NULL, screen, &rcSprite);
SDL_UpdateRect(screen, 0, 0, 0, 0);  
if (keystate1[SDLK_LEFT] ) {rcSprite.x -=20; }
if (keystate1[SDLK_RIGHT] ) { rcSprite.x +=20; }

rcSprite.y += 10;
SDL_BlitSurface(grass, NULL, screen, &rcGrass);
SDL_BlitSurface(sprite, NULL, screen, &rcSprite);
SDL_UpdateRect(screen, 0, 0, 0, 0);  
SDL_Delay(30);
rcSprite.y += 10;
SDL_BlitSurface(grass, NULL, screen, &rcGrass);
SDL_BlitSurface(sprite, NULL, screen, &rcSprite);
SDL_UpdateRect(screen, 0, 0, 0, 0);  
SDL_Delay(30);
rcSprite.y += 10;
SDL_BlitSurface(grass, NULL, screen, &rcGrass);
SDL_BlitSurface(sprite, NULL, screen, &rcSprite);
SDL_UpdateRect(screen, 0, 0, 0, 0);  
SDL_Delay(30);
rcSprite.y += 10;
SDL_BlitSurface(grass, NULL, screen, &rcGrass);
SDL_BlitSurface(sprite, NULL, screen, &rcSprite);
SDL_UpdateRect(screen, 0, 0, 0, 0);  

    }
    if (keystate[SDLK_LEFT] ) {
rcSprite.x -=10;
sprite = IMG_Load("detective2-1.png");
      SDL_BlitSurface(grass, NULL, screen, &rcGrass);
        SDL_BlitSurface(sprite, NULL, screen, &rcSprite);
SDL_UpdateRect(screen, 0, 0, 0, 0);
SDL_Delay(30);
rcSprite.x -=10;
sprite = IMG_Load("detective2-2.png");
      SDL_BlitSurface(grass, NULL, screen, &rcGrass);
        SDL_BlitSurface(sprite, NULL, screen, &rcSprite);
SDL_UpdateRect(screen, 0, 0, 0, 0);
SDL_Delay(30);
rcSprite.x -=10;
sprite = IMG_Load("detective2-3.png");
      SDL_BlitSurface(grass, NULL, screen, &rcGrass);
        SDL_BlitSurface(sprite, NULL, screen, &rcSprite);
SDL_UpdateRect(screen, 0, 0, 0, 0);
SDL_Delay(30);
rcSprite.x -=10;
sprite = IMG_Load("detective2-7.png");
      SDL_BlitSurface(grass, NULL, screen, &rcGrass);
        SDL_BlitSurface(sprite, NULL, screen, &rcSprite);
SDL_UpdateRect(screen, 0, 0, 0, 0);
SDL_Delay(30);
rcSprite.x -=10;
sprite = IMG_Load("detective2-8.png");
      SDL_BlitSurface(grass, NULL, screen, &rcGrass);
        SDL_BlitSurface(sprite, NULL, screen, &rcSprite);
SDL_UpdateRect(screen, 0, 0, 0, 0);
    }
    if (keystate[SDLK_RIGHT] ) {
      rcSprite.x +=10;
sprite = IMG_Load("detective1-1.png");
      SDL_BlitSurface(grass, NULL, screen, &rcGrass);
        SDL_BlitSurface(sprite, NULL, screen, &rcSprite);
SDL_UpdateRect(screen, 0, 0, 0, 0);
SDL_Delay(30);
rcSprite.x +=10;
sprite = IMG_Load("detective1-2.png");
      SDL_BlitSurface(grass, NULL, screen, &rcGrass);
        SDL_BlitSurface(sprite, NULL, screen, &rcSprite);
SDL_UpdateRect(screen, 0, 0, 0, 0);
SDL_Delay(30);
rcSprite.x +=10;
sprite = IMG_Load("detective1-3.png");
      SDL_BlitSurface(grass, NULL, screen, &rcGrass);
        SDL_BlitSurface(sprite, NULL, screen, &rcSprite);
SDL_UpdateRect(screen, 0, 0, 0, 0);
SDL_Delay(30);
rcSprite.x +=10;
sprite = IMG_Load("detective1-7.png");
      SDL_BlitSurface(grass, NULL, screen, &rcGrass);
        SDL_BlitSurface(sprite, NULL, screen, &rcSprite);
SDL_UpdateRect(screen, 0, 0, 0, 0);
SDL_Delay(30);
rcSprite.x+=10;
sprite = IMG_Load("detective1-8.png");
      SDL_BlitSurface(grass, NULL, screen, &rcGrass);
        SDL_BlitSurface(sprite, NULL, screen, &rcSprite);
SDL_UpdateRect(screen, 0, 0, 0, 0);
    }
    
    /*if (keystate[SDLK_DOWN] ) {
      rcSprite.y += 80;
    }*/
    /* collide with edges of screen */
 hero.x=rcSprite.x ;
  hero.y=rcSprite.y ;
  hero.w=32;
  hero.h=32;
  ennemii.x=rcennemi.x;
  ennemii.y=rcennemi.x;
  ennemii.w=32;
  ennemii.h=32;
    o=colision_b_box(hero,ennemii);
    if(o==1)
   {
           SDL_BlitSurface(grass, NULL, screen, &rcGrass);
         SDL_BlitSurface(test, NULL, screen, &rctest);
                  SDL_BlitSurface(ennemi, NULL, screen, &rcennemi);
               SDL_BlitSurface(sprite, NULL, screen, &rcSprite);
            SDL_UpdateRect(screen, 0, 0, 0, 0);
   }
    if ( rcSprite.x < 0 ) {
      rcSprite.x = 0;
    }
    else if ( rcSprite.x > SCREEN_WIDTH-SPRITE_SIZE ) {
      rcSprite.x = SCREEN_WIDTH-SPRITE_SIZE;
    }
    if ( rcSprite.y < 0 ) {
      rcSprite.y = 0;
    }
    else if ( rcSprite.y > SCREEN_HEIGHT-SPRITE_SIZE ) {
      rcSprite.y = SCREEN_HEIGHT-SPRITE_SIZE;
    }

    //draw the grass 
    for (int x = 0; x < SCREEN_WIDTH / SPRITE_SIZE; x++) {
      for (int y = 0; y < SCREEN_HEIGHT / SPRITE_SIZE; y++) {
        rcGrass.x =0;
        rcGrass.y =0;
        SDL_BlitSurface(grass, NULL, screen, &rcGrass);
      }
    }
    /* draw the sprite */
    SDL_BlitSurface(sprite, NULL, screen, &rcSprite);

    /* update the screen */
    SDL_UpdateRect(screen, 0, 0, 0, 0);

       SDL_BlitSurface(grass, NULL, screen, &rcGrass);
         SDL_BlitSurface(ennemi, NULL, screen, &rcennemi);
 SDL_BlitSurface(sprite, NULL, screen, &rcSprite);
            SDL_UpdateRect(screen, 0, 0, 0, 0);

  }

  /* clean up */
  SDL_FreeSurface(test);
  SDL_FreeSurface(ennemi);
  SDL_FreeSurface(sprite);
  SDL_FreeSurface(grass);
  SDL_Quit();

  return 0;
}
