#include "stack.h"
#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

Stack *stack_create() {
  Stack *stack = malloc(sizeof(Stack));
  stack->list = list_create();
  return stack;
}

void stack_push(Stack *stack, int value) { list_push(stack->list, value); };

int stack_pop(Stack *stack) {
  if (stack_is_empty(stack)) {
    fprintf(stderr, "error: stack is empty\n");
    exit(EXIT_FAILURE);
  }
  return list_pop(stack->list);
}

int stack_front(Stack *stack) {
  if (stack_is_empty(stack)) {
    fprintf(stderr, "error: stack is empty\n");
    exit(EXIT_FAILURE);
  }
  return list_value_at(stack->list, stack_size(stack) - 1);
}

int stack_size(Stack *stack) { return list_size(stack->list); }

bool stack_is_empty(Stack *stack) { return list_is_empty(stack->list); };

void stack_destroy(Stack *stack) {
  list_destroy(stack->list);
  free(stack);
}

void stack_print(Stack *stack) {
  if (stack->list->head == NULL || stack->list->size == 0) {
    return;
  }
  Node *current_node = stack->list->head;
  printf("stack: ");
  while (current_node != NULL) {
    printf("[%d]", current_node->data);
    current_node = current_node->next;
  }
  printf("\n");
}

void test_stack(Stack *stack);

int main(int argc, char *argv[]) {
  Stack *stack = stack_create();
  test_stack(stack);
  return EXIT_SUCCESS;
}

void test_stack(Stack *stack) {
  stack_push(stack, 5);
  stack_print(stack);
  stack_pop(stack);
  stack_print(stack);
  stack_destroy(stack);
}
