#define T int
#include "../../include/list.h"

int main() {
  List* l = NULL;
  lpush_back(&l, 1);
  lpush_front(&l, 2);
  lpush_back(&l, 3);
  while (l != NULL) {
    printf("%d -> \n", l->data);
    l = l->next;
  }

  ldelete_front(&l);
}
