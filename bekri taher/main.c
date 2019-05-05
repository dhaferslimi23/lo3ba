#include<stdio.h>
#include<stdlib.h>
#include"SDL/SDL.h"
#include<SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "jeux.h"
int main(void)
{
sec se; 
sco s;
obj o;
objet ob;
ennemi en;
deplacement d;
int v=0;
int done=1;

SDL_Surface* imagevie1;
SDL_Surface* imagevie2;
SDL_Surface* imagevie3;
SDL_Rect positionecran,positionecran1,positionvieA,positionvieB,positionvieC;
SDL_Event event;
SDL_Init(SDL_INIT_VIDEO);
s.sscore=0;
s.state=1;

if( SDL_Init(SDL_INIT_VIDEO)!=0)
{
printf("unabel to initialize SDL:%s\n",SDL_GetError());
return (-1);
}

se.screen=SDL_SetVideoMode(1700,850,32, SDL_HWSURFACE |SDL_DOUBLEBUF);
se.image=SDL_LoadBMP("marche2.bmp");
se.imagemap=SDL_LoadBMP("map2.bmp");

se.positionecran.x=0;
se.positionecran.y=0;
se.positionecran.w=se.image->w;
se.positionecran.h=se.image->h;
se.positionecran1.x=0;
se.positionecran1.y=0;
se.positionecran1.w=se.image->w;
se.positionecran1.h=se.image->h;

se.positionmap.x=700;
se.positionmap.y=690;
se.positionmap.w=se.imagemap->w;
se.positionmap.h=se.imagemap->h;


en.positionsp.x=200;
en.positionsp.y=260;
d.positionperso.x=800;
d.positionperso.y=260;

en.intermin=60;
en.intermax=360;
en.intermapp=240;
en.intermap=260;

en.positionalea.x=370;
en.positionalea.y=127;
en.positionalea2.x=70;
en.positionalea2.y=127;
positionvieA.x=340;
positionvieA.y=0;
positionvieB.x=390;
positionvieB.y=0;
positionvieC.x=440;
positionvieC.y=0;

s.position_score.x=60;
s.position_score.y=0;

ob.position_objet.x=900;
ob.position_objet.y=273;
en.positionjoueur.x=740;
en.positionjoueur.y=736;

d.positionmape.x=790;
d.positionmape.y=736;

o.postime.x=0;
o.postime.y=0;

imagevie1=IMG_Load("imagevie1.png");
imagevie2=IMG_Load("imagevie2.png");
imagevie3=IMG_Load("imagevie3.png");
en.imagedep=IMG_Load("imagedep.png");
d.imageperso=IMG_Load("imageperso.png");
d.imagemape=IMG_Load("imagemape.png");
en.imagealea=IMG_Load("imagealea.png");
en.imagealea2=IMG_Load("imagealea2.png");

SDL_BlitSurface(se.image,&se.positionecran1,se.screen,&se.positionecran);
SDL_BlitSurface(se.imagemap,NULL,se.screen,&se.positionmap);
SDL_BlitSurface(en.imagedep,NULL,se.screen,&en.positionsp);
SDL_BlitSurface(en.imagealea,NULL,se.screen,&en.positionalea);
SDL_BlitSurface(en.imagealea2,NULL,se.screen,&en.positionalea2);
SDL_BlitSurface(d.imageperso,NULL,se.screen,&d.positionperso);
SDL_BlitSurface(d.imagemape,NULL,se.screen,&d.positionmape);

while(done)
{
SDL_EnableKeyRepeat(6,6);
SDL_PollEvent(&event);
  switch(event.type) 
    {
       case SDL_QUIT: 
         done = 0; 
        SDL_Quit();
          break;
          case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
                {case SDLK_t:
                        s.state=s.state+1;
                          break;                  
                    case SDLK_y:                                                 
                        s.state=s.state-1;
                          break;                                               
                    case SDLK_LEFT:  
			d.positionperso.x += -4; 
			d.positionmape.x +=-1;
                         break;
                    case SDLK_RIGHT:
			d.positionperso.x += 4; 
			d.positionmape.x +=1;
                        break;
                    case SDLK_a: 
                       s.sscore=s.sscore+10; 
                         break;
                 }
     break;
  }
v=vie(&s,v);
deplacement_perso(&d);

if(d.start==1)
{
DepAlea(&en,&d);
}
initialiser_score(&s,se);
init_obj(se,&ob);
menu(se,&en);

switch(v)
{
case 1: 
SDL_BlitSurface(se.image,&se.positionecran1,se.screen,&se.positionecran);
SDL_BlitSurface(se.imagemap,NULL,se.screen,&se.positionmap);
SDL_BlitSurface(en.imagedep,NULL,se.screen,&en.positionsp);
SDL_BlitSurface(en.imagealea,NULL,se.screen,&en.positionalea);
SDL_BlitSurface(en.imagealea2,NULL,se.screen,&en.positionalea2);
SDL_BlitSurface(d.imageperso,NULL,se.screen,&d.positionperso);
SDL_BlitSurface(d.imagemape,NULL,se.screen,&d.positionmape);
SDL_BlitSurface(imagevie1,NULL,se.screen,&positionvieA);
SDL_BlitSurface(imagevie2,NULL,se.screen,&positionvieB);
SDL_BlitSurface(imagevie3,NULL,se.screen,&positionvieC);
init_obj(se,&ob);
menu(se,&en);
break;
case 2:
SDL_BlitSurface(se.image,&se.positionecran1,se.screen,&se.positionecran);
SDL_BlitSurface(se.imagemap,NULL,se.screen,&se.positionmap);
SDL_BlitSurface(en.imagedep,NULL,se.screen,&en.positionsp);
SDL_BlitSurface(en.imagealea,NULL,se.screen,&en.positionalea);
SDL_BlitSurface(en.imagealea2,NULL,se.screen,&en.positionalea2);
SDL_BlitSurface(d.imageperso,NULL,se.screen,&d.positionperso);
SDL_BlitSurface(d.imagemape,NULL,se.screen,&d.positionmape);
SDL_BlitSurface(imagevie1,NULL,se.screen,&positionvieA);
SDL_BlitSurface(imagevie2,NULL,se.screen,&positionvieB);
init_obj(se,&ob);
menu(se,&en);
break;
case 3:
SDL_BlitSurface(se.image,&se.positionecran1,se.screen,&se.positionecran);
SDL_BlitSurface(se.imagemap,NULL,se.screen,&se.positionmap);
SDL_BlitSurface(en.imagedep,NULL,se.screen,&en.positionsp);
SDL_BlitSurface(en.imagealea,NULL,se.screen,&en.positionalea);
SDL_BlitSurface(en.imagealea2,NULL,se.screen,&en.positionalea2);
SDL_BlitSurface(d.imageperso,NULL,se.screen,&d.positionperso);
SDL_BlitSurface(d.imagemape,NULL,se.screen,&d.positionmape);
SDL_BlitSurface(imagevie1,NULL,se.screen,&positionvieA);
init_obj(se,&ob);
menu(se,&en);
break;
}
s.state=0;
}
SDL_Quit();
return 0;
}
