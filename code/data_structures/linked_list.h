#ifndef LINKED_LIST_H
#define LINKED_LIST_H

/*
 * Linked lists have one tail and head, which respectively, points to the end and beginning.
 * Access is linear, O(n), because there's no way to get the element at nth position without going from head to n.
 * Circular linked lists tails points towards the linked list head.
 * Otherwise, if not circular, points to null pointer.
 */

#include <stdbool.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

typedef struct {
  int size;
  struct Node *head;
  struct Node *tail;
} LinkedList;

LinkedList *ll_create();
int ll_size(LinkedList *linked_list);
bool ll_is_empty(LinkedList *linked_list);
int ll_value_at(LinkedList *linked_list, int index);
void ll_push(LinkedList *linked_list, int value);
int ll_pop(LinkedList *linked_list);
void ll_insert_at(LinkedList *linked_list, int index, int value);
void ll_erase_at(LinkedList *linked_list, int index);
void ll_remove_value(LinkedList *linked_list, int value);
void ll_destroy(LinkedList *linked_list);
void ll_print(LinkedList *linked_list);

#endif
