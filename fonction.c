#include "fonction.h"
SDL_Surface * intial_player(player *pl,int x,int y)
{
pl->joueur=IMG_load("image.png");
if(pl->joueur==NULL)
{printf("image not found",SDL_GetError());
return NULL;
}
else
{
SDL_Rect pospl;
pospl.x=x;
pospl.y=y;
pospl.h=pl->joueur.h:
pospl.w=pl->joueur.w;
}
return(pl->joueur);
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
void affiche_object(game_object *game_object,SDL_Rect pospl[],SDL_Surface *ecran)
{int i;
for(i=0;i<10;i++)
{SDL_BlitSurface(obj->objects[i].player.joueur,NULL,ecran,&pospl[i]);
}
}

