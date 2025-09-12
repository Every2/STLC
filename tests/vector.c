#define T int
#include "../include/vector.h"

#include "ctest.h"

CTEST_DATA(Vec_test) {
    Vector v;
};


CTEST_SETUP(Vec_test) {
    vinit(&data->v);
}

CTEST_TEARDOWN(Vec_test) {
    vdelete(&data->v);
}

CTEST2(Vec_test, test_init) {
    ASSERT_NOT_NULL(data->v.data);
    ASSERT_EQUAL(data->v.size, 0);
    ASSERT_EQUAL(data->v.capacity, 16);
}

CTEST2(Vec_test, insert_one_element) {
    vinsert(&data->v, 10);
    ASSERT_EQUAL(data->v.data[0], 10);
}
