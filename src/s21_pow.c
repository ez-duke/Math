#include "s21_math.h"

long double s21_pow(double base, double exp) {
  long double res, fractional = exp - s21_floor(exp), base_long = base;
  if (base == 1 || exp == 0) {
    res = 1;
  } else if (base <= -S21_INF || exp >= S21_INF) {
    res = S21_INF;
  } else if (exp != exp || base != base) {
    res = S21_NAN;
  } else if (exp <= -S21_INF) {
    res = 0;
  } else if (fractional) {
    // по волшебной формуле с википедии, основана на свойствах степеней
    res = s21_exp(exp * s21_log(base_long));
  } else {
    if (exp < 0) {
      base_long = 1.0 / base_long;
      exp = -exp;
    }
    res = base_long;
    for (int i = exp; i > 1; i--) res *= base_long;
  }
  return res;
}
