#include "stack.h"
#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

Stack *stk_create() {
  Stack *stack = malloc(sizeof(Stack));
  stack->list = ll_create();
  return stack;
}

void stk_push(Stack *stack, int value) { ll_push(stack->list, value); };

int stk_pop(Stack *stack) {
  if (stk_is_empty(stack)) {
    fprintf(stderr, "error: stack is empty\n");
    exit(EXIT_FAILURE);
  }
  return ll_pop(stack->list);
};

int stk_size(Stack *stack) { return ll_size(stack->list); };

int stk_front(Stack *stack) {
  if (stk_is_empty(stack)) {
    fprintf(stderr, "error: stack is empty\n");
    exit(EXIT_FAILURE);
  }
  return ll_value_at(stack->list, stk_size(stack) - 1);
};

bool stk_is_empty(Stack *stack) { return ll_is_empty(stack->list); };

void stk_destroy(Stack *stack) {
  ll_destroy(stack->list);
  free(stack);
};

void stk_print(Stack *stack) {
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
  Stack *stack = stk_create();
  test_stack(stack);
  return EXIT_SUCCESS;
}

void test_stack(Stack *stack) {
  stk_push(stack, 5);
  stk_print(stack);
  stk_pop(stack);
  stk_print(stack);
  stk_destroy(stack);
}
