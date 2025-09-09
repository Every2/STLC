#define T int
#include "../include/vector.h"

#include "ctest.h"

CTEST(Vec_test, init_is_correctly) {
    Vector v;
    vinit(&v);
    ASSERT_EQUAL(v.data[v.size], 0);
    ASSERT_EQUAL(v.size, 0);
    ASSERT_EQUAL(v.capacity, 16);
}

CTEST(Vec_test, insert_one_element) {
    Vector v;
    vinit(&v);
    vinsert(&v, 10);
    ASSERT_EQUAL(v.data[0], 10);
}
