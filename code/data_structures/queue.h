#ifndef QUEUE_H
#define QUEUE_H
#include "array.h"
#include "linked_list.h"

typedef struct {
  LinkedList *list;
} Queue;

Queue *queue_create();
void queue_enqueue(Queue *queue, int value);
bool queue_is_empty(Queue *queue);
bool queue_is_full(Queue *queue);
int queue_dequeue(Queue *queue);
int queue_size(Queue *queue);
void queue_print(Queue *queue);

#endif // !QUEUE_H
