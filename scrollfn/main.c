#include<stdio.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_mixer.h"
#include <SDL/SDL_ttf.h>
void DepAlea(SDL_Rect *positionsp,int intermin , int intermax)
{
    int x;
    x=(rand()%2)+1;
    switch(x)
       {
       case 1:
        if(positionsp->x<intermax)
            positionsp->x++;
        break;
       case 2:
        if(positionsp->x>intermin)
            positionsp->x--;
        break;
       }
}
int collision(int x , int y , int h1x ,int h1y , int h2x ,int h2y , int sx , int sy , int sx1 , int sy1)
{
    if((x-h1x<40 && x-h1x>-40 && y-h1y<40 && y-h1y>-40)||(x-h2x<40 && x-h2x>-40 && y-h2y<40 && y-h2y>-40))
        return 1;
       else
           if((x-sx<40 && x-sx>-40 && y-sy<40 && y-sy>-40)||(x-sx1<40 && x-sx1>-40 && y-sy1<40 && y-sy1>-40))
               return -1;
           else 
               return 0;
}
int vie(int state , int hp)
{
    if (state==1)
          {if(hp<3)
                hp++;}
      else
          if(state==-1)
              hp--;
                 else
                    return hp;
 return hp;
}

void scroll(int *intermax1,int *intermin1,int *intermax,int *intermin,SDL_Event event,int *sens,int *cmpimg,int *limitex,int *limitey,SDL_Rect *position, SDL_Rect *positionperso , SDL_Rect *positionhig1 , SDL_Rect *positionhig2 , SDL_Rect *positionsp)
{
    switch(event.type) 
{
case SDL_KEYDOWN:
switch(event.key.keysym.sym)
                {
                    case SDLK_UP:// Flèche haut
                                 /*if (limitey >= 600)
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
                                                }*/
                            break;
                    /*case SDLK_DOWN: // Flèche bas
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
                                                }*/
                    case SDLK_LEFT: // Flèche gauche
                          if(*sens==1)  
                            *cmpimg=1;
                          *sens=2;  
                       if(positionperso->x>=500)
                            {positionperso->x=positionperso->x-10;
                             break;}
                            else{      if ((*limitex) >= 900)
                                                {
                                                position->x=position->x-5;
                                                positionhig1->x+=5;
                                                positionhig2->x+=5;
                                                positionsp->x+=5;
                                                *intermin-=5;
                                                *intermax-=5;
                                                *intermin1-=5;
                                                *intermax1-=5;
                                                (*limitex)--;
                                                break;
                                                }
                                                else
                                                {
                                                position->x =0;
                                                positionhig1->x=700;
                                                positionhig2->x=1500;
                                                (*limitex)=900;
                                                if(positionperso->x>=0)
                                                    {positionperso->x=positionperso->x-10;}
                                                break;
                                                }
                                 }
                 case SDLK_RIGHT: // Flèche droite
                         if(*sens==2)  
                            *cmpimg=1;
                         *sens=1;
                      if(positionperso->x<=350)
                        {positionperso->x=positionperso->x+10;
                         break;}
                        else{        if ((*limitex) <= 1600)
                                                {
                                                position->x=position->x+5;
                                                positionhig1->x-=5;
                                                positionhig2->x-=5;
                                                *intermin+=5;
                                                *intermax+=5;
                                                *intermin1+=5;
                                                *intermax1+=5;
                                                positionsp->x-=5;
                                                (*limitex)++;
                                                break;
                                                }
                                                else
                                                {
                                                position->x = 700;
                                                (*limitex)=1600;
                                                if(positionperso->x<=800)
                                                    {positionperso->x=positionperso->x+10;}
                                                break;
                                                }
                            }      
                  }
break;
}
}

