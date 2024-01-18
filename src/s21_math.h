#ifndef S21_MATH_H
#define S21_MATH_H

#define _POSIX_C_SOURCE 200809L
#define S21_EXP 2.71828182845904523536028747135266250L
#define S21_PI 3.14159265358979323846264338327950288L
#define S21_PI_2 1.57079632679489661923132169163975144L
#define S21_PI_4 0.785398163397448309615660845819875721L
#define S21_INF 1.0 / 0.0L
#define S21_NAN 0.0 / 0.0L

typedef union {
  long double l_double;
  struct {
    unsigned long long int m : 64;
    unsigned int e : 15;
    unsigned short int s : 1;
  } Parts;
} Floor;

#include <check.h>
#include <math.h>
#include <stdio.h>
// только для abs() :)
#include <stdlib.h>

int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_round(long double x);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);

#endif
