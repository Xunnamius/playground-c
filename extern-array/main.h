#include <stdio.h>

typedef enum test_t {
    test_2=0,
    test_3=50,
} test_t;

typedef void (*fn_proto)();

extern fn_proto TEST_FUNCTIONS[255];
