#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h> /* Inclusion du header de SDL_image (adapter le dossier au besoin) */
#include "back.h"

SDL_Surface* intialiser_imagedeFond(SDL_Surface* imagedeFond,SDL_Rect positionFond,int x,int y)
{

    SDL_Surface *ecran = NULL;
 /* Chargement d'une image Bitmap dans une surface */
imagedeFond = SDL_LoadBMP("ahmed.bmp");
if(imagedeFond==NULL)
{
printf("on ne peut pas telecharger l image :%s\n",SDL_GetError());
exit(1);
}
else
{
    positionFond.x = x;

    positionFond.y = y;
    positionfond.h=imagedeFond.h;
    positionFond.w=imagedeFond.w;
}

return (imagedeFond);
}

 void blit_image(SDL_Surface* imageDeFond,SDL_Surface* ecran,SDL_Rect positionFond)
{ 

 SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
}
   



