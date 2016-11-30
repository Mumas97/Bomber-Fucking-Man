#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "menu.h"



int main(void)
{
  
  SDL_Surface *menu = NULL, *ecran = NULL;
  
  menujeu(menu, ecran);

  return EXIT_SUCCESS;

}
  
