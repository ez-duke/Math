#include "../s21_math.h"

long double s21_sqrt(double x) {
  long double res;
  if (x > 0 && x < S21_INF) {
    // 2 - просто угадывание
    res = 2;
    long double x_long = x;
    // метод Герона
    for (int i = 0; i < 100; i++) res = 0.5 * (res + x_long / res);
  } else if (x == 0) {
    res = 0;
  } else if (x >= S21_INF) {
    res = S21_INF;
  } else {
    res = S21_NAN;
  }
  return res;
}
