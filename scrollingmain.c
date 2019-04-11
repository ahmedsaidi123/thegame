   #include "structs.h"

    int main( int argc, char *argv[ ] )
   {
    int go;

if (SDL_Init(SDL_INIT_VIDEO ) < 0)
    {
        printf("Could not initialize SDL: %s\n", SDL_GetError());
        return 1;
    }


     /* On crée la fenêtre, représentée par le pointeur jeu.screen en utilisant la largeur et la
     hauteur définies dans les defines (defs.h). On utilise aussi la mémoire vidéo
     (SDL_HWPALETTE) et le double buffer pour éviter que ça scintille
     (SDL_DOUBLEBUF) */

    jeu.screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 0,
                                                        SDL_HWPALETTE|SDL_DOUBLEBUF);

     /* Si on y arrive pas, on quitte */

    if (jeu.screen == NULL)
        {
            printf("Couldn't set screen mode to %d x %d: %s\n", SCREEN_WIDTH,  
                     SCREEN_HEIGHT, SDL_GetError());
            exit(1);
        }


    /* On entre le titre de la fenêtre */

    SDL_WM_SetCaption("background", NULL);
initializePlayer();
      loadGame();

      atexit(cleanup);
go = 1;

    /* Boucle infinie, principale, du jeu */

    while (go == 1)
    {

        /* On vérifie l'état des entrées  */
        getInput();
    /* Affiche l'écran */
    SDL_Flip(jeu.screen);
     /* On met à jour le jeu */
        updatePlayer();

        /* On affiche tout */
draw();
    }

    /* Exit */
    exit(0);

    }
