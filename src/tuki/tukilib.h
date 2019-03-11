#ifndef __TUKILIBH__
#define __TUKILIBH__

#include <stdio.h>

typedef struct db_t db_t;

// Modo di accesso interno per dati percettrone
db_t * file_db();
FILE * stream(const char * file);

#endif