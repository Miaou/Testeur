#pragma once


#include <SDL/SDL.h>
#include <SDL/SDL_image.h>



class CBaseMap
{
public:
	CBaseMap(void);
	~CBaseMap(void);

	bool ChargementMaps(); // On va se contenter d'une...
	//bool 
	BYTE GetAlpha(int x, int y);

//private:
	// Restons simple, vu que c'est du proto rapide.
	SDL_Surface *bg, *fg;
};
