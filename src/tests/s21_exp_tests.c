#include "s21_math_tests.h"

START_TEST(s21_exp_test0) {
  ck_assert_ldouble_le(s21_fabs(s21_exp(0.0) - expl(0.0)), 1e-6);
}
END_TEST

START_TEST(s21_exp_test1) {
  ck_assert_ldouble_le(s21_fabs(s21_exp(1.0) - expl(1.0)), 1e-6);
}
END_TEST

START_TEST(s21_exp_test2) {
  ck_assert_ldouble_le(s21_fabs(s21_exp(-1.0) - expl(-1.0)), 1e-6);
}
END_TEST

START_TEST(s21_exp_test3) {
  ck_assert_ldouble_le(s21_fabs(s21_exp(S21_PI_4) - expl(S21_PI_4)), 1e-6);
}
END_TEST

START_TEST(s21_exp_test4) {
  ck_assert_ldouble_le(s21_fabs(s21_exp(-S21_PI_4) - expl(-S21_PI_4)), 1e-6);
}
END_TEST

START_TEST(s21_exp_test5) {
  ck_assert_ldouble_le(s21_fabs(s21_exp(S21_PI_2) - expl(S21_PI_2)), 1e-6);
}
END_TEST

START_TEST(s21_exp_test6) {
  ck_assert_ldouble_le(s21_fabs(s21_exp(-5 * S21_PI_2) - expl(-5 * S21_PI_2)),
                       1e-6);
}
END_TEST

START_TEST(s21_exp_test7) {
  ck_assert_ldouble_le(s21_exp(S21_INF), expl(S21_INF));
}
END_TEST

START_TEST(s21_exp_test8) {
  ck_assert_ldouble_le(s21_fabs(s21_exp(-S21_INF) - expl(-S21_INF)), 1e-6);
}
END_TEST

START_TEST(s21_exp_test9) { ck_assert_ldouble_nan(s21_exp(S21_NAN)); }
END_TEST

START_TEST(s21_exp_test10) {
  ck_assert_ldouble_le(s21_fabs(s21_exp(S21_PI) - expl(S21_PI)), 1e-6);
}
END_TEST

START_TEST(s21_exp_test11) {
  ck_assert_ldouble_le(s21_fabs(s21_exp(-7 * S21_PI) - expl(-7 * S21_PI)),
                       1e-6);
}
END_TEST

START_TEST(s21_exp_test12) {
  ck_assert_ldouble_le(s21_fabs(s21_exp(0.135126315234) - expl(0.135126315234)),
                       1e-6);
}
END_TEST

START_TEST(s21_exp_test13) {
  ck_assert_ldouble_le(s21_fabs(s21_exp(-19.5) - expl(-19.5)), 1e-6);
}
END_TEST

Suite *s21_exp_test_suite() {
  Suite *s = suite_create("s21_exp");
  TCase *tc_case = tcase_create("s21_exp_case");
  tcase_add_test(tc_case, s21_exp_test0);
  tcase_add_test(tc_case, s21_exp_test1);
  tcase_add_test(tc_case, s21_exp_test2);
  tcase_add_test(tc_case, s21_exp_test3);
  tcase_add_test(tc_case, s21_exp_test4);
  tcase_add_test(tc_case, s21_exp_test5);
  tcase_add_test(tc_case, s21_exp_test6);
  tcase_add_test(tc_case, s21_exp_test7);
  tcase_add_test(tc_case, s21_exp_test8);
  tcase_add_test(tc_case, s21_exp_test9);
  tcase_add_test(tc_case, s21_exp_test10);
  tcase_add_test(tc_case, s21_exp_test11);
  tcase_add_test(tc_case, s21_exp_test12);
  tcase_add_test(tc_case, s21_exp_test13);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_exp_tests() {
  Suite *s = s21_exp_test_suite();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}
