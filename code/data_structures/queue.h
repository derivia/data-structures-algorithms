#ifndef QUEUE_H
#define QUEUE_H
#include "array.h"
#include "linked_list.h"

typedef struct {
  LinkedList *list;
} ListQueue;

typedef struct {
  MyArray *array;
} ArrayQueue;

ArrayQueue que_create_array();
void arr_enqueue(ArrayQueue *array, int value);
bool arr_is_empty(ArrayQueue *array);
bool arr_is_full(ArrayQueue *array);
int arr_dequeue(ArrayQueue *array);
ListQueue que_create_list();
void list_enqueue(ListQueue *list, int value);
bool list_is_empty(ListQueue *list, int value);
bool list_is_full(ListQueue *list, int value);
int list_dequeue(ListQueue *list, int value);

#endif // !QUEUE_H
