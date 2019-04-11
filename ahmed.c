#include "structs.h"

   void drawImage(SDL_Surface *image, int x, int y)
  {
       SDL_Rect dest;

       /* Règle le rectangle à blitter selon la taille de l'image source */

       dest.x = x;
       dest.y = y;
       dest.w = image->w;
       dest.h = image->h;

       /* Blitte l'image entière sur l'écran aux coordonnées x et y */

       SDL_BlitSurface(image, NULL, jeu.screen, &dest);
   }




   SDL_Surface *loadImage(char *name)
   {
       /* Charge une image temporaire avec SDL Image */

       SDL_Surface *temp = IMG_Load(name);
       SDL_Surface *image;

       /* Si elle n'est pas chargée on quitte avec une erreur */
      if (temp == NULL)
      {
           printf("Failed to load image %s\n", name);

          return NULL;
       }

       /* Ajoute la transparence à l'image temporaire en accord avec les defines TRANS_R, G, B */

       SDL_SetColorKey(temp, (SDL_SRCCOLORKEY | SDL_RLEACCEL), SDL_MapRGB(temp->format, TRANS_R, TRANS_G,    TRANS_B));

       /* Convertit l'image au format de l'écran (screen) pour un blit plus rapide */

       image = SDL_DisplayFormat(temp);
       
       /* Libère l'image temporaire */
       SDL_FreeSurface(temp);

       if (image == NULL)
       {
           printf("Failed to convert image %s to native format\n", name);

           return NULL;
       }

       /* Retourne l'image au format de l'écran pour accélérer son blit */

       return image;


   }

void loadGame(void)
    {

        /* Charge l'image du fond */
        map.background = loadImage("graphics/ahmed.bmp");

     }
 void cleanup()
   {

     /* Libère l'image du background */

      if (map.background != NULL)
      {
            SDL_FreeSurface(map.background);
      }
   
if (player.sprite != NULL)
      {
            SDL_FreeSurface(player.sprite);
      }

      /* Quitte la SDL */
      SDL_Quit();

    }
  void getInput()
 {
    SDL_Event event;

    /* Keymapping : gère les appuis sur les touches et les enregistre
    dans la structure input */

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {

            case SDL_QUIT:
                exit(0);
            break;

            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        exit(0);
                    break;

                    case SDLK_LEFT:
                        input.left = 1;
                    break;

                    case SDLK_RIGHT:
                        input.right = 1;
                    break;
                    default:
                    break;
                }
            break;

            case SDL_KEYUP:
                switch (event.key.keysym.sym)
                {

                    case SDLK_LEFT:
                        input.left = 0;
                    break;

                    case SDLK_RIGHT:
                        input.right = 0;
                    break;
                    default:
                    break;
                }
            break;
        case SDL_MOUSEBUTTONUP:
    if(event.button.button==SDL_BUTTON_LEFT)
{
input.cursor=1;
input.positionclic.x=event.button.x;
}
break;
        }

    }
 }

 void updatePlayer(void)
{
     if (input.right == 1)
    {
        player.x += PLAYER_SPEED;
         player.dirX-=1;
     
    }

    else if (input.left == 1)
    {
        player.x -= PLAYER_SPEED;
        player.dirX+=1;
  
    }

/* else if(input.cursor=1)
{
if(player.x<input.positionclic.x)
{
while(player.x<input.positionclic.x)
{
 player.x += PLAYER_SPEED;
         player.dirX-=1;
}
}
else if(player.x>input.positionclic.x)
{
while(player.x>input.positionclic.x)
{
 player.x -= PLAYER_SPEED;
         player.dirX+=1;
}
}

}*/
}


 void initializePlayer(void)
   {

       /* Charge le sprite de notre héros */
       player.sprite = loadImage("graphics/player.png");

      /* Coordonnées de démarrage de notre héros */
       player.x = 20;
       player.y = 200;

   }
  void drawplayer()
{
    /* Rectangle de destination à blitter */
    SDL_Rect dest;

    dest.x = player.x;
    dest.y = player.y;
    dest.w = PLAYER_WIDTH;
    dest.h = PLAYER_HEIGTH;

    /* Rectangle source à blitter */
    SDL_Rect src;

    src.x = 0;
    src.y = 0;
    src.w = PLAYER_WIDTH;
    src.h = PLAYER_HEIGTH;

    /* Blitte notre héros sur l'écran aux coordonnées x et y */

    SDL_BlitSurface(player.sprite, &src, jeu.screen, &dest);

}
void draw(void)
{

    drawImage(map.background, player.dirX,0);
drawplayer();
    /* Affiche l'écran */
    SDL_Flip(jeu.screen);

    /* Delai */

    SDL_Delay(1);

}


