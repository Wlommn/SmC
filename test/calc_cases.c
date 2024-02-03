#include "./test.h"
#include "../src/calc/calc.c"

START_TEST(calc_test_1) {
    char expression[IO_MAX_SIZE] = "2 5 F";
    double expected = 10.0;
    double result = calc(expression, 0);
    ck_assert_double_eq(expected, result);
}
END_TEST

START_TEST(calc_test_2) {
    char expression[IO_MAX_SIZE] = "x 2 F";
    double expected = 10.0;
    double result = calc(expression, 5.0);
    ck_assert_double_eq(expected, result);
}
END_TEST

START_TEST(calc_test_3) {
    char expression[IO_MAX_SIZE] = "0.2 0.3 D";
    double expected = 0.5;
    double result = calc(expression, 0);
    ck_assert_double_eq(expected, result);
}
END_TEST

START_TEST(calc_test_4) {
    char expression[IO_MAX_SIZE] = "x x F";
    double expected = 4;
    double result = calc(expression, 2);
    ck_assert_double_eq(expected, result);
}
END_TEST

START_TEST(calc_test_5) {
    char expression[IO_MAX_SIZE] = "x x F";
    double expected = 2.3716;
    double result = calc(expression, 1.54);
    ck_assert_double_eq(expected, result);
}
END_TEST


Suite *calc_cases() {
    Suite *suite = suite_create("calc_test");
    TCase *testCase = tcase_create("calc_test");

    tcase_add_test(testCase, calc_test_1);
    tcase_add_test(testCase, calc_test_2);
    tcase_add_test(testCase, calc_test_3);
    tcase_add_test(testCase, calc_test_4);
    tcase_add_test(testCase, calc_test_5);

    suite_add_tcase(suite, testCase);
    return suite;
}
