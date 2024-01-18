#include "s21_math.h"

long double s21_atan(double x) {
  long double res;
  int sign = 0;
  if (x < 0) sign = 1;
  x = s21_fabs(x);

  if (x >= S21_INF) {
    res = S21_PI_2;
  } else if (x <= -S21_INF) {
    res = -S21_PI_2;
  } else if (x >= 1 || x <= -1) {
    // волшебное свойство арктангенса, найденное на стаковере для математиков
    res = S21_PI_2 - atan(1.0 / x);
  } else {
    // используя ряды Тейлора
    res = x;
    for (int i = 1; i < 50; i++) {
      long double num =
          s21_pow(-1.0, i) * s21_pow(x, 2.0 * i + 1) / (2.0 * i + 1);
      res += num;
    }
  }
  if (sign) res = -res;
  return res;
}
