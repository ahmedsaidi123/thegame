void initializeMonster(int x, int y, ennemi *enn)
{
	if (enn->jeu.nombreMonstres < MONSTRES_MAX)
	{
		enn->monster[enn->jeu.nombreMonstres].sprite =
			loadImage("monster1.bmp", enn);
		enn->monster[enn->jeu.nombreMonstres].direction = LEFT;
		enn->monster[enn->jeu.nombreMonstres].frameNumber = 0;
		enn->monster[enn->jeu.nombreMonstres].frameTimer =
			TIME_BETWEEN_2_FRAMES;
		enn->monster[enn->jeu.nombreMonstres].x = x;
		enn->monster[enn->jeu.nombreMonstres].y = y;
		enn->monster[enn->jeu.nombreMonstres].w = TILE_SIZE;
		enn->monster[enn->jeu.nombreMonstres].h = TILE_SIZE;
		enn->monster[enn->jeu.nombreMonstres].timerMort = 0;
		enn->monster[enn->jeu.nombreMonstres].onGround = 0;
		enn->jeu.nombreMonstres++;
	}
}
void affmonster(ennemi *enn,SDL_Surface *ecran)
{
SDL_Rect	pos;
pos.x=enn->monster[enn->jeu.nombreMonstres].x;
pos.y=enn->monster[enn->jeu.nombreMonstres].y ;
enn->monster[enn->jeu.nombreMonstres].timerMort = 100;
enn->monster[enn->jeu.nombreMonstres].onGround = 1;
SDL_BlitSurface(enn->monster.sprite, NULL, ecran, &pos);
}
