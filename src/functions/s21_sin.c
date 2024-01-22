#include "../s21_math.h"

long double s21_sin(double x) {
  long double res;
  if (x >= S21_INF || x <= -S21_INF) {
    res = S21_NAN;
  } else {
    // используя ряды Маклорена, формула с оптимизированными факториалами
    long double x_long = x;
    x_long = s21_fmod(x_long, 2 * S21_PI);
    if (x_long < 0) x_long += 2 * S21_PI;

    int sign = 0;
    if (x_long <= 2 * S21_PI && x_long > S21_PI + 1e-14) sign = 1;

    // считаем только в I четверти
    // результат отражаем на другую четверть при необходимости
    x_long = s21_fmod(x_long, S21_PI);
    if (x_long > S21_PI_2) x_long = S21_PI - x_long;

    int skip = 0;
    if (s21_fabs(x_long - S21_PI_2) < 1e-6) {
      res = 1.0;
      skip = 1;
    } else if (s21_fabs(x_long) < 1e-6) {
      res = 0.0;
      skip = 1;
    }

    if (!skip) {
      long double num = x_long, xx = x_long * x_long;
      res = x_long;
      for (int i = 1; i < 12; i++) {
        num *= -xx / (2.0 * i * (2.0 * i + 1));
        res += num;
      }
    }
    if (sign) res = -res;
  }
  return res;
}
