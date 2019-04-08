int affichEnigme(int x , SDL_Surface*screen , *image , SDL_Rect positionecran){
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
SDL_FreeSurface(image);
return 1;
}

int Win(SDL_Surface *screen , SDL_Surface *image, SDL_Rect positionecran){
	image=SDL_LoadBMP("Winner.bmp");
	SDL_BlitSurface(image,NULL,screen,&positionecran);
	SDL_Flip(screen);
return 1;
}
int Lose(SDL_Surface *screen , SDL_Surface *image, SDL_Rect positionecran){
 image=SDL_LoadBMP("Loser.bmp");
 SDL_BlitSurface(image,NULL,screen,&positionecran);
 SDL_Flip(screen);
return 1;
}
int ReponseEnigme(SDL_Event test , int x){
int done =1;
		while(done){
		SDL_WaiteEvent(&event);
		switch(event.type){
		case SDL_QUIT:
			done = 0; 
		break;

		case SDL_KEYDOWN:
			switch(test_event.key.keysym.sym){
			case SDLK_ESCAPE:
					done=0;
			break;
			}
		case SDL_KEYDOWN :
		if (x==0){ 
		switch(event.key.keysym.sym)
		{
		case SDLK_1 : 
			Win(*screen , *image ,positionecran);
			else {
				Lose(*screen , *image ,positionecran);
			     }
		break;
		}
		if (x==1){ 
		switch(event.key.keysym.sym)
		{
		case SDLK_3 : 
			Win(*screen , *image ,positionecran);
			else {
				Lose(*screen , *image ,positionecran);
			     }
		break;
		}
		if (x==2) {
		switch(event.key.keysym.sym)
		{
		case SDLK_4 : 
			Win(*screen , *image ,positionecran);
			else {
				Lose(*screen , *image ,positionecran);
			     }
		break;
return1;
}	
