#include "s21_math_tests.h"

START_TEST(s21_tan_test0) {
  ck_assert_ldouble_le(s21_fabs(s21_tan(0.0) - tanl(0.0)), 1e-6);
}
END_TEST

START_TEST(s21_tan_test1) {
  ck_assert_ldouble_le(s21_fabs(s21_tan(1.0) - tanl(1.0)), 1e-6);
}
END_TEST

START_TEST(s21_tan_test2) {
  ck_assert_ldouble_le(s21_fabs(s21_tan(-1.0) - tanl(-1.0)), 1e-6);
}
END_TEST

START_TEST(s21_tan_test3) {
  ck_assert_ldouble_le(s21_fabs(s21_tan(S21_PI_4) - tanl(S21_PI_4)), 1e-6);
}
END_TEST

START_TEST(s21_tan_test4) {
  ck_assert_ldouble_le(s21_fabs(s21_tan(-S21_PI_4) - tanl(-S21_PI_4)), 1e-6);
}
END_TEST

START_TEST(s21_tan_test5) {
  ck_assert_ldouble_le(
      s21_fabs(s21_tan(S21_PI_2 + 0.01) - tanl(S21_PI_2 + 0.01)), 1e-6);
}
END_TEST

START_TEST(s21_tan_test6) {
  ck_assert_ldouble_le(s21_fabs(s21_tan(312.47172461) - tanl(312.47172461)),
                       1e-6);
}
END_TEST

START_TEST(s21_tan_test7) { ck_assert_ldouble_nan(s21_tan(S21_INF)); }
END_TEST

START_TEST(s21_tan_test8) { ck_assert_ldouble_nan(s21_tan(-S21_INF)); }
END_TEST

START_TEST(s21_tan_test9) { ck_assert_ldouble_nan(s21_tan(S21_NAN)); }
END_TEST

START_TEST(s21_tan_test10) {
  ck_assert_ldouble_le(s21_fabs(s21_tan(S21_PI) - tanl(S21_PI)), 1e-6);
}
END_TEST

START_TEST(s21_tan_test11) {
  ck_assert_ldouble_le(s21_fabs(s21_tan(-7 * S21_PI) - tanl(-7 * S21_PI)),
                       1e-6);
}
END_TEST

START_TEST(s21_tan_test12) {
  ck_assert_ldouble_le(s21_fabs(s21_tan(0.135126315234) - tanl(0.135126315234)),
                       1e-6);
}
END_TEST

Suite *s21_tan_test_suite() {
  Suite *s = suite_create("s21_tan");
  TCase *tc_case = tcase_create("s21_tan_case");
  tcase_add_test(tc_case, s21_tan_test0);
  tcase_add_test(tc_case, s21_tan_test1);
  tcase_add_test(tc_case, s21_tan_test2);
  tcase_add_test(tc_case, s21_tan_test3);
  tcase_add_test(tc_case, s21_tan_test4);
  tcase_add_test(tc_case, s21_tan_test5);
  tcase_add_test(tc_case, s21_tan_test6);
  tcase_add_test(tc_case, s21_tan_test7);
  tcase_add_test(tc_case, s21_tan_test8);
  tcase_add_test(tc_case, s21_tan_test9);
  tcase_add_test(tc_case, s21_tan_test10);
  tcase_add_test(tc_case, s21_tan_test11);
  tcase_add_test(tc_case, s21_tan_test12);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_tan_tests() {
  Suite *s = s21_tan_test_suite();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}
