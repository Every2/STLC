#define T int
#include <stdio.h>

#include "../../include/stack.h"

int main() {
    Stack s;
    sinit(&s);
    spush(&s, 1);
    printf("Top: %d\n", stop(&s));
    spush(&s, 10);
    for (size_t i = 0; i < s.size; i++)
        printf("Two elements: %d\n", s.data[i]);
    printf("Pop: %d\n", spop(&s));
    for (size_t i = 0; i < s.size; i++)
        printf("All elements after pop: %d\n", s.data[i]);
    sdelete(&s);
}
