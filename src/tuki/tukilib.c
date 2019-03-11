#include "tukilib.h"
#include "token_string.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "object.h"
#include "recordset.h"

typedef struct db_t
{
  FILE * _db;
  recordset_t * _table;
} db_t;


/**
 * struct record_db_t;
 * struct token_string_t
 */

///////////////////////////////////////////////////////////////
// db_t
///////////////////////////////////////////////////////////////

// Wrapper and initializer for db_t [Tested 100%]
db_t * file_db()
{
  static db_t * db = NULL;
  
  if(db == NULL)
  {
    db = (db_t*) malloc(sizeof(db_t)); // Alloco struttura
    db->_db = fopen("perc.db", "r+");
  }

  return db;
}

// 01.Metodo write() della struttura // Tested 85%
FILE * stream(const char * file)
{
  db_t * db = file_db();
  static FILE * open_w;
  static const char * file_name;

  if(open_w == NULL)
  {
    open_w = fopen(file, "r+");
    if (open_w == NULL) {
      open_w = fopen(file, "w");
      fclose(open_w);
      open_w = fopen(file, "r+");
    }
    file_name = file;
  }
  else
  {
    if(strcmp(file, file_name) != 0) // Do per scontato che il file c'era (else) e quindi file_name non e` a NULL
    {
      fclose(open_w);
      open_w = fopen(file, "r+");
      file_name = file;
    }
  }

  return open_w;
}