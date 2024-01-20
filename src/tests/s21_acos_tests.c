#include "s21_math_tests.h"

START_TEST(s21_acos_test0) {
  ck_assert_ldouble_le(s21_fabs(s21_acos(0.0) - acosl(0.0)), 1e-6);
}
END_TEST

START_TEST(s21_acos_test1) {
  ck_assert_ldouble_le(s21_fabs(s21_acos(1.0) - acosl(1.0)), 1e-6);
}
END_TEST

START_TEST(s21_acos_test2) {
  ck_assert_ldouble_le(s21_fabs(s21_acos(-1.0) - acosl(-1.0)), 1e-6);
}
END_TEST

START_TEST(s21_acos_test3) {
  ck_assert_ldouble_le(s21_fabs(s21_acos(-S21_PI_4) - acosl(-S21_PI_4)), 1e-6);
}
END_TEST

START_TEST(s21_acos_test4) {
  ck_assert_ldouble_le(
      s21_fabs(s21_acos(0.135126315234) - acosl(0.135126315234)), 1e-6);
}
END_TEST

START_TEST(s21_acos_test5) { ck_assert_ldouble_nan(s21_acos(-S21_PI_2)); }
END_TEST

Suite *s21_acos_test_suite() {
  Suite *s = suite_create("s21_acos");
  TCase *tc_case = tcase_create("s21_acos_case");
  tcase_add_test(tc_case, s21_acos_test0);
  tcase_add_test(tc_case, s21_acos_test1);
  tcase_add_test(tc_case, s21_acos_test2);
  tcase_add_test(tc_case, s21_acos_test3);
  tcase_add_test(tc_case, s21_acos_test4);
  tcase_add_test(tc_case, s21_acos_test5);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_acos_tests() {
  Suite *s = s21_acos_test_suite();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}
