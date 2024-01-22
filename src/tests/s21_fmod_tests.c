#include "s21_math_tests.h"

START_TEST(s21_fmod_test0) { ck_assert_ldouble_nan(s21_fmod(0.0, 0.0)); }
END_TEST

START_TEST(s21_fmod_test1) { ck_assert_ldouble_nan(s21_fmod(1.0, 0.0)); }
END_TEST

START_TEST(s21_fmod_test2) {
  ck_assert_ldouble_le(s21_fabs(s21_fmod(1.0, -1.0) - fmodl(1.0, -1.0)), 1e-6);
}
END_TEST

START_TEST(s21_fmod_test3) {
  ck_assert_ldouble_le(s21_fabs(s21_fmod(29.7, 9.9) - fmodl(29.7, 9.9)), 1e-6);
}
END_TEST

START_TEST(s21_fmod_test4) {
  ck_assert_ldouble_le(
      s21_fabs(s21_fmod(0.135126315234, 1.0) - fmodl(0.135126315234, 1.0)),
      1e-6);
}
END_TEST

START_TEST(s21_fmod_test5) {
  ck_assert_ldouble_le(
      s21_fabs(s21_fmod(-0.4568784, 0.0012) - fmodl(-0.4568784, 0.0012)), 1e-6);
}
END_TEST

START_TEST(s21_fmod_test6) {
  ck_assert_ldouble_le(
      s21_fabs(s21_fmod(312.471724611, 2.3456) - fmodl(312.47172461, 2.3456)),
      1e-6);
}
END_TEST

START_TEST(s21_fmod_test7) {
  ck_assert_ldouble_le(s21_fmod(0.0, S21_INF), fmodl(0.0, S21_INF));
}
END_TEST

START_TEST(s21_fmod_test8) {
  ck_assert_ldouble_le(s21_fmod(1.0, -S21_INF), fmodl(1.0, -S21_INF));
}
END_TEST

START_TEST(s21_fmod_test9) { ck_assert_ldouble_nan(s21_fmod(S21_NAN, 1.0)); }
END_TEST

START_TEST(s21_fmod_test10) { ck_assert_ldouble_nan(s21_fmod(1.0, S21_NAN)); }
END_TEST

Suite *s21_fmod_test_suite() {
  Suite *s = suite_create("s21_fmod");
  TCase *tc_case = tcase_create("s21_fmod_case");
  tcase_add_test(tc_case, s21_fmod_test0);
  tcase_add_test(tc_case, s21_fmod_test1);
  tcase_add_test(tc_case, s21_fmod_test2);
  tcase_add_test(tc_case, s21_fmod_test3);
  tcase_add_test(tc_case, s21_fmod_test4);
  tcase_add_test(tc_case, s21_fmod_test5);
  tcase_add_test(tc_case, s21_fmod_test6);
  tcase_add_test(tc_case, s21_fmod_test7);
  tcase_add_test(tc_case, s21_fmod_test8);
  tcase_add_test(tc_case, s21_fmod_test9);
  tcase_add_test(tc_case, s21_fmod_test10);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_fmod_tests() {
  Suite *s = s21_fmod_test_suite();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}
