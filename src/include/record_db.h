#ifndef __RECORD_DBH_
#define __RECORD_DBH_
#include <stdbool.h>

typedef struct _record_db
{
  struct token_string_t * _key;
  struct token_string_t * _value;

  void(*set)(const char * key, const char * value);
  const char * (*get)(const char * key);

  //const char * (*insert_string)();      // Funzione che restituisce cosa deve andare a scrivere (Query)
  bool(*insert)();                        // Funzione che chiama il db per scrivere
}record_db_t;


#endif