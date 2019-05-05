#include<stdio.h>
#include"SDL/SDL.h"
#include<SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "jeux.h"

void initialiser_score(sco *score,sec se)
{
TTF_Init();
score->font=TTF_OpenFont("BebasNeue-Book.ttf", 50);
SDL_Color color={255,0,0};
char ch[10];
sprintf(ch,"%d Dt",score->sscore);
score->score=TTF_RenderText_Solid(score->font,ch,color);
SDL_BlitSurface(score->score,NULL,se.screen,&score->position_score);
SDL_Delay(100);
SDL_Flip(se.screen);
TTF_Quit();
}

int vie(sco *s , int v)
{
    if (s->state==1)
          {
         if(v<3)
                v++;
          }
      else
          if(s->state==-1)
              v--;
                 else
                    return v;
 return v;
}

void DepAlea(ennemi *en,deplacement *d)
{ 
    int x;
    x=(rand()%2)+1;
    switch(x)
       {
       case 1:
        if((en->positionsp.x<en->intermax)/*||(en->positionjoueur.x<en->intermap)*/)
            en->positionsp.x+=20;
	    en->positionjoueur.x+=4;
	    en->positionalea.x+=2;
	    en->positionalea2.x+=2;
        break;
       case 2:
        if((en->positionsp.x>en->intermin)/*||(en->positionjoueur.x>en->intermapp)*/)
            en->positionsp.x-=20;
	    en->positionjoueur.x-=4;
	    en->positionalea.x-=1;
	    en->positionalea2.x-=1;
        break;
       }
}

void init_obj(sec se,objet *ob)
{
    ob->objet=IMG_Load("objet.png");       
    SDL_BlitSurface(ob->objet, NULL, se.screen,&ob->position_objet);    
}

void menu(sec se,ennemi *en)
{
en->imagejoueur=IMG_Load("joueur.png");       
SDL_BlitSurface(en->imagejoueur,NULL,se.screen,&en->positionjoueur);
}

void deplacement_perso(deplacement *d)
{
d->start=0;
if(d->positionperso.x<=650)
{
d->start=1;
}
}


