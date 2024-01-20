#include "s21_math_tests.h"

START_TEST(s21_ceil_test0) {
  ck_assert_ldouble_le(s21_fabs(s21_ceil(0.0) - ceill(0.0)), 1e-6);
}
END_TEST

START_TEST(s21_ceil_test1) {
  ck_assert_ldouble_le(s21_fabs(s21_ceil(1.0) - ceill(1.0)), 1e-6);
}
END_TEST

START_TEST(s21_ceil_test2) {
  ck_assert_ldouble_le(s21_fabs(s21_ceil(-1.0) - ceill(-1.0)), 1e-6);
}
END_TEST

START_TEST(s21_ceil_test3) {
  ck_assert_ldouble_le(s21_fabs(s21_ceil(-S21_PI_4) - ceill(-S21_PI_4)), 1e-6);
}
END_TEST

START_TEST(s21_ceil_test4) {
  ck_assert_ldouble_le(
      s21_fabs(s21_ceil(0.135126315234) - ceill(0.135126315234)), 1e-6);
}
END_TEST

START_TEST(s21_ceil_test5) {
  ck_assert_ldouble_le(s21_fabs(s21_ceil(S21_PI_2) - ceill(S21_PI_2)), 1e-6);
}
END_TEST

START_TEST(s21_ceil_test6) {
  ck_assert_ldouble_le(s21_fabs(s21_ceil(312.47172461) - ceill(312.47172461)),
                       1e-6);
}
END_TEST

START_TEST(s21_ceil_test7) {
  ck_assert_ldouble_le(s21_fabs(s21_ceil(S21_INF)), ceill(S21_INF));
}
END_TEST

START_TEST(s21_ceil_test8) {
  ck_assert_ldouble_le(s21_ceil(-S21_INF), ceill(-S21_INF));
}
END_TEST

START_TEST(s21_ceil_test9) { ck_assert_ldouble_nan(s21_ceil(S21_NAN)); }
END_TEST

Suite *s21_ceil_test_suite() {
  Suite *s = suite_create("s21_ceil");
  TCase *tc_case = tcase_create("s21_ceil_case");
  tcase_add_test(tc_case, s21_ceil_test0);
  tcase_add_test(tc_case, s21_ceil_test1);
  tcase_add_test(tc_case, s21_ceil_test2);
  tcase_add_test(tc_case, s21_ceil_test3);
  tcase_add_test(tc_case, s21_ceil_test4);
  tcase_add_test(tc_case, s21_ceil_test5);
  tcase_add_test(tc_case, s21_ceil_test6);
  tcase_add_test(tc_case, s21_ceil_test7);
  tcase_add_test(tc_case, s21_ceil_test8);
  tcase_add_test(tc_case, s21_ceil_test9);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_ceil_tests() {
  Suite *s = s21_ceil_test_suite();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}
