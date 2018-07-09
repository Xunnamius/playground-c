#include "main.h"

fn_proto TEST_FUNCTIONS[255];

static fn_proto getfn(test_t fn)
{
    return TEST_FUNCTIONS[fn];
}

int main()
{
    fn_proto fn1 = getfn(test_2);
    fn_proto fn2 = getfn(test_3);

    fn1();
    fn2();
    return 0;
}
