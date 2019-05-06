/**
*@file mvtacf.c
*/

#include "SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_mixer.h"
#include <math.h>
#include "mvtac.h"
#include <stdio.h>

#define SPRITE_SIZE    32
void save(ttimage *allin,char fich[])
{
ttimage e=(*allin);
FILE *f=NULL;
f=fopen(fich,"wb");
    if(f!=NULL)
    {
          
   
    fwrite(&e,sizeof(ttimage),1,f);
    

    
    }

fclose(f);
}
void Load(ttimage *allin,char fich[])
{

ttimage e;
FILE *f=NULL;
f=fopen(fich,"rb");
    if(f!=NULL)
{
fread(&e,sizeof(ttimage),1,f);
}
(*allin)=e;
fclose(f);

}

int fnparabole(int x)
{
int y;
y=((-(x*x))+4);
if(y%10==0)
  return y;

}
void affichejump(ttimage *allin,SDL_Surface *screen)
{

SDL_BlitSurface(allin->background.image, &allin->background.postion, screen, NULL);
SDL_BlitSurface(allin->person.image, NULL, screen, &allin->person.postion);
SDL_UpdateRect(screen, 0, 0, 0, 0);  

}



void initialiser_image_position(ttimage *allin)
{
     allin->background.image = SDL_LoadBMP("grass.bmp");
     allin->background.postion.x=0;
     allin->background.postion.y=0;
       
     allin->person.image=IMG_Load("detective1-1.png");
     allin->person.postion.x=0;
     allin->person.postion.y=398;
     allin->person.sens=1;
     allin->person.acceleration=0.001;

    
}








void affichesimple(SDL_Surface *image ,SDL_Rect pos,SDL_Surface *screen)
{
SDL_BlitSurface(image, NULL, screen, &pos);
}

void afficheall(ttimage *allin,SDL_Surface *screen)
{

SDL_BlitSurface(allin->background.image, NULL, screen, &allin->background.postion);
affichesimple(allin->person.image ,allin->person.postion,screen);
SDL_UpdateRect(screen, 0, 0, 0, 0);
}



void move(ttimage *allin ,SDL_Event event ,SDL_Surface *screen,int *gameover,Uint32 dt)
{
int x,i,o=0,k,o1=1;
char save1[]="SAVE1.bin";
SDL_Rect tmp,tmpe;
        switch( event.type ){
            /* Look for a keypress */
            case SDL_QUIT:
         (* gameover) = 1;
          break;
            case SDL_KEYDOWN:
                /* Check the SDLKey values and move change the coords */
                switch( event.key.keysym.sym ){
                   case SDLK_ESCAPE:
            case SDLK_q:
              (*gameover) = 1;
              break;
                        case SDLK_LEFT:
                       allin->person.acceleration+=0.005;
                        allin->person.postion.x -=(0.5*allin->person.acceleration)*(dt*dt)+allin->person.vitesse*dt;
                        allin->person.sens=-1;
                        break;
                        case SDLK_RIGHT:
                        allin->person.acceleration+=0.005;
                        allin->person.postion.x +=(0.5*allin->person.acceleration)*(dt*dt)+allin->person.vitesse*dt;
                        allin->person.sens=1;
                        break;
                        case SDLK_SPACE:
                        if(allin->person.sens==-1)
                            {x=-8;k=0;
                               for(i=0;i<17;i++)
                                  {

                                 allin->person.postion.x-=10;

                                        if(i<7)
                                           allin->person.postion.y+=fnparabole(x);


                                        else

                                      allin->person.postion.y-=fnparabole(x);

                                    affichejump(allin,screen);
                                    SDL_Delay(10);
                                    x++;
                                   


                                   }
                            }
                        if(allin->person.sens==1)
                            {k=0;
                              x=-8;
                             for(i=0;i<17;i++)
                                {


                                allin->person.postion.x+=10;

                                     if(i<7)
                                      allin->person.postion.y+=fnparabole(x);

                                     else
                                      allin->person.postion.y-=fnparabole(x);

                                 affichejump(allin,screen);
                                 SDL_Delay(10);
                               x++;
                               

                            }



                        break;
case SDLK_j:
Load(allin,save1);
break;
                    case SDLK_k:
save(allin,save1);
break;
                    default:
                        break;
                }

                break;
                }
  break;               
case SDL_KEYUP:
switch( event.key.keysym.sym ){
          case SDLK_LEFT:
            allin->person.acceleration=0.001;
          break;
          case SDLK_RIGHT:
            allin->person.acceleration=0.001;
          break;
                              }
break;

}








}



















