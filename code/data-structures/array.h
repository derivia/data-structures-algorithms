#ifndef ARRAY_H
#define ARRAY_H

typedef enum {
  INT,
  FLOAT,
  CHAR
} DataType;

typedef struct {
  void *data;
  int size;
  DataType type;
} myArray;

myArray *arr_create(int size, DataType type);
void arr_update(myArray *arr, void *element, int index);
void *arr_get(myArray *arr, int index);
void arr_del(myArray *arr, int index);
void arr_push(myArray *arr, DataType element);
void arr_pop(myArray *arr);

#endif
