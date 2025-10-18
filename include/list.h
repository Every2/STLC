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

typedef struct List List;

struct List {
    T data;
    List *next;
};

#define LIST_lnew_node IMPL_METHOD(lnew_node)
#define LIST_lis_empty IMPL_METHOD(lis_empty)
#define LIST_ldelete IMPL_METHOD(ldelete)
#define LIST_lpush_back IMPL_METHOD(lpush_back)
#define LIST_lpush_front IMPL_METHOD(lpush_front)
#define LIST_ldelete_back IMPL_METHOD(ldelete_back)
#define LIST_ldelete_front IMPL_METHOD(ldelete_front)

#ifdef LIST_DECLS_ONLY

LIST_LINKAGE List LIST_lnew_node(T element);
LIST_LINKAGE bool LIST_lis_empty(List **self);
LIST_LINKAGE void LIST_lpush_back(List **self, T element);
LIST_LINKAGE void LIST_lpush_front(List **self, T element);
LIST_LINKAGE void LIST_ldelete_back(List **self);
LIST_LINKAGE viud LIST_ldelete_front(List **self);
#else
LIST_LINKAGE List *LIST_lnew_node(T element) {
    List *new_node = (List *) malloc(sizeof(List));
    new_node->data = element;
    new_node->next = NULL;
    return new_node;
}

LIST_LINKAGE bool LIST_lis_empty(List **self) {
    return *self == NULL;
}

LIST_LINKAGE void LIST_lpush_back(List **self, T element) {
    List *new_node = lnew_node(element);
    if (lis_empty(self)) {
        *self = new_node;
    } else {
        List *tmp = *self;
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new_node;
    }
}

LIST_LINKAGE void LIST_lpush_front(List **self, T element) {
    List *new_node = lnew_node(element);
    new_node->next = *self;
    *self = new_node;
}

LIST_LINKAGE void LIST_ldelete_back(List **self) {
    if (lis_empty(self))
        return;

    if ((*self)->next == NULL) {
        free(*self);
        *self = NULL;
        return;
    }

    List *tmp = *self;
    while (tmp->next->next != NULL)
        tmp = tmp->next;
    free(tmp->next);
    tmp->next = NULL;
}

LIST_LINKAGE void LIST_ldelete_front(List **self) {
    if (!lis_empty(self)) {
        List *tmp = *self;
        *self = (*self)->next;
        free(tmp);
    }
}

#endif

#undef T
#undef List
#undef LIST_LINKAGE
#undef LIST_lnew_node
#undef LIST_ldelete
#undef LIST_lis_empty
#undef LIST_dresize
#undef LIST_lpush_back
#undef LIST_lpush_front
#undef LIST_ldelete_back
#undef LIST_ldelete_front
#ifdef LIST_DECLS_ONLY
#undef LIST_DECLS_ONLY
#endif
