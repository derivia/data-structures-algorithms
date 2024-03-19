#include "array.h"
#include <stdio.h>
#include <stdlib.h>

myArray *arr_create(int capacity, DataType type) {
  switch (type) {
  case INT:
    type = sizeof(int);
    break;
  case FLOAT:
    type = sizeof(float);
    break;
  case CHAR:
    type = sizeof(char);
    break;
  default:
    fprintf(stderr, "Invalid data type\n");
    exit(EXIT_FAILURE);
  }
  myArray *arr = malloc(sizeof(myArray));
  arr->capacity = capacity;
  arr->type = type;
  return arr;
};

void arr_update(myArray *arr, void *element, int index) {

};

void *arr_get(myArray *arr, int index) {};

void arr_del(myArray *arr, int index) {
  // deleting on the end is different from deleting on other place, the elements
  // should be shifted to the left if the deletion isn't on the end
};

int main(int argc, char *argv[]) {
  myArray *arr = arr_create(8, INT);
  printf("capacity: %d\ntype size in bytes: %u\n", arr->capacity, arr->type);
  return EXIT_SUCCESS;
}
