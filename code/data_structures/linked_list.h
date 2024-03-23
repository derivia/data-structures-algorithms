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

LinkedList *list_create();
int list_size(LinkedList *linked_list);
bool list_is_empty(LinkedList *linked_list);
int list_value_at(LinkedList *linked_list, int index);
void list_push(LinkedList *linked_list, int value);
int list_pop(LinkedList *linked_list);
void list_insert_at(LinkedList *linked_list, int index, int value);
void list_erase_at(LinkedList *linked_list, int index);
void list_remove_value(LinkedList *linked_list, int value);
void list_destroy(LinkedList *linked_list);
void list_print(LinkedList *linked_list);

#endif
