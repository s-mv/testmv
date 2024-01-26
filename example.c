#define smv_testmv_enable
#include "testmv.h"

// functions to be tested: add, subtract
int add(int x, int y) { return x + y; }
int subtract(int x, int y) { return x - y; }

int main() {
  int result;

  testmv_start("addition");
  result = add(2, 3);
  testmv_assert(result == 5);
  testmv_end();

  testmv_start("subtraction");
  result = subtract(2, 3);
  testmv_assert(result == -1);
  testmv_end();

  testmv_start("both");
  result = subtract(2, 3);
  testmv_assert(result == add(2, -3));
  testmv_end();

  return 0;
}