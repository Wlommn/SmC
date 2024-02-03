#include "./test.h"
#include "../src/parse/parse.c"

extern char postfix[IO_MAX_SIZE * 2];

START_TEST(parse_test_1) {
    char input[IO_MAX_SIZE] = "2 * 5";
    char expected[IO_MAX_SIZE] = "2 5 F";
    char *result = infix_to_postfix(input);
    ck_assert_str_eq(expected, result);
}
END_TEST

START_TEST(parse_test_2) {
    char input[IO_MAX_SIZE] = "2 * x";
    char expected[IO_MAX_SIZE] = "2 x F";
    char *result = infix_to_postfix(input);
    ck_assert_str_eq(expected, result);
}
END_TEST

START_TEST(parse_test_3) {
    char input[IO_MAX_SIZE] = "x*x";
    char expected[IO_MAX_SIZE] = "x x F";
    char *result = infix_to_postfix(input);
    ck_assert_str_eq(expected, result);
}
END_TEST

Suite *parse_cases() {
    Suite *suite = suite_create("parse_test");
    TCase *testCase = tcase_create("parse_test");

    tcase_add_test(testCase, parse_test_1);
    tcase_add_test(testCase, parse_test_2);
    tcase_add_test(testCase, parse_test_3);

    suite_add_tcase(suite, testCase);
    return suite;
}
