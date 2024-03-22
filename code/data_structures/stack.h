#ifndef STACK_H
#define STACK_H
#include "linked_list.h"
#include <stdbool.h>

typedef struct {
  LinkedList *list;
} Stack;

void stk_push(Stack *stack, int value);
int stk_pop(Stack *stack);
int stk_size(Stack *stack);
int stk_front(Stack *stack);
bool stk_is_empty(Stack *stack);
void stk_destroy(Stack *stack);
void stk_print(Stack *stack);

#endif // !STACK_H
