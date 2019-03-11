#include "token_string.h"

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "object.h"

#define ALLOC(type) (type*)malloc(sizeof(type))
//#define FUNCTION(funct, type) __##funct##_sYmo__##type

typedef struct token_string_t {
cobject*    _obj;
char*       _str;
int         _counter_next;
const char* _delimiter;
} token_string_t;

token_string_t * NEW(token_string_t)()
{
  return NEW(token_string_t, 2)("", "|");
}

token_string_t * NEW(token_string_t, 2)(const char * string, const char * delimiter){
  token_string_t * obj = ALLOC(token_string_t);

  obj->_obj = ALLOC(cobject);
  obj->_obj->_name = "token_string_t";
  obj->_str = malloc(strlen(string) + 1 * sizeof(char));
  strcpy_s(obj->_str, strlen(string) + 1 * sizeof(char), string);
  obj->_counter_next = 0;
  obj->_delimiter = delimiter;

  return obj;
}

//void FUNCTION(add, token_string_t)(struct token_string_t * this, const char * str)
void add_tok(token_string_t * this, const char * str)
{
  const int len = strlen(this->_str) + strlen(str) + strlen(this->_delimiter);
  char * newstr = malloc(len + 1 * sizeof(char));

  strcpy_s(newstr, strlen(this->_str) + 1 * sizeof(char), this->_str);
  strcat_s(newstr, len + 1 * sizeof(char), str);
  strcat_s(newstr, len + 1 * sizeof(char), this->_delimiter);
  free(this->_str);
  this->_str = newstr;
}

char * get_pos_tok(token_string_t * this, const int pos)
{
  int itm = 0;

  this->_counter_next = pos;
  if ((itm = items_tok(this)) != 0 && pos >= 0 && itm > pos) // Items strettamente maggiore di pos!
  {
    char* str = get_tok(this->_str, this->_delimiter);
    for (int i = 1; i < pos + 1; i++)
      str = get_tok(NULL, this->_delimiter);
    return str;
  }
  return NULL;      // else
}

char * get_next_tok(struct token_string_t * this)
{
  char * str = get_pos_tok(this, this->_counter_next);
  this->_counter_next = this->_counter_next + 1;
  return str;
}

//int FUNCTION(items, token_string_t)(token_string_t * this)
int items_tok(token_string_t * this)
{
  int count = 0;
  const int len = strlen(this->_str);
  char delimiter = *this->_delimiter;
  if(len > 0)
  {
    const char * str = get_tok(this->_str, this->_delimiter);
    
    while (str != NULL)
    {
      ++count;
      str = get_tok(NULL, this->_delimiter);
    }
    return count;
  }
  return 0; // else
}

void clean_tok(struct token_string_t* this)
{
  free(this->_str);
  this->_str = malloc(sizeof(char));
  *this->_str = '\0';
}

void set_delim_tok(struct token_string_t* this, const char* str)
{
  this->_delimiter = str;
}

char * get_tok(char * str, const char * delimiter)
{
  static  char* string_tokenized = NULL;
  static  int   last_pos;
  static  int   len;
  const   bool  str_null = str == NULL;

  if (str_null && string_tokenized == NULL)   // Stringa mai passata e non passo nulla
  {
    last_pos = -1;
    len = 0;
    return NULL;
  }

  // Passo una stringa per la prima volta o nuova stringa
  if (!str_null)
  {
    string_tokenized = str;
    last_pos = 0;
    len = strlen(str);
    int i = 0;
    for(; i<len; i++)
      if(string_tokenized[i] == *delimiter)
        break;

    if(i-last_pos == 0) // Caso "|..."
      return "";

    char * str_ret = malloc(i - last_pos + 1 * sizeof(char));
    strncpy_s(str_ret, i - last_pos + 1 * sizeof(char), string_tokenized+last_pos, i-last_pos);
    str_ret[i - last_pos] = '\0';
    last_pos = i+1;   // Mi posiziono dopo il delimitatore
    return (const char*)str_ret;
  }

  // Next token
  if (string_tokenized != NULL && str_null)
  {
    if (last_pos >= len) {
      string_tokenized = NULL;
      last_pos = 0;
      len = 0;
      return NULL;
    }
    int i = last_pos;
    for (; i < len; i++)
      if (string_tokenized[i] == *delimiter)
        break;

    if (i - last_pos == 0)
    {
      last_pos++;
      return "";
    }
    char * str_ret = malloc(i - last_pos + 1 * sizeof(char));
    strncpy_s(str_ret, (i - last_pos + 1) * sizeof(char), string_tokenized + last_pos, i - last_pos);
    str_ret[i - last_pos] = '\0';
    last_pos = i + 1;   // Mi posiziono dopo il delimitatore
    return str_ret;
  }
  return NULL;
}

/*  Versione per puntatori a funzione in struct
void  FUNCTION(add, token_string_t)     (token_string_t * this, const char * str);
char* FUNCTION(get_pos, token_string_t) (token_string_t * this, int pos);
char* FUNCTION(get_next, token_string_t)(token_string_t * this);
int   FUNCTION(items, token_string_t)   (token_string_t*);
*/
/*  Versione con puntatori a funzione per "metodi"
token_string_t * NEW(token_string_t, 2)(const char * string, const char * delimiter)
{
  token_string_t * obj = ALLOC(token_string_t);

  obj->_obj           = ALLOC(cobject);
  obj->_str           = malloc(strlen(string) + 1 * sizeof(char));
  strcpy_s(obj->_str, strlen(string) + 1 * sizeof(char), string);
  obj->_counter_next  = 0;
  obj->_delimiter     = delimiter;

  obj->add            = FUNCTION(add, token_string_t);
  obj->get_pos        = FUNCTION(get_pos, token_string_t);
  obj->get_next       = FUNCTION(get_next, token_string_t);
  obj->items          = FUNCTION(items, token_string_t);

  return obj;
}
*/