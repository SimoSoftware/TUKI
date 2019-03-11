#include "record_db.h"
#include <stdlib.h>
#include <string.h>

/////////////////////////////////////////////////////////
// record_db_t
/////////////////////////////////////////////////////////
void(__set_sYmo_record_db)(const char * key, const char * value);
const char * (__get_sYmo_record_db)(const char * key);
bool (__insert_sYmo_record_db)();

record_db_t * new_recs_db()
{
  record_db_t* recset = malloc(sizeof(record_db_t));
  recset->_key    = "|";
  recset->_value  = "|";
  recset->set     = __set_sYmo_record_db;
  recset->get     = __get_sYmo_record_db;
  recset->insert  = __insert_sYmo_record_db;

  return recset;
}

void(__set_sYmo_record_db)(const char * key, const char * value)
{

}
const char * (__get_sYmo_record_db)(const char * key)
{
  if (key != NULL || strcmp(key, "") != 0)      // Se non mi hanno passato una chiave nulla o vuota
  {
    int counter = -1;
    bool ok = false;
    const char * keys = recset_db()->_key;
    const char * values = recset_db()->_value;
    const char * tok_key = strtok(keys, "|");
    const char * res;

    while (tok_key != NULL)
    {
      ++counter;
      if (strcmp(tok_key, key) == 0)
      {
        ok = true;
        break;
      }
      tok_key = strtok(NULL, "|");
    }
    if (ok)       // L'ho trovata
    {
      res = strtok(values, "|");
      for (int i = 1; i < counter + 1; i++)
        res = strtok(NULL, "|");
      return res;
    }
    file_db()->get(key);
  }
  return NULL;    // La chiave e` vuota
}

bool (__insert_sYmo_record_db)()
{

  return true;
}