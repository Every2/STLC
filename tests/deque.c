#define T int
#include "../include/deque.h"

#include "ctest.h"

CTEST_DATA(Deque_test) {
    Deque d;
};


CTEST_SETUP(Deque_test) {
    dinit(&data->d);
}

CTEST_TEARDOWN(Deque_test) {
    ddelete(&data->d);
}

CTEST2(Deque_test, test_init) {
    ASSERT_NOT_NULL(data->d.data);
    ASSERT_EQUAL(data->d.size, 0);
    ASSERT_EQUAL(data->d.capacity, 16);
}

CTEST2(Deque_test, push_back) {
    dpush_back(&data->d, 10);
    ASSERT_EQUAL(data->d.data[0], 10);
}

CTEST2(Deque_test, push_front) {
    dpush_front(&data->d, 11);
    ASSERT_EQUAL(data->d.data[7], 11);
}
