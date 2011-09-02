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
}

CEngine::~CEngine(void)
{
	// Automatique...
}


bool CEngine::Init(void)
{
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
int CEngine::StartEngine(HWND hSDLWnd, HWND hSDLRect)
{
	char wndID[32];
	RECT rct;
	
	m_hSDL = hSDLWnd;
	m_hWndForPlace = hSDLRect;
	
	// SDL_WINDOWID hack
	sprintf_s(wndID, 32, "SDL_WINDOWID=%u", m_hSDL);
	_putenv(wndID);

	// Création de la fenêtre SDL
	GetClientRect(m_hWndForPlace, &rct);
	m_sScreen = SDL_SetVideoMode(rct.right-rct.left, rct.bottom-rct.top, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
	
	// Chargement des images
	m_pSpritesMan = new CBaseSprite();
	m_pSpritesMan->ChargementSprites(); // gérer le if...
	
	// Les musiques
	m_musique = FSOUND_Stream_Open("Sons//PuyoCool.mp3", FSOUND_LOOP_NORMAL, 0, 0);
	
	// Les sons
	m_sonPop = FSOUND_Sample_Load(FSOUND_FREE, "Sons//Pop.wav", 0, 0, 0);
	
	// Tout est prêt, on celebrate !
	SDL_Flip(m_sScreen);
	FSOUND_Stream_Play(FSOUND_FREE, m_musique);
	FSOUND_Stream_SetLoopCount(m_musique,-1);
	
	return 0; // Tout va bien ! Car je n'ai géré aucun des problèmes potentiels...
}


