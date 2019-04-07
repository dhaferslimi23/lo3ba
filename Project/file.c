#include<stdio.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_mixer.h"
#include"file.h"
void pauuse()
{
    int continuer = 1;
    SDL_Event event;
 
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
        }
    }
}

int fn_pre_menu(int *boucle_jeux)
{int v=1,done=1;
 SDL_Surface *background;
 SDL_Event test_event;
 SDL_Surface *screen;
 SDL_Surface *Play ;
 SDL_Rect positionscreen;
 SDL_Rect positionPlay;
 positionPlay.x=480;
 positionPlay.y=500;
 positionscreen.x=0;
 positionscreen.y=0;
 if(SDL_Init(SDL_INIT_VIDEO)!=0)
{printf("Unable to initialize SDL: %s\n",SDL_GetError());
return 1;}
screen= SDL_SetVideoMode(1087,666,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
if(screen==NULL)
{printf("Unable to set video mode: %s\n",SDL_GetError());
return 1;}

background= SDL_LoadBMP("pre menu.bmp");
Play = IMG_Load("pressanykey.png");

SDL_BlitSurface(background, NULL, screen , &positionscreen);
SDL_Flip(screen);
if(background==NULL)
{printf("Unable to load bitmap: %s\n",SDL_GetError());
return 1;}
SDL_BlitSurface(Play, NULL, screen, &positionPlay);
SDL_Flip(screen);
while(done==1)
{SDL_Delay(750);
 SDL_BlitSurface(background, NULL, screen , &positionscreen);
 SDL_Flip(screen);
 SDL_Delay(750);
 SDL_BlitSurface(Play, NULL, screen, &positionPlay);
 SDL_Flip(screen);
 SDL_PollEvent(&test_event); 
switch(test_event.type) 
{
case SDL_QUIT: 
done = 0; 
v=0;
boucle_jeux=0;
SDL_Quit();
break;
case SDL_KEYDOWN: 
     v=2;//menu
     done=0;
  break;  
}
}
return v;}//fin fn_pre_menu


int fn_menu(int *boucle_jeux)
{
int vpos=0,pos=1,done=1,x=0,y=0,v=2;
SDL_Event test_event;
SDL_Event quit;
SDL_Event m_event;

Uint8 *keystate;

SDL_Surface *background;
SDL_Surface *screen;
SDL_Surface *Play ;
SDL_Surface *Option ;
SDL_Surface *Quit ;
SDL_Surface *Play_press =NULL;
SDL_Surface *Option_press =NULL;
SDL_Surface *Quit_press=NULL ;

SDL_Rect positionscreen;
SDL_Rect positionPlay;
SDL_Rect positionOption;
SDL_Rect positionQuit;

positionPlay.x=780;
positionPlay.y=220;

positionOption.x=780;
positionOption.y=270;

positionQuit.x =780;
positionQuit.y =320;

positionscreen.x=0;
positionscreen.y=0;

if(SDL_Init(SDL_INIT_VIDEO)!=0)
{printf("Unable to initialize SDL: %s\n",SDL_GetError());
return 1;}
screen= SDL_SetVideoMode(1087,666,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
if(screen==NULL)
{printf("Unable to set video mode: %s\n",SDL_GetError());
return 1;}
background= SDL_LoadBMP("menu.bmp");
Play = IMG_Load("play.png");
Option = IMG_Load("options.png");
Quit = IMG_Load("quit.png");
Play_press = IMG_Load("play pressed.png");
Option_press = IMG_Load("option pressed.png");
Quit_press = IMG_Load("quit pressed.png");

SDL_BlitSurface(background, NULL, screen , &positionscreen);
SDL_Flip(screen);

if(background==NULL)
{printf("Unable to load bitmap: %s\n",SDL_GetError());
return 1;}

SDL_BlitSurface(Play_press, NULL, screen, &positionPlay);
SDL_Flip(screen);
SDL_BlitSurface(Option, NULL, screen, &positionOption);
SDL_Flip(screen);
SDL_BlitSurface(Quit, NULL, screen, &positionQuit);
SDL_Flip(screen);
while(done==1)
{
 SDL_PollEvent(&test_event); 
switch(test_event.type) 
{

case SDL_QUIT: 
done = 0; 
v=0;
boucle_jeux=0;
SDL_Quit();
break;
/*case SDL_KEYDOWN: 
switch(test_event.key.keysym.sym)
{

case SDLK_UP:

if(pos==2)
     {SDL_BlitSurface(background, NULL, screen , &positionscreen);
     SDL_BlitSurface(Play_press, NULL, screen, &positionPlay);
     SDL_BlitSurface(Option, NULL, screen, &positionOption);
     SDL_BlitSurface(Quit, NULL, screen, &positionQuit);
     SDL_Flip(screen);
     pos=1;
     }
else if(pos==3)
     {SDL_BlitSurface(background, NULL, screen , &positionscreen);
     SDL_BlitSurface(Play, NULL, screen, &positionPlay);
     SDL_BlitSurface(Option_press, NULL, screen, &positionOption);
     SDL_BlitSurface(Quit, NULL, screen, &positionQuit);
     SDL_Flip(screen);
     pos=2;}
break;

case SDLK_DOWN:
if(pos==1)
     {SDL_BlitSurface(background, NULL, screen , &positionscreen);
     SDL_BlitSurface(Play, NULL, screen, &positionPlay);
     SDL_BlitSurface(Option_press, NULL, screen, &positionOption);
     SDL_BlitSurface(Quit, NULL, screen, &positionQuit);
     SDL_Flip(screen);
     pos=2;}
else if(pos==2)
     {SDL_BlitSurface(background, NULL, screen , &positionscreen);
     SDL_BlitSurface(Play, NULL, screen, &positionPlay);
     SDL_BlitSurface(Option, NULL, screen, &positionOption);
     SDL_BlitSurface(Quit_press, NULL, screen, &positionQuit);
     SDL_Flip(screen);
     pos=3;
     SDL_PollEvent(&test_event);
switch(test_event.type)
  {case SDLK_KP_ENTER:
   done = 0; 
   v=0;
   SDL_Quit();
   break;
   }
      }
break;
}
break;*/
case SDL_MOUSEMOTION:

x = test_event.motion.x;
y = test_event.motion.y;

if((x >780)&&(x<875)&&(y<256)&&(y>220))
{
 SDL_BlitSurface(background, NULL, screen , &positionscreen);
 SDL_BlitSurface(Play_press, NULL, screen, &positionPlay);
 SDL_BlitSurface(Option, NULL, screen, &positionOption);
 SDL_BlitSurface(Quit, NULL, screen, &positionQuit);
     SDL_Flip(screen);
 pos=1;
SDL_PollEvent(&test_event);
switch(test_event.type)
  {case SDL_MOUSEBUTTONDOWN:
   done = 0; 
   v=3;
   SDL_Quit();
   break;
   }
}

else if((x >780)&&(x<875)&&(y>270 )&&(y<306))
{
 SDL_BlitSurface(background, NULL, screen , &positionscreen);
 SDL_BlitSurface(Play, NULL, screen, &positionPlay);
 SDL_BlitSurface(Option_press, NULL, screen, &positionOption);
 SDL_BlitSurface(Quit, NULL, screen, &positionQuit);
     SDL_Flip(screen);
  pos=2;
/*SDL_PollEvent(&test_event);
switch(test_event.type)
  {case SDL_MOUSEBUTTONDOWN:
   done = 0; 
   v=4;
   SDL_Quit();
   break;
   }*/

}

else if((x>780)&&(x<875)&&(y>320)&&(y<356))
{
 SDL_BlitSurface(background, NULL, screen , &positionscreen);
 SDL_BlitSurface(Play, NULL, screen, &positionPlay);
 SDL_BlitSurface(Option, NULL, screen, &positionOption);
 SDL_BlitSurface(Quit_press, NULL, screen, &positionQuit);
     SDL_Flip(screen);
 pos=3;
SDL_PollEvent(&test_event);
switch(test_event.type)
  {case SDL_MOUSEBUTTONDOWN:
   done = 0;
   boucle_jeux=0; 
   v=0;
   SDL_Quit();
   break;
   }
}
break; // fin souris
} //fin switch test event

keystate = SDL_GetKeyState(NULL);
if (keystate[SDLK_UP])
{
switch(pos)
 { case 2:
    SDL_BlitSurface(background, NULL, screen , &positionscreen);
     SDL_BlitSurface(Play_press, NULL, screen, &positionPlay);
     SDL_BlitSurface(Option, NULL, screen, &positionOption);
     SDL_BlitSurface(Quit, NULL, screen, &positionQuit);
     SDL_Flip(screen);
     pos=1;
break;
case 3:
SDL_BlitSurface(background, NULL, screen , &positionscreen);
     SDL_BlitSurface(Play, NULL, screen, &positionPlay);
     SDL_BlitSurface(Option_press, NULL, screen, &positionOption);
     SDL_BlitSurface(Quit, NULL, screen, &positionQuit);
     SDL_Flip(screen);
     pos=2;
break;
}

 }    
if (keystate[SDLK_DOWN])
{
switch(pos)
{ case 1:
     SDL_BlitSurface(background, NULL, screen , &positionscreen);
     SDL_BlitSurface(Play, NULL, screen, &positionPlay);
     SDL_BlitSurface(Option_press, NULL, screen, &positionOption);
     SDL_BlitSurface(Quit, NULL, screen, &positionQuit);
     SDL_Flip(screen);
     pos=2;
 break;
case 2:
     SDL_BlitSurface(background, NULL, screen , &positionscreen);
     SDL_BlitSurface(Play, NULL, screen, &positionPlay);
     SDL_BlitSurface(Option, NULL, screen, &positionOption);
     SDL_BlitSurface(Quit_press, NULL, screen, &positionQuit);
     SDL_Flip(screen);
     pos=3;
break;
}
}

 
} //fin while(done)
SDL_FreeSurface(background);
return v;}


int fn_play_menu(int *boucle_jeux)
{
int vpos=0,pos=1,done=1,x=0,y=0,v=2;
SDL_Event test_event;
SDL_Event quit;
SDL_Event m_event;



SDL_Surface *background;
SDL_Surface *screen;
SDL_Surface *Play ;
SDL_Surface *Option ;
SDL_Surface *Quit ;
SDL_Surface *Play_press =NULL;
SDL_Surface *Option_press =NULL;
SDL_Surface *Quit_press=NULL ;

SDL_Rect positionscreen;
SDL_Rect positionPlay;
SDL_Rect positionOption;
SDL_Rect positionQuit;

positionPlay.x=780;
positionPlay.y=220;

positionOption.x=780;
positionOption.y=270;

positionQuit.x =780;
positionQuit.y =320;

positionscreen.x=0;
positionscreen.y=0;

if(SDL_Init(SDL_INIT_VIDEO)!=0)
{printf("Unable to initialize SDL: %s\n",SDL_GetError());
return 1;}
screen= SDL_SetVideoMode(1087,666,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
if(screen==NULL)
{printf("Unable to set video mode: %s\n",SDL_GetError());
return 1;}
background= SDL_LoadBMP("menu.bmp");
Play = IMG_Load("resume game.png");
Option = IMG_Load("new game.png");
Quit = IMG_Load("return.png");
Play_press = IMG_Load("resume game pressed.png");
Option_press = IMG_Load("new game pressed.png");
Quit_press = IMG_Load("return pressed.png");

SDL_BlitSurface(background, NULL, screen , &positionscreen);
SDL_Flip(screen);

if(background==NULL)
{printf("Unable to load bitmap: %s\n",SDL_GetError());
return 1;}

SDL_BlitSurface(Play_press, NULL, screen, &positionPlay);
SDL_Flip(screen);
SDL_BlitSurface(Option, NULL, screen, &positionOption);
SDL_Flip(screen);
SDL_BlitSurface(Quit, NULL, screen, &positionQuit);
SDL_Flip(screen);
while(done==1)
{
 SDL_PollEvent(&test_event); 
switch(test_event.type) 
{

case SDL_QUIT: 
done = 0; 
v=0;
boucle_jeux=0;
SDL_Quit();
break;
case SDL_KEYDOWN: 
switch(test_event.key.keysym.sym)
{

case SDLK_UP:

if(pos==2)
     {SDL_BlitSurface(background, NULL, screen , &positionscreen);
     SDL_BlitSurface(Play_press, NULL, screen, &positionPlay);
     SDL_BlitSurface(Option, NULL, screen, &positionOption);
     SDL_BlitSurface(Quit, NULL, screen, &positionQuit);
     SDL_Flip(screen);
     pos=1;
     }
else if(pos==3)
     {SDL_BlitSurface(background, NULL, screen , &positionscreen);
     SDL_BlitSurface(Play, NULL, screen, &positionPlay);
     SDL_BlitSurface(Option_press, NULL, screen, &positionOption);
     SDL_BlitSurface(Quit, NULL, screen, &positionQuit);
     SDL_Flip(screen);
     pos=2;}
break;

case SDLK_DOWN:
if(pos==1)
     {SDL_BlitSurface(background, NULL, screen , &positionscreen);
     SDL_BlitSurface(Play, NULL, screen, &positionPlay);
     SDL_BlitSurface(Option_press, NULL, screen, &positionOption);
     SDL_BlitSurface(Quit, NULL, screen, &positionQuit);
     SDL_Flip(screen);
     pos=2;}
else if(pos==2)
     {SDL_BlitSurface(background, NULL, screen , &positionscreen);
     SDL_BlitSurface(Play, NULL, screen, &positionPlay);
     SDL_BlitSurface(Option, NULL, screen, &positionOption);
     SDL_BlitSurface(Quit_press, NULL, screen, &positionQuit);
     SDL_Flip(screen);
     pos=3;
     SDL_PollEvent(&test_event);
switch(test_event.type)
  {case SDLK_KP_ENTER:
   done = 0; 
   v=0;
   SDL_Quit();
   break;
   }

}
break;
}
case SDL_MOUSEMOTION:

x = test_event.motion.x;
y = test_event.motion.y;

if((x >780)&&(x<875)&&(y<256)&&(y>220))
{
 SDL_BlitSurface(background, NULL, screen , &positionscreen);
 SDL_BlitSurface(Play_press, NULL, screen, &positionPlay);
 SDL_BlitSurface(Option, NULL, screen, &positionOption);
 SDL_BlitSurface(Quit, NULL, screen, &positionQuit);
     SDL_Flip(screen);
 pos=1;
SDL_PollEvent(&test_event);
switch(test_event.type)
  {case SDL_MOUSEBUTTONDOWN:
   done = 0; 
   v=4;
   SDL_Quit();
   break;
   }
}

else if((x >780)&&(x<875)&&(y>270 )&&(y<306))
{
 SDL_BlitSurface(background, NULL, screen , &positionscreen);
 SDL_BlitSurface(Play, NULL, screen, &positionPlay);
 SDL_BlitSurface(Option_press, NULL, screen, &positionOption);
 SDL_BlitSurface(Quit, NULL, screen, &positionQuit);
     SDL_Flip(screen);
  pos=2;
/*SDL_PollEvent(&test_event);
switch(test_event.type)
  {case SDL_MOUSEBUTTONDOWN:
   done = 0; 
   v=4;
   SDL_Quit();
   break;
   }*/

}

else if((x>780)&&(x<875)&&(y>320)&&(y<356))
{
 SDL_BlitSurface(background, NULL, screen , &positionscreen);
 SDL_BlitSurface(Play, NULL, screen, &positionPlay);
 SDL_BlitSurface(Option, NULL, screen, &positionOption);
 SDL_BlitSurface(Quit_press, NULL, screen, &positionQuit);
     SDL_Flip(screen);
 pos=3;
SDL_PollEvent(&test_event);
switch(test_event.type)
  {case SDL_MOUSEBUTTONDOWN:
   done = 0;
   v=2;
   SDL_Quit();
   break;
   }
}
break; // fin souris
} //fin switch test event 
} //fin while(done)
SDL_FreeSurface(background);
return v;}//fin play menu


int fn_ingame(int *boucle_jeux)
{int v=4,done=1;
SDL_Surface *background;
SDL_Surface *screen;
SDL_Surface *perso;
SDL_Surface *map;
SDL_Event test_event;
SDL_Rect position;
SDL_Rect positionperso;
SDL_Rect positionscreen;
positionscreen.x=0;
positionscreen.y=0;
position.x=0;
position.y=-7334;
positionperso.x=50;
positionperso.y=500;


SDL_Init(SDL_INIT_VIDEO);
 if(SDL_Init(SDL_INIT_VIDEO)!=0)
{printf("Unable to initialize SDL: %s\n",SDL_GetError());
return 1;}
screen= SDL_SetVideoMode(1087,666,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
if(screen==NULL)
{printf("Unable to set video mode: %s\n",SDL_GetError());
return 1;}

background= SDL_LoadBMP("map.bmp");
perso = IMG_Load("perso.png");
map=IMG_Load("map.png");
SDL_BlitSurface(background, NULL, screen , &positionscreen);
SDL_Flip(screen);
if(background==NULL)
{printf("Unable to load bitmap: %s\n",SDL_GetError());
return 1;}

while(done==1)
{
 SDL_PollEvent(&test_event); 
switch(test_event.type) 
{
case SDL_QUIT: 
done = 0; 
v=0;
boucle_jeux=0;
SDL_Quit();
break;

case SDL_KEYDOWN: 
switch(test_event.key.keysym.sym)
{
case SDLK_ESCAPE:
     done=0;
     v=fn_esc_menu(boucle_jeux);//ingame menu escape
     break;
}
}//fin switch event
SDL_PollEvent(&test_event);
switch(test_event.type) 
{
case SDL_QUIT: 
done = 0; 
SDL_Quit();
break;
case SDL_KEYDOWN:
switch(test_event.key.keysym.sym)
                {
                    case SDLK_UP:// Flèche haut
                                                
                                                if (position.y <=7334)
                                                {
                                                position.y=position.y-1;

                                                break;
                                                }
                                                else
                                                {
                                                position.y=7334;
                                                break;
                                                }
                    case SDLK_DOWN: // Flèche bas
                                                if (position.y >=-7334 )
                                                {
                                                position.y=position.y-1;
                                                break;
                                                }
                                                else
                                                {
                                                position.y = -7334;
                                                break;
                                                }
                    case SDLK_LEFT: // Flèche gauche
                                              if (position.x <= 14913)
                                                {
                                                position.x=position.x+1;
                                                break;
                                                }
                                                else
                                                {
                                                position.x = 14913;
                                                break;
                                                }  
                                                
                 case SDLK_RIGHT: // Flèche droite
                                       if (position.x >= -14913)
                                                {
                                                position.x=position.x-1;
                                                break;
                                                }
                                                else
                                                {
                                                position.x =-14193;
                                                break;
                                                }
                                       
               
        }
break;
}//fin switch keydown
SDL_BlitSurface(map, NULL, screen , &position);
SDL_BlitSurface(perso, NULL, screen , &positionperso);
SDL_Flip(screen);
}//fin while
return v;}//fin fn_ingame



int fn_esc_menu(int *boucle_jeux)
{int v=1,done=1,x=0,y=0;
 SDL_Surface *background;
 SDL_Event test_event;
 SDL_Surface *screen;
 SDL_Surface *Play ;
SDL_Surface *Play_press =NULL;
 SDL_Rect positionscreen;
 SDL_Rect positionPlay;
 positionPlay.x=480;
 positionPlay.y=500;
 positionscreen.x=0;
 positionscreen.y=0;
 if(SDL_Init(SDL_INIT_VIDEO)!=0)
{printf("Unable to initialize SDL: %s\n",SDL_GetError());
return 1;}
screen= SDL_SetVideoMode(1087,666,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
if(screen==NULL)
{printf("Unable to set video mode: %s\n",SDL_GetError());
return 1;}

background= SDL_LoadBMP("pre menu.bmp");
Play = IMG_Load("quit.png");
Play_press=IMG_Load("quit pressed.png");
SDL_BlitSurface(background, NULL, screen , &positionscreen);
SDL_Flip(screen);
if(background==NULL)
{printf("Unable to load bitmap: %s\n",SDL_GetError());
return 1;}
SDL_BlitSurface(Play, NULL, screen, &positionPlay);
SDL_Flip(screen);
while(done==1)
{
 SDL_PollEvent(&test_event); 
switch(test_event.type) 
{
case SDL_QUIT: 
done = 0; 
v=0;
boucle_jeux=0;
SDL_Quit();
break;
case SDL_MOUSEMOTION:

x = test_event.motion.x;
y = test_event.motion.y;
if((x>480)&&(x<575)&&(y>500)&&(y<536))
{
 SDL_BlitSurface(background, NULL, screen , &positionscreen);
 SDL_BlitSurface(Play_press, NULL, screen, &positionPlay);
     SDL_Flip(screen);
SDL_PollEvent(&test_event);
switch(test_event.type)
  {case SDL_MOUSEBUTTONDOWN:
   done = 0; 
   v=2;
   break;
   }
}//fin if
break;
}//fin switch event
}//fin while
return v;}//fin ingame esc menu

