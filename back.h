#ifndef BACK_H_INCLUDED
#define BACK_H_INCLUDED


#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
SDL_Surface* intialiser_imagedeFond(SDL_Surface* imagedeFond, SDL_Rect positionFond,int x,int y);
void blit_image(SDL_Surface* imageDeFond,SDL_Surface* ecran,SDL_Rect positionFond);

#endif//BACK_H_INCLUDED

