#ifndef STACK_HEADER_H
#define STACK_HEADER_H
#include <stdlib.h>

#define IMPL_METHOD(method) PREFIX_MACRO(, method)
#define PREFIX_MACRO(prefix, method) CONCAT(prefix, method)
#define CONCAT(prefix, method) prefix##method

#endif // STACK_HEADER_H

#ifndef T
#error "Generic type T must be defined, example: #define T int"
#endif

#ifndef TYPE_NAME
#define TYPE_NAME PREFIX_MACRO(PREFIX_MACRO(self, _), T)
#endif

#ifndef STACK_LINKAGE
#define STACK_LINKAGE static inline
#endif

typedef struct TYPE_NAME TYPE_NAME;
struct TYPE_NAME {
    T* data;
    size_t size;
    size_t capacity;
};

#define STACK_push IMPL_METHOD(push)

#ifdef STACK_DECLS_ONLY

STACK_LINKAGE void STACK_push(TYPE_NAME* self, T elem);

#else

STACK_LINKAGE
void STACK_push(TYPE_NAME* self, T elem){
    // todo
}
#endif

#undef T
#undef TYPE_NAME
#undef STACK_LINKAGE
#undef STACK_push
#ifdef STACK_DECLS_ONLY
#undef STACK_DECLS_ONLY
#endif
