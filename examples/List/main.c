#define T int
#include "../../include/list.h"

int main() {
  List l;
  linit(&l);
  lpush(&l, 1);
  lpush(&l, 2);
  lpush(&l, 3);
  lpush(&l, 4);
  lpush(&l, 5);
  lpush(&l, 6);
  Node* tmp = l.head;
  while (tmp != NULL) {
    printf("%d -> ", tmp->data);
    tmp = tmp->next;
  }
  printf("\n");
  ldelete(&l);
}
