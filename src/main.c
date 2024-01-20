#include <stdio.h>
#include "s21_math.h"
#include <math.h>

int main() {
  // long double x = 1737537853727.407871;
  // long double y = 2.456;
  printf("%.26Lf\n", ceill(-S21_INF));
  printf("%.26Lf\n", s21_ceil(-S21_INF));
  return 0;
}
