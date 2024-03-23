#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

Queue *queue_create() {
  Queue *queue = malloc(sizeof(Queue));
  queue->list = list_create();
  return queue;
}

void queue_enqueue(Queue *queue, int value) { list_push(queue->list, value); }

int queue_dequeue(Queue *queue) {
  if (queue->list == NULL || queue->list->head == NULL) {
    return -1;
  }
  Node *temp = queue->list->head;
  int dequeued_data = temp->data;
  queue->list->head = queue->list->head->next;
  free(temp);
  queue->list->size--;
  if (queue->list->head == NULL) {
    queue->list->tail = NULL;
  }
  return dequeued_data;
}

void queue_print(Queue *queue) {
  if (queue->list->head == NULL || queue->list->size == 0) {
    return;
  }
  Node *current_node = queue->list->head;
  printf("queue: ");
  while (current_node != NULL) {
    printf("[%d]", current_node->data);
    current_node = current_node->next;
  }
  printf("\n");
}

bool queue_is_empty(Queue *queue) { return list_is_empty(queue->list); }

int queue_size(Queue *queue) { return list_size(queue->list); }

void queue_test(Queue *queue);

int main(int argc, char *argv[]) {
  Queue *queue = queue_create();
  queue_test(queue);
  return EXIT_SUCCESS;
}

void queue_test(Queue *queue) {
  queue_enqueue(queue, 5);
  printf("queue size: %d\n", queue_size(queue));
  queue_print(queue);
  queue_enqueue(queue, 7);
  printf("removing first element\n");
  int test = queue_dequeue(queue);
  queue_print(queue);
  queue_enqueue(queue, 9);
  queue_print(queue);
  int test2 = queue_dequeue(queue);
  queue_print(queue);
  printf("queue is empty?: %d\n", queue_is_empty(queue));
  printf("dequeued value: %d\n", test);
};
