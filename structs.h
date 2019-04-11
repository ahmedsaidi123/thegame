  #include <stdio.h>
  #include <string.h>
  #include <stdlib.h>
  #include <math.h>
  #include <SDL/SDL.h>
  #include <SDL/SDL_image.h>
  #include <SDL/SDL_ttf.h>
  #include <SDL/SDL_mixer.h>

 /* Taille de la fenêtre / résolution en plein écran */
  #define SCREEN_WIDTH 640
  #define SCREEN_HEIGHT 400

 /* Valeur RGB pour la transparence (canal alpha) */
 #define TRANS_R 255
 #define TRANS_G 0
 #define TRANS_B 255

 /* Taille d'une tile (32 x 32 pixels) */
 #define TILE_SIZE 32

 /* Taille du sprite de notre héros (largeur = width et hauteur = heigth) */
   #define PLAYER_WIDTH 72
   #define PLAYER_HEIGTH 144

   //Vitesse de déplacement en pixels du sprite
   #define PLAYER_SPEED 4
   
    //Valeurs attribuées aux états/directions
   #define RIGHT 1
   #define LEFT 2

  /* Structure pour gérer l'input (clavier puis joystick) */

   typedef struct Input
  {

    int left, right,cursor;
    SDL_Rect positionclic;

  } Input;


  /* Structure pour gérer le niveau  */

  typedef struct Gestion
  {

    SDL_Surface *screen;

  } Gestion;
  /* Structure pour gérer la map à afficher (à compléter plus tard) */

 typedef struct Map
 {

    SDL_Surface *background;
     /* Coordonnées de début, lorsqu'on doit dessiner la map */
    int startX, startY;
int maxX,maxY;

 } Map;

 /* Structure pour gérer notre héros */

   typedef struct Hero
   {
       //Sprite du héros
       SDL_Surface *sprite;

       /* Coordonnées du héros */
       int x, y;

   /* Largeur, hauteur du sprite */
    int h, w;
    float dirX, dirY;
    int saveX, saveY;
   } Hero;
   Hero player;
  Map map;
  Gestion jeu;
Input input;
 void drawImage(SDL_Surface *image, int x, int y);
SDL_Surface *loadImage(char *name);
void loadGame(void);
 void cleanup();
  void getInput();
 void updatePlayer(void);
void initializePlayer(void);
 void drawplayer();
void draw(void);

