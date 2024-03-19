#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

myArray *arr_create(int capacity, DataType type) {
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
    fprintf(stderr, "Invalid data type\n");
    exit(EXIT_FAILURE);
  }
  myArray *arr = malloc(sizeof(myArray));
  arr->data = malloc(capacity * type_size);
  arr->capacity = capacity;
  arr->type = type_size;
  return arr;
};

void arr_update(myArray *arr, void *element, int index) {
  void *update_location = arr->data + index * arr->type;
  memcpy(update_location, element, arr->type);
};

void *arr_get(myArray *arr, int index) {
  void *get_location = arr->data + index * arr->type;
  return get_location;
};

void arr_del(myArray *arr, int index) {
  // deleting on the end is different from deleting on other place, the elements
  // should be shifted to the left if the deletion isn't on the end
};

int main(int argc, char *argv[]) {
  // integer array test
  myArray *intArr = arr_create(8, INT);
  printf("capacity: %d\ntype size in bytes: %u\n", intArr->capacity, intArr->type);
  printf("address of intArr in memory: %p\n", intArr);
  for (int i = 0; i < intArr->capacity; i++) {
    int update_element = i + 1;
    arr_update(intArr, &update_element, i);
  }
  for (int i = 0; i < intArr->capacity; i++) {
    printf("%d\n", *((int *)arr_get(intArr, i)));
  }
  // char array test
  myArray *charArr = arr_create(8, CHAR);
  printf("capacity: %d\ntype size in bytes: %u\n", charArr->capacity, charArr->type);
  printf("address of charArr in memory: %p\n", charArr);
  for (int i = 0; i < charArr->capacity; i++) {
    int update_element = i + 97;
    arr_update(charArr, &update_element, i);
  }
  for (int i = 0; i < charArr->capacity; i++) {
    printf("%c\n", *((char *)arr_get(charArr, i)));
  }
  free(intArr->data);
  free(intArr);
  free(charArr->data);
  free(charArr);
  return EXIT_SUCCESS;
}
