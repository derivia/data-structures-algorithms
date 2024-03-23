#ifndef QUEUE_H
#define QUEUE_H
#include "array.h"
#include "linked_list.h"

typedef struct {
  LinkedList *list;
} ListQueue;

typedef struct {
  Array *array;
} ArrayQueue;

ArrayQueue queue_array_create();
void queue_array_enqueue(ArrayQueue *queue, int value);
bool queue_array_is_empty(ArrayQueue *queue);
bool queue_array_is_full(ArrayQueue *queue);
int queue_array_dequeue(ArrayQueue *queue);

ListQueue queue_list_create();
void queue_list_enqueue(ListQueue *queue, int value);
bool queue_list_is_empty(ListQueue *queue);
bool queue_list_is_full(ListQueue *queue);
int queue_list_dequeue(ListQueue *queue);

#endif // !QUEUE_H
