#ifndef LIST_HEADER_H
#define LIST_HEADER_H
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define IMPL_METHOD(method) PREFIX_MACRO(, method)
#define PREFIX_MACRO(prefix, method) CONCAT(prefix, method)
#define CONCAT(prefix, method) prefix##method
#define Max(a, b) (a > b ? a : b)
#endif  // LIST_HEADER_H

#ifndef T
#error "Generic type T must be defined, example: #define T int"
#endif

#ifndef LIST_LINKAGE
#define LIST_LINKAGE static inline
#endif

typedef struct Node Node;
typedef struct List List;

struct Node {
    T data;
    Node *next;
};

struct List {
    Node *head;
    Node *tail;
    size_t size;
};

#define LIST_lnew_node IMPL_METHOD(lnew_node)
#define LIST_linit IMPL_METHOD(linit)
#define LIST_lis_empty IMPL_METHOD(lis_empty)
#define LIST_lpush IMPL_METHOD(lpush)
#define LIST_lpop IMPL_METHOD(lpop)
#define LIST_ldelete IMPL_METHOD(ldelete)

#ifdef LIST_DECLS_ONLY

LIST_LINKAGE Node LIST_lnew_node(T element);
LIST_LINKAGE void LIST_linit(List *self);
LIST_LINKAGE bool lis_empty(List *self);
LIST_LINKAGE T LIST_lpush(List *self, T element);
LIST_LINKAGE T LIST_lpop(List *self);
LIST_LINKAGE void LIST_ldelete(List *self);
#else
LIST_LINKAGE Node *LIST_lnew_node(T element) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = element;
    new_node->next = NULL;
    return new_node;
}

LIST_LINKAGE void LIST_linit(List *self) {
    self->head = NULL;
    self->tail = NULL;
    self->size = 0;
}

LIST_LINKAGE bool lis_empty(List *self) {
    return self->size == 0;
}

LIST_LINKAGE T LIST_lpush(List *self, T element) {
    Node *node = lnew_node(element);
    node->next = self->head;
    self->head = node;

    if (lis_empty(self))
        self->tail = node;

    self->size++;

    return element;
}

LIST_LINKAGE T LIST_lpop(List *self) {
    assert(!lis_empty(self));
    T tmp = self->head->data;
    Node *node = self->head;
    self->head = self->head->next;
    free(node);

    if (self->size - 1 == 0)
        self->tail = NULL;
    else
        self->size = self->size - 1;

    return tmp;
}

LIST_LINKAGE void LIST_ldelete(List *self) {
    assert(!lis_empty(self));
    Node *next = self->head;
    while (next->next != NULL) {
        Node *tmp = next->next;
        free(next);
        next = tmp;
    }
    free(self->tail);
}

#endif

#undef T
#undef List
#undef LIST_LINKAGE
#undef LIST_lnew_node
#undef LIST_linit
#undef LIST_lpush
#undef LIST_lpop
#undef LIST_lis_empty
#undef LIST_ldelete
#ifdef LIST_DECLS_ONLY
#undef LIST_DECLS_ONLY
#endif
