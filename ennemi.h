#ifndef ENNEMI_H
# define ENNEMI_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#define MONSTRES_MAX 50
#define LEFT 2
#define TIME_BETWEEN_2_FRAMES 8
#define TILE_SIZE 32
typedef struct	s_object
{
	SDL_Surface	*sprite;
	int			invicibleTimer;
	int			x;
	int			y;
	int			h;
	int			w;
	int			life;
	int			frameNumber;
	int			frameTimer;
	int			etat;
	int			direction;
	int			onGround;
	int			timerMort;
	int			jump;
	int			saveX;
	int			saveY;
	float		dirX;
	float		dirY;
	int			respawnY;
	int			checkpointActif;
	int			respawnX;
	int			beginX;
	int			beginY;
	int			type;
	int			player_dessus;
}t_object;
typedef struct	s_gestion
{
	int			nombreMonstres;
}gestion;
typedef struct ennemi
{
t_object	monster[MONSTRES_MAX];
gestion jeu;
}ennemi;
void initializeMonster(int x, int y, ennemi *enn);
void affmonster(ennemi *enn,SDL_Surface *ecran);
#endif

