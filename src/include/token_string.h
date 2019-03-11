#ifndef TOKEN_STRINGH
#define TOKEN_STRINGH
/////////////////////////////////////////////////////////
// STRUCT token_string_t
/////////////////////////////////////////////////////////
#define NEW(obj, n_par) new##n_par##_##obj
typedef struct token_string_t token_string_t;

// This function returns a new token_string_t object
token_string_t * new_token_string_t(); // Default params: string="", delimiter="|"
token_string_t * new2_token_string_t(const char * string, const char * delimiter);
//  Metodi per l'elaborazione di token_string_t
void  add_tok       (token_string_t * this, const char* str);		// Add new token
char* get_pos_tok   (token_string_t * this, int pos);						// Get a token in specified position
char* get_next_tok  (token_string_t * this);										// Get next token 
int   items_tok     (const token_string_t * this);                    // Number of tokens
void  clean_tok     (token_string_t * this);                    // Delete last string
void  set_delim_tok (token_string_t * this, const char * str);  // Set new delimiter (previous token stay separate with old delimiter)
char* get_tok       (char* str, const char* delimiter);
#endif