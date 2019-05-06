
/**
*@file f.c
*/


#include "SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_mixer.h"
#include <math.h>
#include "f.h"
#include <stdio.h>

#define SPRITE_SIZE    32
/*void save(ttimage *allin,ttimage2 *allin2,char fich1[],char fich2[])
{
ttimage e=(*allin);
ttimage2 e2=(*allin2);
FILE *f=NULL;
FILE *f1=NULL;
f=fopen(fich1,"wb");
    if(f!=NULL)
    {
        
    fwrite(&e,sizeof(ttimage),1,f);
    
    }

fclose(f);
f1=fopen(fich2,"wb");
    if(f1!=NULL)
    {
        
    fwrite(&e2,sizeof(ttimage2),1,f1);
    
    }

fclose(f1);
}
void Load(ttimage *allin,ttimage2 *allin2,char fich1[],char fich2[])
{

ttimage e;
ttimage2 e2;
FILE *f=NULL;
FILE *f1=NULL;
f=fopen(fich1,"rb");
    if(f!=NULL)
{
fread(&e,sizeof(ttimage),1,f);
}
(*allin)=e;
fclose(f);

f1=fopen(fich2,"rb");
    if(f1!=NULL)
{
fread(&e2,sizeof(ttimage2),1,f1);
}
(*allin2)=e2;
fclose(f1);


}*/

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


SDL_Color GetPixel(SDL_Surface *pSurface,int x,int y)
{
SDL_Color color;
Uint32 col=0;
//Determine position
char* pPosition=(char* ) pSurface->pixels;
pPosition+= (pSurface->pitch * y);
pPosition+= (pSurface->format->BytesPerPixel *x);
memcpy(&col ,pPosition ,pSurface->format->BytesPerPixel);
//convertir color
SDL_GetRGB(col,pSurface->format, &color.r, &color.g, &color.b);
return (color);
}

