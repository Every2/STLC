#ifndef DEQUE_HEADER_H
#define DEQUE_HEADER_H
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define IMPL_METHOD(method) PREFIX_MACRO(, method)
#define PREFIX_MACRO(prefix, method) CONCAT(prefix, method)
#define CONCAT(prefix, method) prefix##method
#define Max(a, b) (a > b ? a : b)
#endif  // DEQUE_HEADER_H

#ifndef T
#error "Generic type T must be defined, example: #define T int"
#endif

#ifndef DEQUE_LINKAGE
#define DEQUE_LINKAGE static inline
#endif

typedef struct Deque Deque;

struct Deque {
    T *data;
    T start;
    size_t size;
    size_t capacity;
};

#define DEQUE_dinit IMPL_METHOD(dinit)
#define DEQUE_ddelete IMPL_METHOD(ddelete)
#define DEQUE_dis_empty IMPL_METHOD(dis_empty)
#define DEQUE_dresize IMPL_METHOD(dresize)
#define DEQUE_dpush_back IMPL_METHOD(dpush_back)
#define DEQUE_dpush_front IMPL_METHOD(dpush_front)
#define DEQUE_dpop_back IMPL_METHOD(dpop_back)
#define DEQUE_dpop_front IMPL_METHOD(dpop_front)

#ifdef DEQUE_DECLS_ONLY

DEQUE_LINKAGE void DEQUE_dinit(Deque *self);
DEQUE_LINKAGE void DEQUE_ddelete(Deque *self);
DEQUE_LINKAGE bool DEQUE_dis_empty(Deque *self);
DEQUE_LINKAGE void DEQUE_dresize(Deque *self);
DEQUE_LINKAGE void DEQUE_dpush_back(Deque *self, T element);
DEQUE_LINKAGE void DEQUE_dpush_front(Deque *self, T element);
DEQUE_LINKAGE T DEQUE_dpop_back(Deque *self);
DEQUE_LINKAGE T DEQUE_dpop_front(Deque *self);
#else
DEQUE_LINKAGE void DEQUE_dinit(Deque *self) {
    self->data = malloc(sizeof(T) * 8);
    self->start = 0;
    self->size = 0;
    self->capacity = 8;
}

DEQUE_LINKAGE void DEQUE_ddelete(Deque *self) {
    free(self->data);
}

DEQUE_LINKAGE bool DEQUE_dis_empty(Deque *self) {
    return self->size == 0 && self->start == 0;
}

DEQUE_LINKAGE void DEQUE_dresize(Deque *self) {
    if (!dis_empty(self)) {
        void *tmp = malloc(sizeof(T) * Max(1, 2 * self->size));
        assert(tmp != NULL);
        T *new = tmp;
        for (size_t i = 0; i < self->size; i++)
            new[i] = self->data[(self->start + i) % self->capacity];
        ddelete(self);
        self->data = new;
        self->start = 0;
	self->capacity = self->size * 2;
    }
}

DEQUE_LINKAGE void DEQUE_dpush_back(Deque *self, T element) {
    if (self->size == self->capacity)
        dresize(self);

    T index = (self->start + self->size) % self->capacity;
    self->data[index] = element;
    self->size++;
}

DEQUE_LINKAGE void DEQUE_dpush_front(Deque *self, T element) {
    if (self->size == self->capacity)
        dresize(self);

    if (self->start == 0) {
        T index = self->capacity - 1;
        self->data[index] = element;
        self->size++;
        self->start = index;
    } else {
        T index = (self->start - 1) % self->capacity;
        self->data[index] = element;
        self->size++;
        self->start = index;
    }
}

DEQUE_LINKAGE T DEQUE_dpop_back(Deque *self) {
    if (!dis_empty(self)) {
        T index = (self->start + self->size - 1) % self->capacity;
        T tmp = self->data[index];
        self->size--;
        if (self->capacity >= 3 * self->size)
            dresize(self);
        return tmp;
    }
}

DEQUE_LINKAGE T DEQUE_dpop_front(Deque *self) {
    if (!dis_empty(self)) {
        T tmp = self->data[self->start];
        self->size--;
        self->start = (self->start + 1) % self->capacity;
        if (self->capacity >= 3 * self->size)
            dresize(self);
        return tmp;
    }
}

#endif

#undef T
#undef Deque
#undef DEQUE_LINKAGE
#undef DEQUE_dinit
#undef DEQUE_ddelete
#undef DEQUE_dis_empty
#undef DEQUE_dresize
#undef DEQUE_dpush
#undef DEQUE_dpop
#undef DEQUE_dtop
#ifdef DEQUE_DECLS_ONLY
#undef DEQUE_DECLS_ONLY
#endif
