#include "s21_math_tests.h"

START_TEST(s21_atan_test0) {
  ck_assert_ldouble_le(s21_fabs(s21_atan(0.0) - atanl(0.0)), 1e-6);
}
END_TEST

START_TEST(s21_atan_test1) {
  ck_assert_ldouble_le(s21_fabs(s21_atan(1.0) - atanl(1.0)), 1e-6);
}
END_TEST

START_TEST(s21_atan_test2) {
  ck_assert_ldouble_le(s21_fabs(s21_atan(-1.0) - atanl(-1.0)), 1e-6);
}
END_TEST

START_TEST(s21_atan_test3) {
  ck_assert_ldouble_le(s21_fabs(s21_atan(S21_PI_4) - atanl(S21_PI_4)), 1e-6);
}
END_TEST

START_TEST(s21_atan_test4) {
  ck_assert_ldouble_le(s21_fabs(s21_atan(-S21_PI_4) - atanl(-S21_PI_4)), 1e-6);
}
END_TEST

START_TEST(s21_atan_test5) {
  ck_assert_ldouble_le(s21_fabs(s21_atan(S21_PI_2) - atanl(S21_PI_2)), 1e-6);
}
END_TEST

START_TEST(s21_atan_test6) {
  ck_assert_ldouble_le(s21_fabs(s21_atan(-5 * S21_PI_2) - atanl(-5 * S21_PI_2)),
                       1e-6);
}
END_TEST

START_TEST(s21_atan_test7) {
  ck_assert_ldouble_le(s21_fabs(s21_atan(S21_INF) - atanl(S21_INF)), 1e-6);
}
END_TEST

START_TEST(s21_atan_test8) {
  ck_assert_ldouble_le(s21_fabs(s21_atan(-S21_INF) - atanl(-S21_INF)), 1e-6);
}
END_TEST

START_TEST(s21_atan_test9) { ck_assert_ldouble_nan(s21_atan(S21_NAN)); }
END_TEST

START_TEST(s21_atan_test10) {
  ck_assert_ldouble_le(s21_fabs(s21_atan(S21_PI) - atanl(S21_PI)), 1e-6);
}
END_TEST

START_TEST(s21_atan_test11) {
  ck_assert_ldouble_le(s21_fabs(s21_atan(-7 * S21_PI) - atanl(-7 * S21_PI)),
                       1e-6);
}
END_TEST

START_TEST(s21_atan_test12) {
  ck_assert_ldouble_le(
      s21_fabs(s21_atan(0.135126315234) - atanl(0.135126315234)), 1e-6);
}
END_TEST

START_TEST(s21_atan_test13) {
  ck_assert_ldouble_le(s21_fabs(s21_atan(312.47172461) - atanl(312.47172461)),
                       1e-6);
}
END_TEST

Suite *s21_atan_test_suite() {
  Suite *s = suite_create("s21_atan");
  TCase *tc_case = tcase_create("s21_atan_case");
  tcase_add_test(tc_case, s21_atan_test0);
  tcase_add_test(tc_case, s21_atan_test1);
  tcase_add_test(tc_case, s21_atan_test2);
  tcase_add_test(tc_case, s21_atan_test3);
  tcase_add_test(tc_case, s21_atan_test4);
  tcase_add_test(tc_case, s21_atan_test5);
  tcase_add_test(tc_case, s21_atan_test6);
  tcase_add_test(tc_case, s21_atan_test7);
  tcase_add_test(tc_case, s21_atan_test8);
  tcase_add_test(tc_case, s21_atan_test9);
  tcase_add_test(tc_case, s21_atan_test10);
  tcase_add_test(tc_case, s21_atan_test11);
  tcase_add_test(tc_case, s21_atan_test12);
  tcase_add_test(tc_case, s21_atan_test13);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_atan_tests() {
  Suite *s = s21_atan_test_suite();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}
