#include "s21_math_tests.h"

START_TEST(s21_sqrt_test0) {
  ck_assert_ldouble_le(s21_fabs(s21_sqrt(0.0) - sqrtl(0.0)), 1e-6);
}
END_TEST

START_TEST(s21_sqrt_test1) {
  ck_assert_ldouble_le(s21_fabs(s21_sqrt(1.0) - sqrtl(1.0)), 1e-6);
}
END_TEST

START_TEST(s21_sqrt_test2) { ck_assert_ldouble_nan(s21_sqrt(-1.0)); }
END_TEST

START_TEST(s21_sqrt_test3) {
  ck_assert_ldouble_le(
      s21_fabs(s21_sqrt(237612831283.1) - sqrtl(237612831283.1)), 1e-6);
}
END_TEST

START_TEST(s21_sqrt_test4) {
  ck_assert_ldouble_le(
      s21_fabs(s21_sqrt(0.135126315234) - sqrtl(0.135126315234)), 1e-6);
}
END_TEST

START_TEST(s21_sqrt_test5) {
  ck_assert_ldouble_le(s21_fabs(s21_sqrt(S21_PI_2) - sqrtl(S21_PI_2)), 1e-6);
}
END_TEST

START_TEST(s21_sqrt_test6) {
  ck_assert_ldouble_le(s21_fabs(s21_sqrt(312.47172461) - sqrtl(312.47172461)),
                       1e-6);
}
END_TEST

START_TEST(s21_sqrt_test7) {
  ck_assert_ldouble_le(s21_sqrt(S21_INF), sqrtl(S21_INF));
}
END_TEST

START_TEST(s21_sqrt_test8) { ck_assert_ldouble_nan(s21_sqrt(-S21_INF)); }
END_TEST

START_TEST(s21_sqrt_test9) { ck_assert_ldouble_nan(s21_sqrt(S21_NAN)); }
END_TEST

START_TEST(s21_sqrt_test10) {
  ck_assert_ldouble_le(s21_fabs(s21_sqrt(S21_PI) - sqrtl(S21_PI)), 1e-6);
}
END_TEST

START_TEST(s21_sqrt_test11) {
  ck_assert_ldouble_le(s21_fabs(s21_sqrt(1e50) - sqrtl(1e50)), 1e-6);
}
END_TEST

Suite *s21_sqrt_test_suite() {
  Suite *s = suite_create("s21_sqrt");
  TCase *tc_case = tcase_create("s21_sqrt_case");
  tcase_add_test(tc_case, s21_sqrt_test0);
  tcase_add_test(tc_case, s21_sqrt_test1);
  tcase_add_test(tc_case, s21_sqrt_test2);
  tcase_add_test(tc_case, s21_sqrt_test3);
  tcase_add_test(tc_case, s21_sqrt_test4);
  tcase_add_test(tc_case, s21_sqrt_test5);
  tcase_add_test(tc_case, s21_sqrt_test6);
  tcase_add_test(tc_case, s21_sqrt_test7);
  tcase_add_test(tc_case, s21_sqrt_test8);
  tcase_add_test(tc_case, s21_sqrt_test9);
  tcase_add_test(tc_case, s21_sqrt_test10);
  tcase_add_test(tc_case, s21_sqrt_test11);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_sqrt_tests() {
  Suite *s = s21_sqrt_test_suite();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}
