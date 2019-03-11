#include "player.h"
#include <stdlib.h>
#include <time.h>
#include "tukilib.h"


/**
 * 0) Ogni turno di gioco (lancio) Tuki perde 1 livello di energia
 * 1) Se mangia una mela acquista un livello di energia
 * 2) Se distrugge una mela non capita nulla
 * 3) Se mangia una bomba produce 2 livelli di danni
 * 4) se distrugge una bomba recupera un livello di danni e uno di energia
 */
azione tuki_turn(int energia_rimasta, int danni_subiti, int x_pacco, int y_paco){
  /*static int init=0;
  if(!init)
    {
      srand(0);
      init=1;
    }*/
  
//  azione choose;
  const char * file = "log.txt";
  //FILE * write = file_db()->file_write;
  //FILE * stream = file_db()->write("test.log");


  //fprintf(stream, "CIaOne\n");
  
  

  /* ...logica 
  if(rand()%2)
    choose = DISTRUGGI;
  else
    choose = MANGIA;*/
  
  return MANGIA;
}
