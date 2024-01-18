#include "s21_math.h"

long double s21_round(long double x) {
  Floor Convert = {.l_double = x};
  // 16383 - порядок степени long double
  // нужен, чтобы отбросить дробную часть
  unsigned int i = Convert.Parts.e + 1 - 16383;

  // 64 - число бит, отведённых на мантиссу
  Convert.Parts.m >>= 64 - i;
  Convert.Parts.m <<= 64 - i;
  return Convert.l_double;
}
