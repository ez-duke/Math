#include "s21_math_tests.h"

START_TEST(s21_floor_test0) {
  ck_assert_ldouble_le(s21_fabs(s21_floor(0.0) - floorl(0.0)), 1e-6);
}
END_TEST

START_TEST(s21_floor_test1) {
  ck_assert_ldouble_le(s21_fabs(s21_floor(1.0) - floorl(1.0)), 1e-6);
}
END_TEST

START_TEST(s21_floor_test2) {
  ck_assert_ldouble_le(s21_fabs(s21_floor(-1.0) - floorl(-1.0)), 1e-6);
}
END_TEST

START_TEST(s21_floor_test3) {
  ck_assert_ldouble_le(s21_fabs(s21_floor(-S21_PI_4) - floorl(-S21_PI_4)),
                       1e-6);
}
END_TEST

START_TEST(s21_floor_test4) {
  ck_assert_ldouble_le(
      s21_fabs(s21_floor(0.135126315234) - floorl(0.135126315234)), 1e-6);
}
END_TEST

START_TEST(s21_floor_test5) {
  ck_assert_ldouble_le(s21_fabs(s21_floor(S21_PI_2) - floorl(S21_PI_2)), 1e-6);
}
END_TEST

START_TEST(s21_floor_test6) {
  ck_assert_ldouble_le(s21_fabs(s21_floor(312.47172461) - floorl(312.47172461)),
                       1e-6);
}
END_TEST

START_TEST(s21_floor_test7) {
  ck_assert_ldouble_le(s21_fabs(s21_floor(S21_INF)), floorl(S21_INF));
}
END_TEST

START_TEST(s21_floor_test8) {
  ck_assert_ldouble_le(s21_floor(-S21_INF), floorl(-S21_INF));
}
END_TEST

START_TEST(s21_floor_test9) { ck_assert_ldouble_nan(s21_floor(S21_NAN)); }
END_TEST

Suite *s21_floor_test_suite() {
  Suite *s = suite_create("s21_floor");
  TCase *tc_case = tcase_create("s21_floor_case");
  tcase_add_test(tc_case, s21_floor_test0);
  tcase_add_test(tc_case, s21_floor_test1);
  tcase_add_test(tc_case, s21_floor_test2);
  tcase_add_test(tc_case, s21_floor_test3);
  tcase_add_test(tc_case, s21_floor_test4);
  tcase_add_test(tc_case, s21_floor_test5);
  tcase_add_test(tc_case, s21_floor_test6);
  tcase_add_test(tc_case, s21_floor_test7);
  tcase_add_test(tc_case, s21_floor_test8);
  tcase_add_test(tc_case, s21_floor_test9);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_floor_tests() {
  Suite *s = s21_floor_test_suite();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}
