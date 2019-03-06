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
SDL_Surface *sprite;
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
SDL_Surface* initialise_player(player *pl,int x,int y);
#endif			
