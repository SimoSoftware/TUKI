/////////////////////////////////////////////////////////////
// recordset_t
/////////////////////////////////////////////////////////////
#include "recordset.h"
#include "object.h"
#include <stddef.h>

typedef struct recordset_t
{
  cobject *         _obj;
  token_string_t *  _keys;
  token_string_t ** _rows;
  int               _pos_cur;
} recordset_t;

// Istanziatori
recordset_t * new_recordset_t()
{
  return NULL;
}

recordset_t * new2_recordset_t(token_string_t * keys, token_string_t ** rows)
{
  return NULL;
}

void  set_recordset(recordset_t * this, token_string_t * keys, token_string_t ** rows)
{
  
}

void  clean_recordset(recordset_t * this)
{
  
}

char * get_field_recordset(const char * flield)
{
  //const char * ;
  return "";
}