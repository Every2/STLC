#define T int
#include "../include/stack.h"

#include "ctest.h"

CTEST_DATA(Stack_test) {
    Stack s;
};


CTEST_SETUP(Stack_test) {
    sinit(&data->s);
}

CTEST_TEARDOWN(Stack_test) {
    sdelete(&data->s);
}

CTEST2(Stack_test, test_init) {
    ASSERT_NOT_NULL(data->s.data);
    ASSERT_EQUAL(data->s.size, 0);
    ASSERT_EQUAL(data->s.capacity, 16);
}

CTEST2(Stack_test, push_one_element) {
    spush(&data->s, 10);
    ASSERT_EQUAL(data->s.data[0], 10);
}

CTEST2(Stack_test, test_top) {
    spush(&data->s, 10);
    ASSERT_EQUAL(stop(&data->s), 10);
}
