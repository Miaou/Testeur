#pragma once

#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <FMOD/fmod.h>
#include "BaseSprite.h"
#include "BaseMap.h"




class CEngine
{
public:
	CEngine(void);
	~CEngine(void);

	// Fcts d'interfaçage
	bool Init(HWND hSDLWnd);
	bool Quit();

	int StartEngine(HWND hSDLRect);
	void FrameMove();

	// Faisons les choses "bien"
private:
	// Fcts internes
	void DispatchMsg(SDL_Event sEvent);
	void OneStep();
	void DrawFrame();
	void RaiseSounds();

	// Variables internes
	HWND m_hSDL, m_hWndForPlace;
	SDL_Surface *m_sScreen;
	FSOUND_STREAM *m_musique;
	FSOUND_SAMPLE *m_sonPop;
	CBaseSprite *m_pSpritesMan;
	CBaseMap *m_pMapMan;
};
