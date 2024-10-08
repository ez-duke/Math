#include "../s21_math.h"

long double s21_exp(double x) {
  long double res;
  if (x < -20.0) {
    res = 0;
  } else {
    long double num = 1, x_long = x;
    res = 1;
    for (unsigned int i = 1; s21_fabs(num / res) > 1e-20; i++) {
      num *= x_long / i;
      res += num;
    }
  }
  return res;
}
