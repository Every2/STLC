#ifndef VECTOR_HEADER_H
#define VECTOR_HEADER_H
#include <stdlib.h>
#include <stdbool.h>

#define IMPL_METHOD(method) PREFIX_MACRO(, method)
#define PREFIX_MACRO(prefix, method) CONCAT(prefix, method)
#define CONCAT(prefix, method) prefix##method

#endif // VECTOR_HEADER_H

#ifndef T
#error "Generic type T must be defined, example: #define T int"
#endif

#ifndef VECTOR_LINKAGE
#define VECTOR_LINKAGE static inline
#endif

typedef struct Vector Vector;

#define VECTOR_vinit IMPL_METHOD(vinit)
#define VECTOR_vdelete IMPL_METHOD(vdelete)
#define VECTOR_vis_empty IMPL_METHOD(vis_empty)
#define VECTOR_vresize IMPL_METHOD(vresize)
#define VECTOR_vinsert IMPL_METHOD(vinsert)
#define VECTOR_vremove IMPL_METHOD(vremove)

#ifdef VECTOR_DECLS_ONLY

VECTOR_LINKAGE Vector VECTOR_vinit();
VECTOR_LINKAGE void VECTOR_vdelete(Vector *self);
VECTOR_LINKAGE bool VECTOR_vis_empty(Vector *self);
VECTOR_LINKAGE void VECTOR_vresize(Vector *self);
VECTOR_LINKAGE void VECTOR_vinsert(Vector *self, T element);
VECTOR_LINKAGE T VECTOR_vremove(Vector *self);

#endif

#undef T
#undef Vector
#undef VECTOR_LINKAGE
#undef VECTOR_vinit
#undef VECTOR_vdelete
#undef VECTOR_vis_empty
#undef VECTOR_vresize
#undef VECTOR_vinsert
#undef VECTOR_vremove
#ifdef VECTOR_DECLS_ONLY
#undef VECTOR_DECLS_ONLY
#endif
