// LemmiBase.cpp : définit le point d'entrée pour l'application.
//

#include "stdafx.h"
#include "LemmiBase.h"
#include <stdio.h>
//#include <SDL/SDL.h>
//#include <SDL/SDL_image.h>
//#include <FMOD/fmod.h>
#include "Engine.h"


#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")


#define MAX_LOADSTRING 100


// Variables globales :
HINSTANCE hInst;								// instance actuelle
TCHAR szTitle[MAX_LOADSTRING];					// Le texte de la barre de titre
TCHAR szWindowClass[MAX_LOADSTRING];			// le nom de la classe de fenêtre principale

HWND g_hSDL, g_hWnd, g_hDlgWnd, g_hTarget;
CEngine *g_engine;
RECT g_rectDecalageTarget;


// Pré-déclarations des fonctions incluses dans ce module de code :
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

INT_PTR CALLBACK	DlgProc(HWND, UINT, WPARAM, LPARAM);



int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO : placez ici le code.
	MSG msg;
	HACCEL hAccelTable;
	bool bGotMsg;
	//CEngine *engine; // Il faut qu'il soit global pour que WndProc puisse intéragir avec !

	// Initialise les chaînes globales
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_LEMMIBASE, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	
	// Inits globales
	g_hSDL = g_hWnd = g_hDlgWnd = g_hTarget = NULL;
	g_engine = new CEngine();
	g_engine->Init();
	
	
	// Effectue l'initialisation de l'application :
	// c'est à dire la création de la fenêtre.
	if (!InitInstance (hInstance, nCmdShow))
		return FALSE;

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LEMMIBASE));
	
	// Boucle de messages principale :
	PeekMessage(&msg, NULL, 0, 0, 0); // Don't remove, c'est juste pour avoir un premier message...
	while( msg.message != WM_QUIT )
	{
		bGotMsg = (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) != 0);
		if(bGotMsg)
		{
			if(IsWindow(g_hDlgWnd) && IsDialogMessage(g_hDlgWnd, &msg))
				;//continue;//*/
			if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			Sleep(1);
		}//*/
	}
	
	// Les codes de sortis
	g_engine->Quit();
	
	return (int) msg.wParam;
}



//
//  FONCTION : MyRegisterClass()
//
//  BUT : inscrit la classe de fenêtre.
//
//  COMMENTAIRES :
//
//    Cette fonction et son utilisation sont nécessaires uniquement si vous souhaitez que ce code
//    soit compatible avec les systèmes Win32 avant la fonction 'RegisterClassEx'
//    qui a été ajoutée à Windows 95. Il est important d'appeler cette fonction
//    afin que l'application dispose des petites icônes correctes qui lui sont
//    associées.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LEMMIBASE));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_LEMMIBASE);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FONCTION : InitInstance(HINSTANCE, int)
//
//   BUT : enregistre le handle de l'instance et crée une fenêtre principale
//
//   COMMENTAIRES :
//
//        Dans cette fonction, nous enregistrons le handle de l'instance dans une variable globale, puis
//        créons et affichons la fenêtre principale du programme.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Stocke le handle d'instance dans la variable globale

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FONCTION : WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  BUT :  traite les messages pour la fenêtre principale.
//
//  WM_COMMAND	- traite le menu de l'application
//  WM_PAINT	- dessine la fenêtre principale
//  WM_DESTROY	- génère un message d'arrêt et retourne
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	RECT rect,rect2;
	WINDOWINFO wi;

	switch (message)
	{
	case WM_CREATE:
		g_hWnd = hWnd;
		// Création de la fenêtre sur laquelle on mettra les boutons.
		// Il est important que IDD_MAIN soit en Child dans Style
		g_hDlgWnd = CreateDialog(hInst, MAKEINTRESOURCE(IDD_MAIN), g_hWnd, DlgProc);
		// Création de la fenêtre d'accueille de SDL.
		g_hSDL = CreateDialog(hInst, MAKEINTRESOURCE(IDD_TARGET), g_hDlgWnd, DlgProc);
		
		// Adaptation de la fenêtre avec menu à la fenêtre sur laquelle on mettra les boutons
		GetClientRect(g_hDlgWnd, &rect);
		GetWindowInfo(g_hWnd, &wi);
		AdjustWindowRect(&rect, wi.dwStyle, true);
		MoveWindow(g_hWnd, wi.rcWindow.left+rect.left, wi.rcWindow.top+rect.top, rect.right-rect.left, rect.bottom-rect.top, true);
		ShowWindow(g_hDlgWnd, SW_SHOW); // Parce que des fois....
		
		// La fenêtre SDL aura les dimensions de IDC_TARGET qui appartient à DlgWnd.
		// Pour fiare un SetVideoMode, on aura besoin de ces dimensions.
		// Ce n'est pas ici, mais dans WM_SIZE qu'on règle la taille de IDD_TARGET.
		g_hTarget = GetDlgItem(g_hDlgWnd, IDC_TARGET);
		g_engine->StartEngine(g_hSDL, g_hTarget);
		
		// Enregistrement de la position relative du cadre Target dans DlgWnd.
		// Ceci permet de garder la même position pour l'avenir.
		GetWindowRect(g_hTarget, &rect);
		GetWindowRect(g_hDlgWnd, &rect2);
		g_rectDecalageTarget.left = rect2.left-rect.left;
		g_rectDecalageTarget.right = rect2.right-rect.right;
		g_rectDecalageTarget.top = rect2.top-rect.top;
		g_rectDecalageTarget.bottom = rect2.bottom-rect.bottom;
		break;

	case WM_SIZE:
		// Ici, le resize du cadre. Ceci implique évidement le resize des choses dedans.
		// Et c'est ici que ça se passe.
		if(hWnd != g_hWnd) // Utile ?
			return DefWindowProc(hWnd, message, wParam, lParam);
		
		GetClientRect(hWnd, &rect);
		SetWindowPos(g_hDlgWnd, NULL, 0, 0, rect.right, rect.bottom, SWP_NOZORDER);
		SetWindowPos(g_hTarget, NULL, 0-g_rectDecalageTarget.left, 0-g_rectDecalageTarget.top, rect.right-g_rectDecalageTarget.right, rect.bottom-rect.top-g_rectDecalageTarget.bottom, SWP_NOZORDER);
		SetWindowPos(g_hSDL, NULL, 0-g_rectDecalageTarget.left, 0-g_rectDecalageTarget.top, rect.right-g_rectDecalageTarget.right, rect.bottom-rect.top-g_rectDecalageTarget.bottom, SWP_NOZORDER);
		
		break;
	
	case WM_COMMAND:
		// Ici, ne devrait y avoir que les menus (puisque la fenêtre à boutons à ses messages vers DlgProc) et les raccourcis clavier
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Analyse les sélections de menu :
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO : ajoutez ici le code de dessin...
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Gestionnaire de messages pour la boîte de dialogue À propos de.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}


INT_PTR CALLBACK DlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	// Ici, on est dans la zone de gris.
	// (et aussi dans la fenêtre IDD_TARGET qui, à mon avis, est subclassed par SDL...)
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;
	case WM_DESTROY:
		PostQuitMessage(0);
			SendMessage(g_hWnd, message, wParam, lParam);
		break;
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Analyse les sélections de menu :
		switch (wmId)
		{
		//case IDM_ABOUT:
		default:
			SendMessage(g_hWnd, message, wParam, lParam);
			break;
		}
		break;
	case WM_RBUTTONDOWN:
		break;
	case WM_LBUTTONDOWN:
		break;
	}
	
	return (INT_PTR)FALSE;
}