int colision_getpixel(SDL_Rect rcSprite,int height,int width)
{ int k=0,i;
SDL_Surface *sprite,*bg;  
pos T[8];
SDL_Color color;

 


T[0].x=rcSprite.x;T[1].x=rcSprite.x+width/2;T[2].x=rcSprite.x+width;T[3].x=rcSprite.x;T[4].x=rcSprite.x;T[5].x=rcSprite.x+width/2;T[6].x=rcSprite.x+width;T[7].x=rcSprite.x+width;
T[0].y=rcSprite.y;T[1].y=rcSprite.y;T[2].y=rcSprite.y;T[3].y=rcSprite.y+height/2;T[4].y=rcSprite.y+height;T[5].y=rcSprite.y+height;T[6].y=rcSprite.y+height;T[7].y=rcSprite.y+height/2;

bg= SDL_LoadBMP("grassm.bmp");
for(i=0;i<8;i++)

color=GetPixel(bg,T[i].x, T[i].y);
         if (color.r==0 && color.g==0 && color.b==0) 
            k=1;

 if(k==1)
return 1;
         else
            return 0;
      
}
int colision_getpixeldown(SDL_Rect rcSprite,int height,int width,SDL_Rect *tmp)
{ int k=1,i=0;
SDL_Surface *bg;  
pos T[3];
SDL_Color color;

 

T[0].x=rcSprite.x;T[1].x=rcSprite.x+(width/2);T[2].x=rcSprite.x+width;
T[0].y=rcSprite.y+height;T[1].y=rcSprite.y+height;T[2].y=rcSprite.y+height;
(*tmp).x=T[0].x ;
(*tmp).y=T[0].y-SPRITE_SIZE;
bg= SDL_LoadBMP("grassm.bmp");
while(i<3 && k==1)
{
color=GetPixel(bg,T[i].x, T[i].y);
i++;
         if (color.r==0 && color.g==0 && color.b==0) 
            k=1;
         else
           k=0;
}
 if(i==3&&k==1)
return 1;
         else
            return 0;
      
}
int colision_getpixelup(SDL_Rect rcSprite,int height,int width)
{ int k=1,i=0;
SDL_Surface *bg;  
pos T[3];
SDL_Color color;

 

T[0].x=rcSprite.x;T[1].x=rcSprite.x+(width/2);T[2].x=rcSprite.x+width;
T[0].y=rcSprite.y;T[1].y=rcSprite.y;T[2].y=rcSprite.y;

bg= SDL_LoadBMP("grassm.bmp");
while(i<3 && k==1)
{
color=GetPixel(bg,T[i].x, T[i].y);
i++;
         if (color.r==0 && color.g==0 && color.b==0) 
            k=1;
         else
           k=0;
}
 if(i==3&&k==1)
return 1;
         else
            return 0;
      
}
int colision_getpixelleft(SDL_Rect rcSprite,int height,int width)
{ int k=1,i=0;
SDL_Surface *bg;  
pos T[3];
SDL_Color color;

 

T[0].x=rcSprite.x;T[1].x=rcSprite.x;T[2].x=rcSprite.x;
T[0].y=rcSprite.y;T[1].y=rcSprite.y+(height/2);T[2].y=rcSprite.y+height;

bg= SDL_LoadBMP("grassm.bmp");
while(i<3 && k==1)
{
color=GetPixel(bg,T[i].x, T[i].y);
i++;
         if (color.r==0 && color.g==0 && color.b==0) 
            k=1;
         else
           k=0;
}
 if(i==3&&k==1)
return 1;
         else
            return 0;
      
}
int colision_getpixelright(SDL_Rect rcSprite,int height,int width)
{ int k=1,i=0;
SDL_Surface *bg;  
pos T[3];
SDL_Color color;

 

T[0].x=rcSprite.x+width;T[1].x=rcSprite.x+width;T[2].x=rcSprite.x+width;
T[0].y=rcSprite.y;T[1].y=rcSprite.y+height;T[2].y=rcSprite.y+(height/2);

bg= SDL_LoadBMP("grassm.bmp");
while(i<3 && k==1)
{
color=GetPixel(bg,T[i].x, T[i].y);
i++;
         if (color.r==0 && color.g==0 && color.b==0) 
            k=1;
         else
           k=0;
}
 if(i==3&&k==1)
return 1;
         else
            return 0;
      
}
int colision_getpixeldownright(SDL_Rect rcSprite,int height,int width)
{ int k=1,i=0;
SDL_Surface *bg;  
pos T[3];
SDL_Color color;

 

T[0].x=rcSprite.x;
T[0].y=rcSprite.y+height;
bg= SDL_LoadBMP("grassm.bmp");
while(i<3 && k==1)
{
color=GetPixel(bg,T[0].x, T[0].y);
i++;
         if (color.r==0 && color.g==0 && color.b==0) 
            k=1;
         else
           k=0;
}
 if(i==3&&k==1)
return 1;
         else
            return 0;
      
}
int colision_getpixeldownleft(SDL_Rect rcSprite,int height,int width)
{ int k=1,i=0;
SDL_Surface *bg;  
pos T[3];
SDL_Color color;

 

T[0].x=rcSprite.x+width;
T[0].y=rcSprite.y+height;
bg= SDL_LoadBMP("grassm.bmp");
while(i<3 && k==1)
{
color=GetPixel(bg,T[0].x, T[0].y);
i++;
         if (color.r==0 && color.g==0 && color.b==0) 
            k=1;
         else
           k=0;
}
 if(i==3&&k==1)
return 1;
         else
            return 0;
      
}

void move(ttimage *allin ,SDL_Event event ,SDL_Surface *screen,int *gameover)
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

                       
                        allin->person.postion.x -=1;
                        allin->person.sens=-1;


o=colision_getpixelleft(allin->person.postion,32,32);
if(o==1)
{
allin->person.postion.x+= 1;
}


                        break;
                    case SDLK_RIGHT:
                        
                        allin->person.postion.x +=1;
                        allin->person.sens=1;

o=colision_getpixelright(allin->person.postion,32,32);
if(o==1)
{
allin->person.postion.x -=1;
}
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
                                   if(k==0){
                                            o=colision_getpixeldown(allin->person.postion,32,32,&tmp);
                                                  if(o==1)
                                                  {   k=1;
                                                      tmpe=tmp;
                                                  }
                                           }


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
                               if(k==0){
                                        o=colision_getpixeldown(allin->person.postion,32,32,&tmp);
                                        if(o==1)
                                          {k=1;tmpe=tmp; }
                                        }
                               }

                            }
if(k==1){
allin->person.postion.y = tmpe.y;
}


                        break;


                    default:
                        break;
                }

                break;


}

if(allin->person.sens==1)
{o1= colision_getpixeldownright(allin->person.postion,32,32);
while(o1==0)
{
allin->person.postion.y +=1;
o1= colision_getpixeldownright(allin->person.postion,32,32);
}
}
if(allin->person.sens==-1)
{
o1= colision_getpixeldownleft(allin->person.postion,32,32);
while(o1==0)
{
allin->person.postion.y +=1;
o1= colision_getpixeldownleft(allin->person.postion,32,32);
}

}





}


















