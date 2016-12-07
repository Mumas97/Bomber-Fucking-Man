#ifndef CONSTANTE_H
#define CONSTANTE_H


// STRUCTURE BOMBERMAN

struct objet
{
  SDL_Surface *surface;
  SDL_Rect position;
};

typedef struct objet objet;

// CONSTANTES VALEURES DES CASES

#define VIDE 0
#define BRIQUE 2
#define MUR 1
#define MAX 100
#define PERSO 3

// CONSTANTES PIXEL

#define CASE 45
#define T_TAB 15



#endif 
