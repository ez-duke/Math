#include "s21_math_tests.h"

START_TEST(s21_fabs_test0) {
  ck_assert_ldouble_le(s21_fabs(s21_fabs(0.0) - fabsl(0.0)), 1e-6);
}
END_TEST

START_TEST(s21_fabs_test1) {
  ck_assert_ldouble_le(s21_fabs(s21_fabs(1.0) - fabsl(1.0)), 1e-6);
}
END_TEST

START_TEST(s21_fabs_test2) {
  ck_assert_ldouble_le(s21_fabs(s21_fabs(-1.0) - fabsl(-1.0)), 1e-6);
}
END_TEST

START_TEST(s21_fabs_test3) {
  ck_assert_ldouble_le(s21_fabs(s21_fabs(-S21_PI_4) - fabsl(-S21_PI_4)), 1e-6);
}
END_TEST

START_TEST(s21_fabs_test4) {
  ck_assert_ldouble_le(
      s21_fabs(s21_fabs(0.135126315234) - fabsl(0.135126315234)), 1e-6);
}
END_TEST

START_TEST(s21_fabs_test5) {
  ck_assert_ldouble_le(s21_fabs(s21_fabs(S21_PI_2) - fabsl(S21_PI_2)), 1e-6);
}
END_TEST

START_TEST(s21_fabs_test6) {
  ck_assert_ldouble_le(s21_fabs(s21_fabs(312.47172461) - fabsl(312.47172461)),
                       1e-6);
}
END_TEST

START_TEST(s21_fabs_test7) {
  ck_assert_ldouble_le(s21_fabs(s21_fabs(S21_INF)), fabsl(S21_INF));
}
END_TEST

START_TEST(s21_fabs_test8) {
  ck_assert_ldouble_le(s21_fabs(-S21_INF), fabsl(-S21_INF));
}
END_TEST

START_TEST(s21_fabs_test9) { ck_assert_ldouble_nan(s21_fabs(S21_NAN)); }
END_TEST

Suite *s21_fabs_test_suite() {
  Suite *s = suite_create("s21_fabs");
  TCase *tc_case = tcase_create("s21_fabs_case");
  tcase_add_test(tc_case, s21_fabs_test0);
  tcase_add_test(tc_case, s21_fabs_test1);
  tcase_add_test(tc_case, s21_fabs_test2);
  tcase_add_test(tc_case, s21_fabs_test3);
  tcase_add_test(tc_case, s21_fabs_test4);
  tcase_add_test(tc_case, s21_fabs_test5);
  tcase_add_test(tc_case, s21_fabs_test6);
  tcase_add_test(tc_case, s21_fabs_test7);
  tcase_add_test(tc_case, s21_fabs_test8);
  tcase_add_test(tc_case, s21_fabs_test9);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_fabs_tests() {
  Suite *s = s21_fabs_test_suite();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}
