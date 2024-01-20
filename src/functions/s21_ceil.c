#include "../s21_math.h"

long double s21_ceil(double x) {
  long double res;
  if (x >= S21_INF) {
    res = S21_INF;
  } else if (x <= -S21_INF) {
    res = -S21_INF;
  } else if (x != x) {
    res = S21_NAN;
  } else {
    res = s21_round(x);
    if (x > 0 && x != res) res++;
  }
  return res;
}
