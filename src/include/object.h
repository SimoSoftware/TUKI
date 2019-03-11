#ifndef __COBJECTH__
#define __COBJECTH__

typedef struct cobject{
  const char * _name;
}cobject;

inline void new_cobject(cobject * this, const char * name)
{
  this->_name = name;
}
#endif