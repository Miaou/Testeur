// Faudra qu'on mette un petit truc de commentaires là, avec des jolis -------------------------

// Cette ligne, c'est pour que la version avec les fenètres Win32 marche...
#include "stdafx.h"
#include "BaseSprite.h"


CBaseSprite::CBaseSprite(void) : m_ppListeSprites(NULL)
{
	m_nSprites[MARCHER] = 8;
	m_nSprites[CHUTER] = 4;
	m_nSprites[MOURIR] = 15;
	m_nSprites[POUCE] = 15;
	m_nSprites[EXPLOSE] = 1;
}

CBaseSprite::~CBaseSprite(void)
{
	Reset();
}

bool CBaseSprite::ChargementSprites()
{
	int iCptAction = 0 ;
	int iCptSprite = 0 ;
	int iCptInit = 0 ;
	int kD, kG ;

	int iNiterSens = 0 ;
	int iNiterSprite = 0 ;

	int iDimension = N_ACTION*N_SENS*N_SPRITE;

	char szAction[128] ;
	char szSprite[128] ;
	char path[128];
	
	// Au cas où on ait quelque chose
	Reset();

	m_ppListeSprites = new SDL_Surface*[iDimension];

	// Initialisation du tableau de pointeur
	for(iCptInit=0; iCptInit<iDimension; iCptInit++)
		m_ppListeSprites[iCptInit] = NULL ;

	// Chargement des images dans le tableau
	for (iCptAction=0; iCptAction<N_ACTION; iCptAction++)
	{
		// Définition du nombre de sens et de sprite suivant l'action
		switch(iCptAction)
		{
		iNiterSprite = m_nSprites[iCptAction];
		case MARCHER:
			iNiterSens = 2;
			sprintf_s(szAction, sizeof(szAction), "Marche");
			break;
		case CHUTER:
			iNiterSens = 1;
			//iNiterSprite = 4;
			sprintf_s(szAction, sizeof(szAction), "Chute");
			break;
		case MOURIR:
			iNiterSens = 1;
			//iNiterSprite = 15;
			sprintf_s(szAction, sizeof(szAction), "Meurt");
			break;
		case POUCE:
			iNiterSens = 2;
			//iNiterSprite = 15;
			sprintf_s(szAction, sizeof(szAction), "ThumbsUp");
			break;
		case EXPLOSE:
			iNiterSens = 1;
			//iNiterSprite = 1;
			sprintf_s(szAction, sizeof(szAction), "Explose");
			break;
		/*case :
			iNiterSens = ;
			iNiterSprite = ;
			sprintf_s(szAction, sizeof(szAction), "");
			break;//*/
		default:
			break;
		}

		for (iCptSprite=0; iCptSprite<iNiterSprite; iCptSprite++)
		{
			kD = iCptAction*N_SENS*N_SPRITE + DROITE*N_SPRITE + iCptSprite ;
			kG = iCptAction*N_SENS*N_SPRITE + GAUCHE*N_SPRITE + iCptSprite ;
			
			sprintf_s(szSprite, sizeof(szSprite), "%02i", iCptSprite);
			sprintf_s(path, sizeof(path), "sprites_lemmings\\%s\\%s.png",szAction,szSprite);
			m_ppListeSprites[kD] = IMG_Load(path);
			
			if(iNiterSens == 2)
				m_ppListeSprites[kG] = rotozoomSurfaceXY(m_ppListeSprites[kD], 0., -1., 1., 0);
			
			if( (! m_ppListeSprites[kD])  ||  (! m_ppListeSprites[kG]) )
			{
				fprintf(stderr, "Erreur lors du chargement de %s\n", path) ;
				return false ;
			}
		}

	}
	
	return true ;

}
SDL_Surface* CBaseSprite::RecupererSprite(EAction aAction, ESens sSens, int iSprite)
{
	int k;
	k = aAction*N_SENS*N_SPRITE + sSens*N_SPRITE + iSprite ;

	if(! m_ppListeSprites)
		return NULL;

	return m_ppListeSprites[k];
}


void CBaseSprite::Reset()
{
	if(! m_ppListeSprites)
		return;
	
	for(unsigned i=0; i<N_ACTION*N_SENS*N_SPRITE; ++i)
		if(m_ppListeSprites[i])
			SDL_FreeSurface(m_ppListeSprites[i]);
	
	delete[] m_ppListeSprites;
	m_ppListeSprites = NULL;
}
