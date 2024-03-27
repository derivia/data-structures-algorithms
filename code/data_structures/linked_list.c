#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

LinkedList *list_create() {
  LinkedList *list = malloc(sizeof(LinkedList));
  list->size = 0;
  list->head = NULL;
  list->tail = NULL;
  return list;
};

int list_size(LinkedList *linked_list) { return linked_list->size; };

bool list_is_empty(LinkedList *linked_list) { return linked_list->size == 0; };

int list_value_at(LinkedList *linked_list, int index) {
  Node *current_node = linked_list->head;
  int current_index = 0;
  while (current_node != NULL && current_index < index) {
    current_node = current_node->next;
    current_index++;
  }
  if (current_node != NULL) {
    return current_node->data;
  } else {
    return -1;
  }
};

void list_push(LinkedList *linked_list, int value) {
  Node *new_node = malloc(sizeof(Node));
  new_node->data = value;
  new_node->next = linked_list->head;
  linked_list->head = new_node;
  if (linked_list->tail == NULL) {
    linked_list->tail = new_node;
  }
    linked_list->size++;
}

int list_pop(LinkedList *linked_list) {
  if (linked_list == NULL || linked_list->head == NULL) {
    return -1;
  }
  Node *current_node = linked_list->head;
  Node *previous_node = NULL;
  while (current_node->next != NULL) {
    previous_node = current_node;
    current_node = current_node->next;
  }
  int popped = linked_list->tail->data;

  if (previous_node == NULL) {
    linked_list->head = NULL;
    linked_list->tail = NULL;
  } else {
    previous_node->next = NULL;
    linked_list->tail = previous_node;
  }

  free(linked_list->tail);
  current_node->next = NULL;
  linked_list->tail = current_node;
  linked_list->size--;
  return popped;
}

void list_insert_at(LinkedList *linked_list, int index, int value) {
  if (index < 0 || index > linked_list->size) {
    return;
  }
  Node *new_node = malloc(sizeof(Node));
  new_node->data = value;
  new_node->next = NULL;
  if (index == 0) {
    new_node->next = linked_list->head;
    linked_list->head = new_node;
    if (linked_list->tail == NULL) {
      linked_list->tail = new_node;
    }
  } else {
    Node *current_node = linked_list->head;
    int current_index = 0;
    while (current_index < index - 1) {
      current_node = current_node->next;
      current_index++;
    }
    new_node->next = current_node->next;
    current_node->next = new_node;
    if (current_node == linked_list->tail) {
      linked_list->tail = new_node;
    }
  }
  linked_list->size++;
};

void list_erase_at(LinkedList *linked_list, int index) {
  if (index < 0 || index > linked_list->size) {
    return;
  }
  if (index == 0) {
    Node *node_to_be_erased = linked_list->head;
    linked_list->head = linked_list->head->next;
    if (linked_list->head == NULL) {
      linked_list->tail = NULL;
    }
    free(linked_list->head);
  } else {
    Node *current_node = linked_list->head;
    for (int i = 0; i < index - 1; i++) {
      current_node = current_node->next;
    }
    Node *node_to_be_erased = current_node->next;
    current_node->next = node_to_be_erased->next;
    if (current_node->next == NULL) {
      // If the node to be deleted was the tail, update the tail pointer
      linked_list->tail = current_node;
    }
    free(node_to_be_erased);
  }
  linked_list->size--;
};

void list_remove_first_node_with_value(LinkedList *linked_list, int value) {
  if (linked_list->head == NULL) {
    return;
  }
  if (linked_list->head->data == value) {
    Node *node_to_be_deleted = linked_list->head;
    linked_list->head = linked_list->head->next;
    if (linked_list->head == NULL) {
      linked_list->tail = NULL;
    }
    free(node_to_be_deleted);
    linked_list->size--;
    return;
  }
  Node *previous_node = linked_list->head;
  Node *current_node = NULL;
  for (current_node = linked_list->head->next; current_node != NULL; current_node = current_node->next) {
    if (current_node->data == value) {
      previous_node->next = current_node->next;
      if (current_node == linked_list->tail) {
        linked_list->tail = previous_node;
      }
      free(current_node);
      linked_list->size--;
      return;
    }
    previous_node = current_node;
  }
};

void list_destroy(LinkedList *linked_list) {
  Node *current_node = linked_list->head;
  Node *next_node = NULL;
  while (current_node != NULL) {
    next_node = current_node->next;
    free(current_node);
    current_node = next_node;
  }
  free(linked_list);
}

void list_print(LinkedList *linked_list) {
  if (linked_list->head == NULL) {
    return;
  }
  Node *current_node = linked_list->head;
  printf("(head) ");
  while (current_node != NULL) {
    printf("%d -> ", current_node->data);
    current_node = current_node->next;
  }
  printf("NULL (tail)\n");
}

void test_linked_list(LinkedList *linked_list);

int main(int argc, char *argv[]) {
  LinkedList *linked_list = list_create();
  test_linked_list(linked_list);
  return EXIT_SUCCESS;
}

void test_linked_list(LinkedList *linked_list) {
  list_push(linked_list, 5);
  list_print(linked_list);
  list_insert_at(linked_list, 1, 9);
  list_print(linked_list);
  list_erase_at(linked_list, 1);
  list_print(linked_list);
  list_push(linked_list, 42);
  list_print(linked_list);
  list_destroy(linked_list);
}
