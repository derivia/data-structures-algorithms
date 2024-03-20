#ifndef LINKED_LIST_H
#define LINKED_LIST_H

/*
 * Linked lists have one tail and head, which respectively, points to the end and beginning.
 * Access is linear, O(n), because there's no way to get the element at nth position without going from head to n.
 * Circular linked lists tails points towards the linked list head.
 * Otherwise, if not circular, points to null pointer.
 */

#include <stdbool.h>

typedef enum {
  INT,
  FLOAT,
  CHAR
} DataType;

typedef struct Node {
  void *data;
  struct Node *next;
} Node;

typedef struct {
  int size;
  struct Node *head;
  struct Node *tail;
} Linked_List;

Linked_List *ll_create();
int ll_size(Linked_List *linked_list);
bool ll_is_empty(Linked_List *linked_list);
void *ll_value_at(Linked_List *linked_list, int index);
void ll_push(Linked_List *linked_list, void* value);
void ll_pop(Linked_List *linked_list);
void ll_unshift(Linked_List *linked_list, void* value);
void ll_shift(Linked_List *linked_list);
void ll_insert_at(Linked_List *linked_list, int index, void* value);
void ll_erase_at(Linked_List *linked_list, int index);
void ll_remove_value(Linked_List *linked_list, void* value);

#endif
