#ifndef ARRAY_H
#define ARRAY_H

typedef enum {
  INT,
  FLOAT,
  CHAR
} DataType;

typedef struct {
  void *data;
  int capacity;
  DataType type;
} MyArray;

MyArray *arr_create(int size, DataType type);
void arr_update(MyArray *arr, void *element, int index);
void *arr_get(MyArray *arr, int index);
void arr_destroy(MyArray *arr);

#endif
