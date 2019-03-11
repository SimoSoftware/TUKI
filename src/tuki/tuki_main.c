#include <stdio.h>
#include "player.h"
#include "token_string.h"
#include <yvals.h>
#include "tukilib.h"
#include <windows.h>
//#include <WinDef.h>

int APIENTRY _tWinMain(HINSTANCE hInst, HINSTANCE hPrev, LPSTR lpCmdLine, int nCmdShow)
{
  int energia_rimasta = 0;
  int danni_subiti    = 0;
  int x_pacco = 0;
  int y_paco  = 0;

	//HWND    hWnd;
	
	

#ifdef WINAPI
	//lpText = ();
	//LPCTSTR lpCaption = "Prova Message";
	//UINT    uType = MB_OK;
	MessageBox(NULL, "Ciaonee", "Prova Message", MB_ICONERROR);
#endif
  FILE * file = stream("prova.txt");

  fprintf(file, "Ciaone");

  //tuki_turn( energia_rimasta,  danni_subiti,  x_pacco,  y_paco);
  return 0;
}
