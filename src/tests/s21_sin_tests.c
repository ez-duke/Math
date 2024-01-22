#include "s21_math_tests.h"

START_TEST(s21_sin_test0) {
  ck_assert_ldouble_le(s21_fabs(s21_sin(0.0) - sinl(0.0)), 1e-6);
}
END_TEST

START_TEST(s21_sin_test1) {
  ck_assert_ldouble_le(s21_fabs(s21_sin(1.0) - sinl(1.0)), 1e-6);
}
END_TEST

START_TEST(s21_sin_test2) {
  ck_assert_ldouble_le(s21_fabs(s21_sin(-1.0) - sinl(-1.0)), 1e-6);
}
END_TEST

START_TEST(s21_sin_test3) {
  ck_assert_ldouble_le(s21_fabs(s21_sin(S21_PI_4) - sinl(S21_PI_4)), 1e-6);
}
END_TEST

START_TEST(s21_sin_test4) {
  ck_assert_ldouble_le(s21_fabs(s21_sin(-S21_PI_4) - sinl(-S21_PI_4)), 1e-6);
}
END_TEST

START_TEST(s21_sin_test5) {
  ck_assert_ldouble_le(s21_fabs(s21_sin(S21_PI_2) - sinl(S21_PI_2)), 1e-6);
}
END_TEST

START_TEST(s21_sin_test6) {
  ck_assert_ldouble_le(s21_fabs(s21_sin(-5 * S21_PI_2) - sinl(-5 * S21_PI_2)),
                       1e-6);
}
END_TEST

START_TEST(s21_sin_test7) { ck_assert_ldouble_nan(s21_sin(S21_INF)); }
END_TEST

START_TEST(s21_sin_test8) { ck_assert_ldouble_nan(s21_sin(-S21_INF)); }
END_TEST

START_TEST(s21_sin_test9) { ck_assert_ldouble_nan(s21_sin(S21_NAN)); }
END_TEST

START_TEST(s21_sin_test10) {
  ck_assert_ldouble_le(s21_fabs(s21_sin(S21_PI) - sinl(S21_PI)), 1e-6);
}
END_TEST

START_TEST(s21_sin_test11) {
  ck_assert_ldouble_le(s21_fabs(s21_sin(-7 * S21_PI) - sinl(-7 * S21_PI)),
                       1e-6);
}
END_TEST

START_TEST(s21_sin_test12) {
  ck_assert_ldouble_le(s21_fabs(s21_sin(0.135126315234) - sinl(0.135126315234)),
                       1e-6);
}
END_TEST

START_TEST(s21_sin_test13) {
  ck_assert_ldouble_le(s21_fabs(s21_sin(312.47172461) - sinl(312.47172461)),
                       1e-6);
}
END_TEST

Suite *s21_sin_test_suite() {
  Suite *s = suite_create("s21_sin");
  TCase *tc_case = tcase_create("s21_sin_case");
  tcase_add_test(tc_case, s21_sin_test0);
  tcase_add_test(tc_case, s21_sin_test1);
  tcase_add_test(tc_case, s21_sin_test2);
  tcase_add_test(tc_case, s21_sin_test3);
  tcase_add_test(tc_case, s21_sin_test4);
  tcase_add_test(tc_case, s21_sin_test5);
  tcase_add_test(tc_case, s21_sin_test6);
  tcase_add_test(tc_case, s21_sin_test7);
  tcase_add_test(tc_case, s21_sin_test8);
  tcase_add_test(tc_case, s21_sin_test9);
  tcase_add_test(tc_case, s21_sin_test10);
  tcase_add_test(tc_case, s21_sin_test11);
  tcase_add_test(tc_case, s21_sin_test12);
  tcase_add_test(tc_case, s21_sin_test13);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_sin_tests() {
  Suite *s = s21_sin_test_suite();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}
