#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
 * TODO: add error handling and deletion function
 */

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
  arr->data = calloc(capacity, type_size);
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

void arr_destroy(myArray *arr) {
  free(arr->data);
  free(arr);
};

myArray *intArrTest();
myArray *charArrTest();

int main(int argc, char *argv[]) {
  myArray *intArr = intArrTest();
  // myArray *charArr = charArrTest();
  arr_destroy(intArr);
  // free(charArr->data);
  // free(charArr);
  return EXIT_SUCCESS;
}

myArray *intArrTest() {
  myArray *intArr = arr_create(8, INT);
  printf("capacity: %d\ntype size in bytes: %u\n", intArr->capacity, intArr->type);
  printf("address of intArr in memory: %p\n", intArr);
  for (int i = 0; i < intArr->capacity; i++) {
    int update_element = i + 1;
    arr_update(intArr, &update_element, i);
  }
  for (int i = 0; i < intArr->capacity; i++) {
    printf("element address in memory and value: %p, %d\n", (void *)arr_get(intArr, i), *((int *)arr_get(intArr, i)));
  }
  return intArr;
}

myArray *charArrTest() {
  myArray *charArr = arr_create(8, CHAR);
  printf("capacity: %d\ntype size in bytes: %u\n", charArr->capacity, charArr->type);
  printf("address of charArr in memory: %p\n", charArr);
  int ascii_lowercase_a = 97;
  for (int i = 0; i < charArr->capacity; i++) {
    int update_element = i + ascii_lowercase_a;
    arr_update(charArr, &update_element, i);
  }
  for (int i = 0; i < charArr->capacity; i++) {
    printf("%c\n", *((char *)arr_get(charArr, i)));
  }
  return charArr;
}
