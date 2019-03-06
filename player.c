#include "fonction.h"
SDL_Surface intialise_player(player *pl,int x,int y)
{
SDL_Rect pospl;(
/*Chargement d'une image Bitmap dans une surface */
imagedeFond = SDL_LoadBMP();
if (imagedeFond==NULL)
{
printf("on ne peut pas telecharger l image:%s\n",SDL_GetError());
exit(1);
}
else
{
pospl.x=x;
pospl.y=y;
pospl.h=pl->sprite.h:
pospl.w=pl->sprite.w;
}
return(player->sprite);
}
void display(player *pl,SDL_Rect pospl,SDL_Surface *ecran)
{
SDL_BlitSurface(pl->joueur,NULL,ecran,&pospl);
}
void initialize_objet(int x[],int y[],game_object *game_object,object_name t_obj[])
{int i;
SDL_Rect pospl[10];
for(i=0;i<10;i++)
{obj->objects[i].player.joueur=IMG_load("%s.png",t_obj[i]);
pospl[i].x=x[i];
pospl[i].y=y[i];
}
}
