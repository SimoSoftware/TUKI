/*Defined direction*/
#define BTFH 32 
#define BTFW 32

#ifndef PLAYER
typedef enum  {MELA,BOMBA} pacco;
typedef enum  {MANGIA,DISTRUGGI} azione;
typedef struct  {
  int x; 
  int y; 
  pacco proiettile; //cosa ha lanciato
} lancio;

azione tuki_turn(int energia_rimasta, int danni_subiti, int x_pacco, int y_paco);
#define PLAYER 
#endif


