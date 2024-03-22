#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
 * TODO: add error handling and deletion function
 */

MyArray *arr_create(int capacity, DataType type) {
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
  MyArray *arr = malloc(sizeof(MyArray));
  arr->data = calloc(capacity, type_size);
  arr->capacity = capacity;
  arr->type = type_size;
  return arr;
};

void arr_update(MyArray *arr, void *element, int index) {
  void *update_location = arr->data + index * arr->type;
  memcpy(update_location, element, arr->type);
};

void *arr_get(MyArray *arr, int index) {
  void *get_location = arr->data + index * arr->type;
  return get_location;
};

void arr_destroy(MyArray *arr) {
  free(arr->data);
  free(arr);
};

MyArray *int_arr_test();
MyArray *char_arr_test();

int main(int argc, char *argv[]) {
  // MyArray *int_arr = int_arr_test();
  MyArray *char_arr = char_arr_test();
  // arr_destroy(int_arr);
  arr_destroy(char_arr);
  return EXIT_SUCCESS;
}

MyArray *int_arr_test() {
  MyArray *int_arr = arr_create(8, INT);
  printf("capacity: %d\ntype size in bytes: %u\n", int_arr->capacity, int_arr->type);
  printf("address of int_arr in memory: %p\n", int_arr);
  for (int i = 0; i < int_arr->capacity; i++) {
    int update_element = i + 1;
    arr_update(int_arr, &update_element, i);
  }
  for (int i = 0; i < int_arr->capacity; i++) {
    printf("element address in memory and value: %p, %d\n", (void *)arr_get(int_arr, i), *((int *)arr_get(int_arr, i)));
  }
  return int_arr;
}

MyArray *char_arr_test() {
  MyArray *char_arr = arr_create(8, CHAR);
  printf("capacity: %d\ntype size in bytes: %u\n", char_arr->capacity, char_arr->type);
  printf("address of char_arr in memory: %p\n", char_arr);
  int ascii_lowercase_a = 97;
  for (int i = 0; i < char_arr->capacity; i++) {
    int update_element = i + ascii_lowercase_a;
    arr_update(char_arr, &update_element, i);
  }
  for (int i = 0; i < char_arr->capacity; i++) {
    printf("element address in memory and value: %p, %c\n", (void *)arr_get(char_arr, i), *((char *)arr_get(char_arr, i)));
  }
  return char_arr;
}
