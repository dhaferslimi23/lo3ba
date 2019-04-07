#include<stdio.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_mixer.h"
#include"file.h"

 

int main(void)
{
int boucle_jeux=1,v=1;
do
{ 
    switch(v)
      { 
        case 1:
           v=fn_pre_menu(&boucle_jeux);
        break;
        
        case 2:
           v=fn_menu(&boucle_jeux);
        break;
        case 3:
           v=fn_play_menu(&boucle_jeux);
        break;
        case 4:
           v=fn_ingame(&boucle_jeux);
        break;
      }
}while(v>0);    
pauuse();
SDL_Quit();
boucle_jeux=0;
return 0;
}
