#include "./test.h"

int main() {
  int count = 1;
  Suite *cases[2];
  cases[0] = parse_cases();
  cases[1] = calc_cases();
  cases[2] = NULL;

  printf("START TEST\n");
  for (Suite **currentTest = cases; *currentTest != NULL; currentTest++) {
    printf("Current Test: %d\n", count);
    count++;
    SRunner *runner = srunner_create(*currentTest);
    srunner_set_fork_status(runner, CK_NOFORK);
    srunner_run_all(runner, CK_NORMAL);
    srunner_free(runner);
    printf("\n");
  }
  return 0;
}