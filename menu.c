#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <menu.h>


void menujeu(SDL_Surface *menu, SDL_Surface *ecran)
{
  menu = NULL;
  ecran = NULL;
  SDL_Event event;
  SDL_Rect position;
  int continuer = 1;


  // LANCER LA SDL

  SDL_Init(SDL_INIT_VIDEO);

  position.x = 0;
  position.y = 0;
  
  //INITIALISATION DE LA FENETRE

  ecran = SDL_SetVideoMode(675, 675, 32, SDL_HWSURFACE);
  SDL_WM_SetCaption("Bomber-Man", NULL);

  menu = SDL_LoadBMP("menu_un.bmp");

  SDL_BlitSurface(menu, NULL, ecran, &position);

  // ECRAN EN PAUSE

  while(continuer)
  {
    SDL_WaitEvent(&event);
    switch (event.type)
    {
      case SDL_QUIT:
        continuer = 0;
        break;

      case SDL_KEYDOWN:
      switch(event.key.keysym.sym)
      {
        case SDLK_DOWN:
        menu = SDL_LoadBMP("menu_deux.bmp");
        break;

        case SDLK_UP:
        menu = SDL_LoadBMP("menu_un.bmp");
        break;
      }
    }
    SDL_BlitSurface(menu, NULL, ecran, &position);
    SDL_Flip(ecran);
  }


// RENOUVELLER L'ECRAN




  SDL_Flip(ecran);
}
