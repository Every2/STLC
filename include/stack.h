#ifndef STACK_HEADER_H
#define STACK_HEADER_H
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define IMPL_METHOD(method) PREFIX_MACRO(, method)
#define PREFIX_MACRO(prefix, method) CONCAT(prefix, method)
#define CONCAT(prefix, method) prefix##method

#endif  // STACK_HEADER_H

#ifndef T
#error "Generic type T must be defined, example: #define T int"
#endif

#ifndef STACK_LINKAGE
#define STACK_LINKAGE static inline
#endif

typedef struct Stack Stack;

struct Stack {
    T *data;
    size_t size;
    size_t capacity;
};

#define STACK_sinit IMPL_METHOD(sinit)
#define STACK_sdelete IMPL_METHOD(sdelete)
#define STACK_sis_empty IMPL_METHOD(sis_empty)
#define STACK_sresize IMPL_METHOD(sresize)
#define STACK_spush IMPL_METHOD(spush)
#define STACK_spop IMPL_METHOD(spop)
#define STACK_stop IMPL_METHOD(stop)

#ifdef STACK_DECLS_ONLY

STACK_LINKAGE void STACK_sinit(Stack *self);
STACK_LINKAGE void STACK_sdelete(Stack *self);
STACK_LINKAGE bool STACK_sis_empty(Stack *self);
STACK_LINKAGE void STACK_sresize(Stack *self);
STACK_LINKAGE void STACK_spush(Stack *self, T element);
STACK_LINKAGE T STACK_spop(Stack *self);
STACK_LINKAGE T STACK_stop(Stack *self);
#else
STACK_LINKAGE void STACK_sinit(Stack *self) {
    self->data = malloc(sizeof(T) * 16);
    self->size = 0;
    self->capacity = 16;
}

STACK_LINKAGE void STACK_sdelete(Stack *self) {
    free(self->data);
}

STACK_LINKAGE bool STACK_sis_empty(Stack *self) {
    return self->size == 0;
}

STACK_LINKAGE void STACK_sresize(Stack *self) {
    if (!sis_empty(self)) {
        void *tmp = realloc(self->data, self->size * 2 * sizeof(T));
        assert(tmp != NULL);
        self->data = tmp;
        self->capacity = 2 * self->size;
    }
}

STACK_LINKAGE void STACK_spush(Stack *self, T element) {
    if (self->size == self->capacity)
        sresize(self);

    self->data[self->size] = element;

    self->size++;
}


STACK_LINKAGE T STACK_spop(Stack *self) {
    assert(!sis_empty(self));

    self->size--;
    T tmp = self->data[self->size];

    if (self->capacity >= self->size * 3)
        sresize(self);

    return tmp;
}

STACK_LINKAGE T STACK_stop(Stack *self) {
    assert(!sis_empty(self));
    assert(self->size != 0);

    return self->data[self->size - 1];
}

#endif

#undef T
#undef Stack
#undef STACK_LINKAGE
#undef STACK_sinit
#undef STACK_sdelete
#undef STACK_sis_empty
#undef STACK_sresize
#undef STACK_spush
#undef STACK_spop
#undef STACK_stop
#ifdef STACK_DECLS_ONLY
#undef STACK_DECLS_ONLY
#endif
