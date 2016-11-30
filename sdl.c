#include<stdio.h>
#include<stdlib.h>
#include"constante.h"
#include<SDL/SDL.h>

void remplissage(int map[T_TAB][T_TAB]);
void affichage(int map[T_TAB][T_TAB]);

int main(void)
{
  SDL_Surface *mur= NULL, *ecran = NULL, *vide = NULL, *brique = NULL;
  SDL_Event event;
  int map[T_TAB][T_TAB];
  SDL_Rect position[T_TAB][T_TAB];
  int continuer = 1;
  int i,j;
  
  remplissage(map);
  affichage(map); 
  SDL_Init(SDL_INIT_VIDEO);

  ecran = SDL_SetVideoMode(675, 675, 32, SDL_HWSURFACE);
  SDL_WM_SetCaption("Bomber-Man", NULL);
  
  brique = SDL_LoadBMP("BRIQUE.bmp");
  mur = SDL_LoadBMP("MUR.bmp");
  vide = SDL_LoadBMP("VIDE.bmp");

  for(i = 0; i<T_TAB; i++)
  {
    for(j = 0; j<T_TAB; j++)
    {

        position[i][j].x = i*CASE;
        position[i][j].y = j*CASE;  
    }
  }
  



// ECRAN PAUSE

while(continuer)
{
  SDL_WaitEvent(&event);
  switch(event.type)
  {
    case SDL_QUIT:
    continuer = 0;
    break;
  }

  for(i = 0; i<T_TAB; i++)
  {
    for(j = 0; j<T_TAB; j++)
    {
      if(map[i][j] == 0)
      {
        SDL_BlitSurface(vide, NULL, ecran, &(position[i][j]));
      }
      else if(map[i][j] == 1)
      {
        SDL_BlitSurface(mur, NULL, ecran, &(position[i][j]));
      }
      else if(map[i][j] == 2)
      {
        SDL_BlitSurface(brique, NULL, ecran, &(position[i][j]));
      }
    }
  }
  
  SDL_Flip(ecran);
}

SDL_Flip(ecran);


return EXIT_SUCCESS;  
}
