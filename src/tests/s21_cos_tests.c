#include "s21_math_tests.h"

START_TEST(s21_cos_test0) {
  ck_assert_ldouble_le(s21_fabs(s21_cos(0.0) - cosl(0.0)), 1e-6);
}
END_TEST

START_TEST(s21_cos_test1) {
  ck_assert_ldouble_le(s21_fabs(s21_cos(1.0) - cosl(1.0)), 1e-6);
}
END_TEST

START_TEST(s21_cos_test2) {
  ck_assert_ldouble_le(s21_fabs(s21_cos(-1.0) - cosl(-1.0)), 1e-6);
}
END_TEST

START_TEST(s21_cos_test3) {
  ck_assert_ldouble_le(s21_fabs(s21_cos(S21_PI_4) - cosl(S21_PI_4)), 1e-6);
}
END_TEST

START_TEST(s21_cos_test4) {
  ck_assert_ldouble_le(s21_fabs(s21_cos(-S21_PI_4) - cosl(-S21_PI_4)), 1e-6);
}
END_TEST

START_TEST(s21_cos_test5) {
  ck_assert_ldouble_le(s21_fabs(s21_cos(S21_PI_2) - cosl(S21_PI_2)), 1e-6);
}
END_TEST

START_TEST(s21_cos_test6) {
  ck_assert_ldouble_le(s21_fabs(s21_cos(-5 * S21_PI_2) - cosl(-5 * S21_PI_2)),
                       1e-6);
}
END_TEST

START_TEST(s21_cos_test7) { ck_assert_ldouble_nan(s21_cos(S21_INF)); }
END_TEST

START_TEST(s21_cos_test8) { ck_assert_ldouble_nan(s21_cos(-S21_INF)); }
END_TEST

START_TEST(s21_cos_test9) { ck_assert_ldouble_nan(s21_cos(S21_NAN)); }
END_TEST

START_TEST(s21_cos_test10) {
  ck_assert_ldouble_le(s21_fabs(s21_cos(S21_PI) - cosl(S21_PI)), 1e-6);
}
END_TEST

START_TEST(s21_cos_test11) {
  ck_assert_ldouble_le(s21_fabs(s21_cos(-7 * S21_PI) - cosl(-7 * S21_PI)),
                       1e-6);
}
END_TEST

START_TEST(s21_cos_test12) {
  ck_assert_ldouble_le(s21_fabs(s21_cos(0.135126315234) - cosl(0.135126315234)),
                       1e-6);
}
END_TEST

START_TEST(s21_cos_test13) {
  ck_assert_ldouble_le(s21_fabs(s21_cos(312.47172461) - cosl(312.47172461)),
                       1e-6);
}
END_TEST

Suite *s21_cos_test_suite() {
  Suite *s = suite_create("s21_cos");
  TCase *tc_case = tcase_create("s21_cos_case");
  tcase_add_test(tc_case, s21_cos_test0);
  tcase_add_test(tc_case, s21_cos_test1);
  tcase_add_test(tc_case, s21_cos_test2);
  tcase_add_test(tc_case, s21_cos_test3);
  tcase_add_test(tc_case, s21_cos_test4);
  tcase_add_test(tc_case, s21_cos_test5);
  tcase_add_test(tc_case, s21_cos_test6);
  tcase_add_test(tc_case, s21_cos_test7);
  tcase_add_test(tc_case, s21_cos_test8);
  tcase_add_test(tc_case, s21_cos_test9);
  tcase_add_test(tc_case, s21_cos_test10);
  tcase_add_test(tc_case, s21_cos_test11);
  tcase_add_test(tc_case, s21_cos_test12);
  tcase_add_test(tc_case, s21_cos_test13);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_cos_tests() {
  Suite *s = s21_cos_test_suite();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}
