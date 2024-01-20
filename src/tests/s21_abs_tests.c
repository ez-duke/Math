#include "s21_math_tests.h"

START_TEST(s21_abs_test0) { ck_assert_int_eq(s21_abs(0), abs(0)); }
END_TEST

START_TEST(s21_abs_test1) { ck_assert_int_eq(s21_abs(4), abs(4)); }
END_TEST

START_TEST(s21_abs_test2) { ck_assert_int_eq(s21_abs(-5), abs(-5)); }
END_TEST

Suite *s21_abs_test_suite() {
  Suite *s = suite_create("s21_abs");
  TCase *tc_case = tcase_create("s21_abs_case");
  tcase_add_test(tc_case, s21_abs_test0);
  tcase_add_test(tc_case, s21_abs_test1);
  tcase_add_test(tc_case, s21_abs_test2);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_abs_tests() {
  Suite *s = s21_abs_test_suite();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}
