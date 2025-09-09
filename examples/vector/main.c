#define T int
#include <stdio.h>

#include "../../include/vector.h"

int main() {
    Vector v;
    vinit(&v);
    vinsert(&v, 10);
    vinsert(&v, 20);

    for (size_t i = 0; i < v.size; i++)
        printf("Inserted elements: %d\n", v.data[i]);

    vremove(&v);

    for (size_t i = 0; i < v.size; i++)
        printf("After remove: %d\n", v.data[i]);

    vdelete(&v);
}
