#ifndef __COMPLEXH__

#define __COMPLEXH__
struct complx_t{
  double re, im;
  //double(*abs)(struct Complex *this);
};

extern const struct complx_class {
  struct complx_t (*new)(double real, double imag);
} complex;
#endif