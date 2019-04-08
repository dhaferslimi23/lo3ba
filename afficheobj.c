#include "SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_mixer.h"

#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 480
#define SPRITE_SIZE    32


void afficheobj(SDL_Surface *screen,SDL_Surface *bg,SDL_Rect rcbg,char nameobj[100],int posx,int posy)
{
SDL_Surface *temp;
SDL_Rect rctemp;
temp  = IMG_Load(nameobj);
rctemp.x=posx;
rctemp.y=posy;
SDL_BlitSurface(bg, NULL, screen, &rcbg);
SDL_BlitSurface(temp, NULL, screen, &rctemp);
SDL_UpdateRect(screen, 0, 0, 0, 0); 
SDL_FreeSurface(temp);
}

int main ()
{
SDL_Surface *screen, *temp,*bg;
SDL_Rect rcbg,rctemp;
SDL_Init(SDL_INIT_VIDEO);
screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);

rcbg.x=0;
rcbg.y=0;
bg = SDL_LoadBMP("grass.bmp");
SDL_BlitSurface(bg, NULL, screen, &rcbg);

afficheobj(screen,bg ,rcbg,"sprite.png",0,206);
SDL_Delay(10000);


return 0;
}
