#include "../hash_table.h"
#include <math.h>
#include <stdio.h>
#include <string.h>

#define PRIME 137

int hash(char *key) {
  int hash = 0;
  while (*key != '\0') {
    hash = ((hash * PRIME) + (*key++)) % HASH_CAPACITY;
  }
  printf("hash: %d\n", hash);
  return hash;
}
