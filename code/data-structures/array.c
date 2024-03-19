#include "array.h"
#include <stdio.h>
#include <stdlib.h>

myArray *arr_create(int size, DataType type) {
  switch (type) {
  case INT:
    size = sizeof(int);
    break;
  case FLOAT:
    size = sizeof(float);
    break;
  case CHAR:
    size = sizeof(char);
    break;
  default:
    fprintf(stderr, "Invalid data type\n");
    exit(EXIT_FAILURE);
  }
  void *data = malloc(size * sizeof(DataType));
  myArray *arr = malloc(sizeof(myArray));
  arr->data = data;
  arr->size = size;
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
  printf("%d, %d, %s", arr->data, arr->size, arr->type);
  return EXIT_SUCCESS;
}
