#ifndef FONCTION_H
#define FONCTION_H

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>

typedef struct player
{
SDL_Surface *joueur;
int invicibleTimer;
int x;
int y;
int h;
int w;
int life;
int frameNumber;
int frameTimer;
int etat;
int direction;
int onGround;
int timerMort;
int jump;
int saveX;
int saveY;
int checkpointActif;
int type;
}player;
typedef struct game_object
{player pl;
player objects[10];
player ennemies[10];
player ennemie_leader;
}game_object;
typedef struct object_name
{char nom[10];
}object_name;
void initialize_objet(int x[],int y[],game_object *game_object,object_name t_obj[]);
void display(player *pl,SDL_Rect pospl,SDL_Surface *ecran);
 SDL_Surface * initialize_player(player *pl,int x,int y);
void affiche_object(game_object *game_object,SDL_Rect pospl[],SDL_Surface *ecran)
#endif


