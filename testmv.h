#ifndef smv_testmv_h
#define smv_testmv_h

#ifdef smv_testmv_enable

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *name;
char passed = 0;  // bool

static inline void _smv_testmv_assert(char passed, const char *condition) {
  printf("(testmv) Condition %s %s -- (%s)\n", name,
         passed ? "passed" : "failed", condition);
}

static inline void testmv_start(const char *test_name) {
  name = malloc(sizeof(test_name));
  memcpy(name, test_name, sizeof(test_name));
}

static inline void testmv_end() {
  passed = 0;
  free(name);
}

#define testmv_assert(_condition) \
  _smv_testmv_assert((_condition), (#_condition))

#endif

#endif