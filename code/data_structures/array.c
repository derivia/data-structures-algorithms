#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
 * TODO: add error handling and deletion function
 */

Array *array_create(int capacity, DataType type) {
  size_t type_size;
  switch (type) {
  case INT:
    type_size = sizeof(int);
    break;
  case FLOAT:
    type_size = sizeof(float);
    break;
  case CHAR:
    type_size = sizeof(char);
    break;
  default:
    fprintf(stderr, "invalid data type\n");
    exit(EXIT_FAILURE);
  }
  Array *arr = malloc(sizeof(Array));
  arr->data = calloc((size_t)capacity, type_size);
  arr->capacity = capacity;
  arr->type = type_size;
  return arr;
};

void array_update(Array *arr, void *element, int index) {
  void *update_location = arr->data + index * arr->type;
  memcpy(update_location, element, arr->type);
};

void *array_get(Array *arr, int index) {
  void *get_location = arr->data + index * arr->type;
  return get_location;
};

void array_destroy(Array *arr) {
  free(arr->data);
  free(arr);
};

Array *int_array_test();
Array *char_array_test();

int main(int argc, char *argv[]) {
  // Array *int_arr = int_array_test();
  Array *char_arr = char_array_test();
  // array_destroy(int_arr);
  array_destroy(char_arr);
  return EXIT_SUCCESS;
}

Array *int_array_test() {
  Array *int_arr = array_create(8, INT);
  printf("capacity: %d\ntype size in bytes: %u\n", int_arr->capacity, int_arr->type);
  printf("address of int_arr in memory: %p\n", int_arr);
  for (int i = 0; i < int_arr->capacity; i++) {
    int update_element = i + 1;
    array_update(int_arr, &update_element, i);
  }
  for (int i = 0; i < int_arr->capacity; i++) {
    printf("element address in memory and value: %p, %d\n", (void *)array_get(int_arr, i), *((int *)array_get(int_arr, i)));
  }
  return int_arr;
}

Array *char_array_test() {
  Array *char_arr = array_create(8, CHAR);
  printf("capacity: %d\ntype size in bytes: %u\n", char_arr->capacity, char_arr->type);
  printf("address of char_arr in memory: %p\n", char_arr);
  int ascii_lowercase_a = 97;
  for (int i = 0; i < char_arr->capacity; i++) {
    int update_element = i + ascii_lowercase_a;
    array_update(char_arr, &update_element, i);
  }
  for (int i = 0; i < char_arr->capacity; i++) {
    printf("element address in memory and value: %p, %c\n", (void *)array_get(char_arr, i), *((char *)array_get(char_arr, i)));
  }
  return char_arr;
}
