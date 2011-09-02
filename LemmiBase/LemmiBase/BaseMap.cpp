#include "StdAfx.h"
#include "BaseMap.h"



CBaseMap::CBaseMap(void)
{
}



CBaseMap::~CBaseMap(void)
{
}


bool CBaseMap::ChargementMaps()
{
	bg = IMG_Load("Maps\\Test_bg.png");
	fg = IMG_Load("Maps\\Test_fg.png");

	return (bg != NULL) && (fg != NULL);
}


BYTE CBaseMap::GetAlpha(int x, int y)
{
	// Bon, on se construit un petit GetPixel des familles...
	// ATTENTION, il est valable que dans le cas 32bpp
	if(! fg)
		return 0;
	
	int val=y*fg->pitch+x*4;
	BYTE *p;
	
	if(val < 0)
		return 0;
	if(val > fg->h*fg->pitch+fg->w*4)
		return 0;
	
	p = (BYTE *)fg->pixels + val;
	
	return p[3];
}