int main(void)
{
SDL_Surface *screen ; //surface est mon fond d'ecran
SDL_Surface *background;
SDL_Surface *texte;
SDL_Surface *texte2;
SDL_Surface *perso;
SDL_Surface *heart;
SDL_Surface *noheart;
SDL_Surface *sparkle;
SDL_Surface *perso1;
SDL_Surface *perso2;
SDL_Surface *perso3;
SDL_Surface *perso4;
SDL_Surface *perso5;
SDL_Surface *perso6;
SDL_Surface *perso7;
SDL_Surface *perso8;
SDL_Surface *perso11;
SDL_Surface *perso22;
SDL_Surface *perso33;
SDL_Surface *perso44;
SDL_Surface *perso55;
SDL_Surface *perso66;
SDL_Surface *perso77;
SDL_Surface *perso88;

SDL_Rect positionscreen;
SDL_Rect positionperso;
SDL_Rect positionsp;
SDL_Rect positionsp1;
SDL_Rect positionh1;
SDL_Rect positionh2;
SDL_Rect positionh3;
SDL_Rect positionhig1;
SDL_Rect positionhig2; 
SDL_Rect positionfond;
SDL_Rect position; //position du fond
SDL_Event event;
positionh1.x=840;
positionh2.x=780;
positionh3.x=720;
positionh1.y=50;
positionh2.y=50;
positionh3.y=50;
positionhig1.x=700;
positionhig1.y=515;

positionhig2.x=1500;
positionhig2.y=515;
positionsp.x=1220;
positionsp.y=515;
positionsp1.x=500;
positionsp1.y=515;

positionperso.x=50;
positionperso.y=515;
position.x=0;
position.y=0;
int done=1,limitex=900,limitey=300,sens=1,cmpimg=1,i,hp=2,state=0;
int interminsp=1200, intermaxsp=1450,interminsp1=400, intermaxsp1=600;
float ms=0;
Uint8 *keystate;
Uint8 *keystate1;


 if(SDL_Init(SDL_INIT_VIDEO)!=0)
{printf("Unable to initialize SDL: %s\n",SDL_GetError());
return 1;}
screen= SDL_SetVideoMode(900,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
if(screen==NULL)
{printf("Unable to set video mode: %s\n",SDL_GetError());
return 1;}
background= SDL_LoadBMP("marche.bmp");
SDL_BlitSurface(background, NULL, screen , &position);
SDL_BlitSurface(heart, NULL, screen , &positionh1);
SDL_BlitSurface(heart, NULL, screen , &positionh2);
SDL_BlitSurface(heart, NULL, screen , &positionh3);
SDL_Flip(screen);
//SDL_BlitSurface(surface, &morceau, ecran, &position);
heart = IMG_Load("heart.png");
noheart = IMG_Load("noheart.png");
sparkle= IMG_Load("enemy.png");
perso1 = IMG_Load("1.png");
perso2 = IMG_Load("2.png");
perso3 = IMG_Load("3.png");
perso4 = IMG_Load("4.png");
perso5 = IMG_Load("5.png");
perso6 = IMG_Load("6.png");
perso7 = IMG_Load("7.png");
perso8 = IMG_Load("8.png");

perso11 = IMG_Load("11.png");
perso22 = IMG_Load("22.png");
perso33 = IMG_Load("33.png");
perso44 = IMG_Load("44.png");
perso55 = IMG_Load("55.png");
perso66 = IMG_Load("66.png");
perso77 = IMG_Load("77.png");
perso88 = IMG_Load("88.png");

position.x=0;
position.y=220;
limitey=820;

while(done==1)
{
SDL_PollEvent(&event);
DepAlea(&positionsp,interminsp,intermaxsp);
DepAlea(&positionsp1,interminsp1,intermaxsp1);
scroll(&intermaxsp1,&interminsp1,&intermaxsp,&interminsp,event,&sens,&cmpimg,&limitex,&limitey,&position, &positionperso , &positionhig1 , &positionhig2 , &positionsp);
switch(event.type) 
{
case SDL_QUIT: 
done = 0; 
SDL_Quit();
break;
}//fin switch keydown
SDL_BlitSurface(background, &position, screen , NULL);
SDL_BlitSurface(heart, NULL, screen , &positionhig1);
SDL_BlitSurface(heart, NULL, screen , &positionhig2);
SDL_BlitSurface(sparkle, NULL, screen , &positionsp);
SDL_BlitSurface(sparkle, NULL, screen , &positionsp1);

state=collision(positionperso.x ,positionperso.y , positionhig1.x ,positionhig1.y , positionhig2.x ,positionhig2.y , positionsp.x , positionsp.y,positionsp1.x,positionsp1.y);
hp=vie(state , hp);
switch(hp)
{case 1:
  SDL_BlitSurface(background, &position, screen , NULL);
SDL_BlitSurface(heart, NULL, screen , &positionhig1);
SDL_BlitSurface(heart, NULL, screen , &positionhig2);
SDL_BlitSurface(sparkle, NULL, screen , &positionsp);
SDL_BlitSurface(sparkle, NULL, screen , &positionsp1);
   SDL_BlitSurface(heart, NULL, screen , &positionh1);
SDL_BlitSurface(noheart, NULL, screen , &positionh2);
SDL_BlitSurface(noheart, NULL, screen , &positionh3);
   break;
 case 2:
  SDL_BlitSurface(background, &position, screen , NULL);
SDL_BlitSurface(heart, NULL, screen , &positionhig1);
SDL_BlitSurface(heart, NULL, screen , &positionhig2);
SDL_BlitSurface(sparkle, NULL, screen , &positionsp);
SDL_BlitSurface(sparkle, NULL, screen , &positionsp1);
SDL_BlitSurface(heart, NULL, screen , &positionh1);
SDL_BlitSurface(heart, NULL, screen , &positionh2);
SDL_BlitSurface(noheart, NULL, screen , &positionh3);
   break;
 case 3:
  SDL_BlitSurface(background, &position, screen , NULL);
SDL_BlitSurface(heart, NULL, screen , &positionhig1);
SDL_BlitSurface(heart, NULL, screen , &positionhig2);
SDL_BlitSurface(sparkle, NULL, screen , &positionsp1);
SDL_BlitSurface(sparkle, NULL, screen , &positionsp);   
SDL_BlitSurface(heart, NULL, screen , &positionh1);
SDL_BlitSurface(heart, NULL, screen , &positionh2);
SDL_BlitSurface(heart, NULL, screen , &positionh3);
   break;
}
switch(sens)
{case 1:
      switch(cmpimg)
         {
             case 1 :
                 SDL_BlitSurface(perso11, NULL, screen , &positionperso);
                 ms++;
               if(ms=1000000000)
                 cmpimg++;
               break;
             case 2 :
                 SDL_BlitSurface(perso22, NULL, screen , &positionperso);
                 ms++;
               if(ms=2000000000)
                 cmpimg++;
               break;
             case 3 :
                 SDL_BlitSurface(perso33, NULL, screen , &positionperso);
                 ms++;
               if(ms=3000000000)
                 cmpimg++;
                 break;
             case 4 :
                 SDL_BlitSurface(perso44, NULL, screen , &positionperso);
                 ms++;
               if(ms=4000000000)
                 cmpimg++;
                break;
             case 5 :
                 SDL_BlitSurface(perso55, NULL, screen , &positionperso);
                 ms++;
               if(ms=5000000000)
                 cmpimg++;
               break;
             case 6 :
                 SDL_BlitSurface(perso66, NULL, screen , &positionperso);
                 ms++;
               if(ms=6000000000)
                 cmpimg++;
                break;
             case 7 :
                 SDL_BlitSurface(perso77, NULL, screen , &positionperso);
                 ms++;
               if(ms=7000000000)
                 cmpimg++;
                break;
             case 8 :
                 SDL_BlitSurface(perso88, NULL, screen , &positionperso);
                 ms++;
               if(ms=8000000000)
                 cmpimg=1;
               break;
             
         }
    break;
case 2:
    switch(cmpimg)
         {
             case 1 :
                 SDL_BlitSurface(perso1, NULL, screen , &positionperso);
                 cmpimg++;
               break;
             case 2 :
                 SDL_BlitSurface(perso2, NULL, screen , &positionperso);
                 cmpimg++;
               break;
             case 3 :
                 SDL_BlitSurface(perso3, NULL, screen , &positionperso);
                 cmpimg++;
                 break;
             case 4 :
                 SDL_BlitSurface(perso4, NULL, screen , &positionperso);
                 cmpimg++;
                break;
             case 5 :
                 SDL_BlitSurface(perso5, NULL, screen , &positionperso);
                 cmpimg++;
               break;
             case 6 :
                 SDL_BlitSurface(perso6, NULL, screen , &positionperso);
                 cmpimg++;
                break;
             case 7 :
                 SDL_BlitSurface(perso7, NULL, screen , &positionperso);
                 cmpimg++;
                break;
             case 8 :
                 SDL_BlitSurface(perso8, NULL, screen , &positionperso);
                 cmpimg=1;
               break;
             
         }
  break;
}
SDL_Flip(screen);

}//fin while
SDL_Quit();
return 0;
}
