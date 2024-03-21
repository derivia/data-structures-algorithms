#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

Linked_List *ll_create() {
  Linked_List *list = malloc(sizeof(Linked_List));
  list->size = 0;
  list->head = NULL;
  list->tail = NULL;
  return list;
};

int ll_size(Linked_List *linked_list) { return linked_list->size; };

bool ll_is_empty(Linked_List *linked_list) { return linked_list->size == 0; };

int ll_value_at(Linked_List *linked_list, int index) {
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

void ll_push(Linked_List *linked_list, int value) {
  Node *new_node = malloc(sizeof(Node));
  new_node->data = value;
  new_node->next = NULL;
  if (linked_list->head == NULL) {
    linked_list->head = new_node;
    linked_list->tail = new_node;
    linked_list->size++;
  } else if (linked_list->size == 1) {
    linked_list->tail = new_node;
    linked_list->head->next = new_node;
    linked_list->size++;
  } else {
    linked_list->tail->next = new_node;
    linked_list->tail = new_node;
    linked_list->size++;
  }
}

void ll_pop(Linked_List *linked_list) {
  if (linked_list->head == NULL) {
    return;
  }
  Node *current_node = linked_list->head;
  while (current_node->next != linked_list->tail) {
    current_node = current_node->next;
  }
  free(linked_list->tail);
  current_node->next = NULL;
  linked_list->tail = current_node;
  linked_list->size--;
}

void ll_insert_at(Linked_List *linked_list, int index, int value) {
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

void ll_erase_at(Linked_List *linked_list, int index) {
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

void ll_remove_first_node_with_value(Linked_List *linked_list, int value) {
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

void ll_destroy(Linked_List *linked_list) {
  Node *current_node = linked_list->head;
  Node *next_node = NULL;
  while (current_node != NULL) {
    next_node = current_node->next;
    free(current_node);
    current_node = next_node;
  }
  free(linked_list);
}

void ll_print(Linked_List *linked_list) {
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

void test_linked_list(Linked_List *linked_list);

int main(int argc, char *argv[]) {
  Linked_List *linked_list = ll_create();
  test_linked_list(linked_list);
  return EXIT_SUCCESS;
}

void test_linked_list(Linked_List *linked_list) {
  ll_push(linked_list, 5);
  ll_print(linked_list);
  ll_insert_at(linked_list, 1, 9);
  ll_print(linked_list);
  ll_erase_at(linked_list, 1);
  ll_print(linked_list);
  ll_push(linked_list, 42);
  ll_print(linked_list);
  ll_destroy(linked_list);
}
