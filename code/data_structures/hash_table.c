#include "hash_table.h"
#include "../misc/hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

HashTable *hash_table_create() {
  HashTable *hash_table = malloc(sizeof(HashTable));
  hash_table->capacity = 32;
  hash_table->size = 0;
  // calloc used to allocate memory for 32 HashTableItem's
  hash_table->items = calloc((size_t)hash_table->capacity, sizeof(HashTableItem *));
  return hash_table;
}

HashTableItem *hash_table_item_create(char *key, char *value) {
  HashTableItem *item = malloc(sizeof(HashTableItem));
  // strdup returns an identical malloc'd string
  item->key = strdup(key);
  item->value = strdup(value);
  return item;
}

void hash_table_item_destroy(HashTableItem *item) {
  free(item->key);
  free(item->value);
  free(item);
};

void hash_table_destroy(HashTable *hash_table) {
  for (int i = 0; i < hash_table->capacity; i++) {
    HashTableItem *temp = hash_table->items[i];
    if (temp != NULL) {
      hash_table_item_destroy(temp);
    }
  }
  free(hash_table->items);
  free(hash_table);
};

int main(int argc, char *argv[]) {
  const int prime = 157;
  int result_one = hash("foo", prime, 32);
  int result_two = hash("bar", prime, 32);
  printf("hash test results: %d & %d\n", result_one, result_two);
  return EXIT_SUCCESS;
}
