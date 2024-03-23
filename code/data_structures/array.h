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
} Array;

Array *array_create(int size, DataType type);
void array_update(Array *arr, void *element, int index);
void *array_get(Array *arr, int index);
void array_destroy(Array *arr);

#endif
