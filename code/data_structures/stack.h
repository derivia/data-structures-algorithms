#ifndef STACK_H
#define STACK_H
#include "linked_list.h"
#include <stdbool.h>

typedef struct {
  LinkedList *list;
} Stack;

void stack_push(Stack *stack, int value);
int stack_pop(Stack *stack);
int stack_size(Stack *stack);
int stack_front(Stack *stack);
bool stack_is_empty(Stack *stack);
void stack_destroy(Stack *stack);
void stack_print(Stack *stack);

#endif // !STACK_H
