#ifndef RECORDSETH
#define RECORDSETH

#include "token_string.h"

typedef struct recordset_t recordset_t;

// Istanziatori
recordset_t * new_recordset_t();
recordset_t * new2_recordset_t(token_string_t * keys, token_string_t ** rows);

// Funzioni
void  set_recordset       (recordset_t * this, token_string_t * keys, token_string_t ** rows);
void  clean_recordset     (recordset_t * this);
char* get_field_recordset (const char * flield);
#endif