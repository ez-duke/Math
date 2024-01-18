#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long double res;
  int sign = 0;
  if (x < 0) sign = 1;
  if (x >= S21_INF || x <= -S21_INF || y != y || x != x || y == 0) {
    res = S21_NAN;
  } else if (y >= S21_INF || y <= -S21_INF) {
    res = s21_fabs(x);
  } else if (x == 0) {
    res = 0;
  } else {
    long double a = s21_fabs(x), b = s21_fabs(y);
    if (a > b) {
      long double num = s21_round(a / b);
      b *= num;
      res = a - b;
    } else {
      res = x;
    }
  }
  if (sign) res = -res;
  return res;
}
