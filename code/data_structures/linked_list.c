#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

Linked_List *ll_create() {
  Linked_List *list = malloc(sizeof(Linked_List));
  list->size = 0;
  list->head = NULL;
  list->tail = NULL;
  return list;
};

int ll_size(Linked_List *linked_list) { return linked_list->size; };

bool ll_is_empty(Linked_List *linked_list) { return linked_list->size == 0; };

void *ll_value_at(Linked_List *linked_list, int index) {
  if (linked_list->size != 0) {
    for (int i = 0; i < linked_list->size; i++) {
      // TODO
    }
  }
  return NULL;
};

void ll_push(Linked_List *linked_list, void *value);
void ll_pop(Linked_List *linked_list);
void ll_unshift(Linked_List *linked_list, void *value);
void ll_shift(Linked_List *linked_list);
void ll_insert_at(Linked_List *linked_list, int index, void *value);
void ll_erase_at(Linked_List *linked_list, int index);
void ll_remove_value(Linked_List *linked_list, void *value);

int main(int argc, char *argv[]) { return EXIT_SUCCESS; }
