#include "array.h"
#include <stdio.h>
#include <stdlib.h>

myArray *arr_create(int size, DataType type) {
  // should allocate memory for the array based on size * type
  // and i don't know how to return it properly
};

void arr_update(myArray *arr, int element, int index) {

};

void *arr_get(myArray *arr, int index) {

};

void arr_del(myArray *arr, int index) {
  // deleting on the end is different from deleting on other place, the elements
  // should be shifted to the left if the deletion isn't on the end
};

int main(int argc, char *argv[]) {
  char test[20];
  int testSize = sizeof(test) / sizeof(test[0]);
  for (int i = 0; i < testSize; i++) {
    test[i] = 'a' + i;
    printf("%c\t%p\n", test[i], (void *)&test[i]);
  }
  return EXIT_SUCCESS;
}
