#include <stdio.h>
#include "player.h"
#include "token_string.h"
#include <yvals.h>
#include "tukilib.h"

int main()
{
  int energia_rimasta = 0;
  int danni_subiti    = 0;
  int x_pacco = 0;
  int y_paco  = 0;

  FILE * file = stream("prova.txt");

  fprintf(file, "Ciaone");

  //tuki_turn( energia_rimasta,  danni_subiti,  x_pacco,  y_paco);
  return 0;
}
