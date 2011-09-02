#include "StdAfx.h"
#include "Engine.h"

CEngine::CEngine(void)
{
	m_hSDL = NULL;
	m_hWndForPlace = NULL;
	m_musique = NULL;
	m_pSpritesMan = NULL;
	m_sonPop = NULL;
	m_sScreen = NULL;
	m_pMapMan = NULL;
}

CEngine::~CEngine(void)
{
	// Automatique...
}


bool CEngine::Init(HWND hSDLWnd)
{
	char wndID[32];
	
	m_hSDL = hSDLWnd;	
	
	// SDL_WINDOWID hack
	sprintf_s(wndID, 32, "SDL_WINDOWID=%u", m_hSDL);
	_putenv(wndID);
	
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
		// Faudra s'étendre quand les logs seront en route...
		return false;

	FSOUND_Init(44100, 32, 0); // Erreur possible ?
	
	return true;
}


bool CEngine::Quit(void)
{
	// 1) SDL
	// Free all surfaces ?
	// Final Quit
	SDL_Quit();
	
	// 2) FMOD
	// Free musics and sounds ? C'est optionnel, il le fait tout seul...
	// Quit FMOD
	FSOUND_Close();
	
	return true;
}


// Ici, on va faire les chargements des images,
// des sons, de la musique
// hSDLWnd est la fenêtre dans laquelle s'afichera SDL
// hSDLRect est la fenêtre qui définit la taille de la fenêtre SDL (PictureControl classiquement)
int CEngine::StartEngine(HWND hSDLRect)
{
	RECT rct;
	
	m_hWndForPlace = hSDLRect;
	
	// Création de la fenêtre SDL
	GetClientRect(m_hWndForPlace, &rct);
	m_sScreen = SDL_SetVideoMode(rct.right-rct.left, rct.bottom-rct.top, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
	
	// Chargement des images
	m_pSpritesMan = new CBaseSprite(); // gérer le if...
	m_pSpritesMan->ChargementSprites(); // gérer le if...

	// Chargement des maps
	m_pMapMan = new CBaseMap(); // Gérer le if...
	m_pMapMan->ChargementMaps(); // -----------...
	
	// Les musiques (sans manager pour l'instant)
	m_musique = FSOUND_Stream_Open("Sons//PuyoCool.mp3", FSOUND_LOOP_NORMAL, 0, 0);
	
	// Les sons (idem)
	m_sonPop = FSOUND_Sample_Load(FSOUND_FREE, "Sons//Pop.wav", 0, 0, 0);
	
	// Tout est prêt, on celebrate !
	SDL_Flip(m_sScreen);
	FSOUND_Stream_Play(FSOUND_FREE, m_musique);
	FSOUND_Stream_SetLoopCount(m_musique,-1);
	
	return 0; // Tout va bien ! Car je n'ai géré aucun des problèmes potentiels...
}


void CEngine::FrameMove()
{
	// C'est ici qu'on fera tout le travail, à chaque image !
    SDL_Event sEvent;

	// 1) Dispatch les messages SDL. La fonction réagit selon le besoin
	// 2) On peut faire avancer le temps
	// 3) On dessine
	// 4) On met à jour les sons
	while(SDL_PollEvent(&sEvent))
		DispatchMsg(sEvent);
	OneStep();
	DrawFrame();
	RaiseSounds();
}


void CEngine::DispatchMsg(SDL_Event sEvent)
{
	RECT rect;

	switch(sEvent.type)
	{
	case SDL_MOUSEBUTTONDOWN:
		//SDL_FillRect(g_sEcran, NULL, SDL_MapRGB(g_sEcran->format, 255, 255, 255));
		break;
	case SDL_MOUSEMOTION:
		//sEvent.motion.x,sEvent.motion.y
		break;
	/*case SDL_KEYDOWN:
		break;//*/
	case SDL_VIDEORESIZE:
		GetClientRect(m_hWndForPlace, &rect);
		m_sScreen = SDL_SetVideoMode(rect.right-rect.left,rect.bottom-rect.top, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
		break;
	default:
		sEvent.type = sEvent.type; // Debug
		break;
	}
}


void CEngine::OneStep()
{
	// !!!
}


void CEngine::DrawFrame()
{
	SDL_FillRect(m_sScreen, NULL, 0);
	SDL_BlitSurface(m_pMapMan->bg, NULL, m_sScreen, NULL);
	SDL_BlitSurface(m_pMapMan->fg, NULL, m_sScreen, NULL);
	SDL_Flip(m_sScreen);
}


void CEngine::RaiseSounds()
{
	// !!!
}

