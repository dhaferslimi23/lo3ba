#include<stdio.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include "Enigme.h"
int  affichEnigme(int x , SDL_Surface*screen , SDL_Surface*image , SDL_Rect positionecran){
switch (x) {
	case 0 :
		image =SDL_LoadBMP("0.bmp");
		SDL_BlitSurface(image,NULL,screen,&positionecran);
		SDL_Flip(screen);
	break;
	
	case 1 : 
		image=SDL_LoadBMP("1.bmp");
		SDL_BlitSurface(image,NULL,screen,&positionecran);
		SDL_Flip(screen);
	break;
	
	case 2 :
		image=SDL_LoadBMP("2.bmp");
		SDL_BlitSurface(image,NULL,screen,&positionecran);
		SDL_Flip(screen);
	break;
}
return 1;
}

int ReponseEnigme(SDL_Event test , int x){
int done =1;
		while(done){
		SDL_WaitEvent(&test);
		switch(test.type){
		case SDL_QUIT:
			done = 0; 
		break;

		case SDL_KEYDOWN:
			switch(test.key.keysym.sym){
			case SDLK_ESCAPE:
					done=0;
			break;
		
		if (x==0){ 
		switch(test.key.keysym.sym)
		{
		case SDLK_3 : 
			return 1 ;
		break;
		}
	        }
		if (x==1){ 
		switch(test.key.keysym.sym)
		{
		case SDLK_3 : 
			return 1;
		break;
		}
		}
		if (x==2) {
		switch(test.key.keysym.sym)
		{
		case SDLK_3 : 
			return 1;
		break; 
		}
		}
}
}
}
}
