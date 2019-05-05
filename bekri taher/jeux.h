#ifndef JEUX
#define JEUX
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
typedef struct
{
SDL_Surface *screen;
SDL_Surface *image,*imagemap;
SDL_Rect positionecran,positionecran1,positionmap;
}sec;

typedef struct 
{
TTF_Font *font;
SDL_Surface *score;
SDL_Rect position_score;
int sscore;
int state;
}sco;

typedef struct
{
    TTF_Font *fonte;
    SDL_Surface * temp;
    SDL_Rect postime;
    int suiv,prec,tmp;
}obj;

typedef struct
{
    SDL_Surface *objet;
    SDL_Rect position_objet;
}objet;

typedef struct
{
SDL_Surface *imagedep,*imagejoueur,*imagealea,*imagealea2;
SDL_Rect positionsp,positionjoueur,positionalea,positionalea2;
int intermin;
int intermax;
int intermapp;
int intermap;
}ennemi;

typedef struct
{
SDL_Surface *imageperso,*imagemape;
SDL_Rect positionperso,positionmape;
int start;
}deplacement;


void initialiser_score(sco *s,sec se);
int vie(sco *s, int v);
void DepAlea(ennemi *en,deplacement *d);
void times(obj *o,sec se);
void init_obj(sec se,objet *ob);
void menu(sec se,ennemi *en);
void deplacement_perso(deplacement *d);
#endif
