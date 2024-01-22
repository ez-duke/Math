#include "s21_math_tests.h"

START_TEST(s21_log_test0) {
  ck_assert_ldouble_le(s21_fabs(s21_log(0.01) - logl(0.01)), 1e-6);
}
END_TEST

START_TEST(s21_log_test1) { ck_assert_ldouble_le(s21_log(1.0), logl(1.0)); }
END_TEST

START_TEST(s21_log_test2) {
  ck_assert_ldouble_le(s21_fabs(s21_log(S21_PI_4) - logl(S21_PI_4)), 1e-6);
}
END_TEST

START_TEST(s21_log_test3) {
  ck_assert_ldouble_le(s21_fabs(s21_log(S21_PI_2) - logl(S21_PI_2)), 1e-6);
}
END_TEST

START_TEST(s21_log_test4) {
  ck_assert_ldouble_le(
      s21_fabs(s21_log(0.05 * S21_PI_2) - logl(0.05 * S21_PI_2)), 1e-6);
}
END_TEST

START_TEST(s21_log_test5) {
  ck_assert_ldouble_le(s21_log(S21_INF), logl(S21_INF));
}
END_TEST

START_TEST(s21_log_test6) { ck_assert_ldouble_nan(s21_log(-S21_INF)); }
END_TEST

START_TEST(s21_log_test7) { ck_assert_ldouble_nan(s21_log(S21_NAN)); }
END_TEST

START_TEST(s21_log_test8) {
  ck_assert_ldouble_le(s21_fabs(s21_log(S21_PI) - logl(S21_PI)), 1e-6);
}
END_TEST

START_TEST(s21_log_test9) {
  ck_assert_ldouble_le(s21_fabs(s21_log(0.135126315234) - logl(0.135126315234)),
                       1e-6);
}
END_TEST

START_TEST(s21_log_test10) {
  ck_assert_ldouble_le(s21_fabs(s21_log(1e178) - logl(1e178)), 1e-6);
}
END_TEST

Suite *s21_log_test_suite() {
  Suite *s = suite_create("s21_log");
  TCase *tc_case = tcase_create("s21_log_case");
  tcase_add_test(tc_case, s21_log_test0);
  tcase_add_test(tc_case, s21_log_test1);
  tcase_add_test(tc_case, s21_log_test2);
  tcase_add_test(tc_case, s21_log_test3);
  tcase_add_test(tc_case, s21_log_test4);
  tcase_add_test(tc_case, s21_log_test5);
  tcase_add_test(tc_case, s21_log_test6);
  tcase_add_test(tc_case, s21_log_test7);
  tcase_add_test(tc_case, s21_log_test8);
  tcase_add_test(tc_case, s21_log_test9);
  tcase_add_test(tc_case, s21_log_test10);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_log_tests() {
  Suite *s = s21_log_test_suite();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}
