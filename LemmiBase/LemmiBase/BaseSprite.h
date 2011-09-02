// Petit texte d'intro
//
// BraChe 2010

#ifndef BASESPRITE_HEADER
#define BASESPRITE_HEADER

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_rotozoom.h>


// Valeur max du nombre de sprites par action 
#define N_SPRITE 15

enum EAction
{
	MARCHER = 0,
	CHUTER,
	MOURIR,
	POUCE,
	EXPLOSE,
	N_ACTION
};

enum ESens
{
	GAUCHE = 0,
	DROITE,
	N_SENS

};

class CBaseSprite
{
public:
	CBaseSprite(void);
	~CBaseSprite(void);
	bool ChargementSprites();
	SDL_Surface* RecupererSprite(EAction aAction, ESens sSens, int iSprite) ;

private:
	// Fonction de mise à zéro de la DB
	void Reset();
	
	// Tableau de surfaces SDL pour les images chargées
	SDL_Surface **m_ppListeSprites;
	// Tableau des nombres de sprites pour les actions correspondantes
	int m_nSprites[N_ACTION];
};



#endif // BASESPRITE_HEADER
