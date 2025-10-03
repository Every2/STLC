#define T int
#include "../../include/deque.h"

int main() {
    Deque d;
    dinit(&d);
    dpush_front(&d, 1);
    dpush_front(&d, 11);
    dpush_front(&d, 2);
    dpush_front(&d, 17);
    dpush_front(&d, 12);
    dpush_front(&d, 24);
    dpush_back(&d, 8);
    dpush_back(&d, 7);
    dpush_back(&d, 28);
    dpush_back(&d, 29);
    dpush_back(&d, 3);
    dpop_back(&d);
    dpop_back(&d);
    dpop_front(&d);
    dpop_front(&d);
    dpop_back(&d);
    dpop_back(&d);
    dpop_back(&d);
    for (int i = 0; i < d.size; i++)
        printf("Elements: %d\n", d.data[(d.start + i) % d.capacity]);
    ddelete(&d);
}
