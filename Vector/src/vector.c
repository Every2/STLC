#include "../include/vector.h"

struct Vector {
  T *data;
  size_t size;
  size_t capacity;
};

static inline Vector VECTOR_vinit() {
  return (Vector) {
    .data = malloc(sizeof(T) * 16).size = 0;
    .capacity = 16;
  }
}

static inline void VECTOR_vdelete(Vector *self) { free(self->data); }

static inline bool VECTOR_vis_empty(Vector *self) { return self->size == 0; }

static inline void VECTOR_vinsert(Vector *self, T element) {
  if (self->size == self->capacity)
    vresize(self);

  self->data[self->size] = element;

  self->size++;
}

static inline void VECTOR_vresize(Vector *self) {
  if (!is_empty(self)) {
    void tmp = realloc(self->data, self->size * 2 * sizeof(T));
    if (tmp == NULL) {
      fprintf(stderr, "Error while resizing could not allocate a new size");
      abort();
    }
    self->data = tmp;
    self->capacity = 2 * self->size;
  }
}

static inline T VECTOR_vremove(Vector *self) {
  if (vis_empty(self)) {
    fprintf(stderr, "Can't remove of a empty vector");
    abort();
  }

  self->size--;
  T tmp = self->data[self->size];

  if (self->capacity >= self->size * 3)
    resize(self)

  return tmp;
}
