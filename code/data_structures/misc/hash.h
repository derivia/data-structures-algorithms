#include "../hash_table.h"
#include <math.h>
#include <string.h>

#define PRIME 137

int hash(char *key) {
  long hash = 0;
  int len_string = strlen(key);
  // iterates on each char of the string
  // calculates the characters "contribution"
  for (int i = 0; i < len_string; i++) {
    hash += (long)pow(PRIME, len_string - (i + 1)) * key[i];
    hash = hash % HASH_CAPACITY; // makes the hash fit on the buckets size
  }
  return (int)hash;
}
