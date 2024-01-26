#ifndef smv_testmv_h
#define smv_testmv_h

#ifdef smv_testmv_enable

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *test_name;
char *session_name;
int passed = 0;
int failed = 0;

// extends a macro, hence _smv_testmv
static inline void _smv_testmv_assert(char did_pass, const char *condition) {
  if (did_pass) passed++;
  printf("(testmv) Session %s: Condition %s %s -- (%s)\n", session_name,
         test_name, did_pass ? "passed" : "failed", condition);
}

static inline void testmv_start(const char *name) {
  int len = (strlen(name) + 1) * sizeof(char);
  test_name = malloc(len);
  memcpy(test_name, name, len);
}

static inline void testmv_end() { free(test_name); }

static inline void testmv_session_start(const char *name) {
  int len = strlen(name) + 1;
  session_name = malloc(len);
  memcpy(session_name, name, len);
  printf("(testmv) Session started: %s\n", name);
}

static inline void testmv_session_end() {
  printf("(testmv) Session ended: %s\n", session_name);
  printf("(testmv) Session summary:\n");
  if (failed > 0)
    printf("         Session FAILED!\n");
  else
    printf("         Session PASSED!\n");

  printf(
      "         Passed: %d\n"
      "         Failed: %d\n",
      passed, failed);

  // reset everything
  passed = 0;
  failed = 0;
  free(session_name);
}

#define testmv_assert(_condition) \
  _smv_testmv_assert((_condition), (#_condition))

#else

#include <stdio.h>

// if testing isn't enabled just completely ignore the tests
// this makes testing easier since the developer doesn't have to remove tests
// but simply comment out `#define testmv_enable` from their code!
// TODO: fine a better way than if(0) perhaps
// I know modern compilers

#define testmv_session_start(_name) if (0) {
#define testmv_start(_name)

#define testmv_assert(_condition)

#define testmv_end()

#define testmv_session_end() }

#endif

#endif