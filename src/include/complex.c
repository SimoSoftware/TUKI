#include "complex.h"
#include <math.h>

static struct complx_t new(const double real, const double imag){
  struct complx_t a;
  a.re = real;
  a.im = imag;
  return a;
};
const struct complx_class complx_t = { .new = &new };

