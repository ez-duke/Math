#include "../s21_math.h"

long double s21_log(double x) {
  long double res;
  if (x == 1) {
    res = 0;
  } else if (x == 0) {
    res = -S21_INF;
  } else if (x >= S21_INF) {
    res = S21_INF;
  } else if (x > 0) {
    int power = 0;
    long double x_long = x;
    while (x_long >= S21_EXP) {
      x_long /= S21_EXP;
      power++;
    }

    // используя метод Ньютона для инвертирования экспоненциальной функции
    long double y = x_long - 1;
    for (int i = 0; i < 5; i++) {
      long double y_next =
          y + 2 * (x_long - s21_exp(y)) / (x_long + s21_exp(y));
      y = y_next;
    }
    res = y + power;
  } else {
    res = S21_NAN;
  }
  return res;
}
