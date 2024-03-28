#include "hash_table.h"
#include "misc/hash.h"
#include <stdio.h>
#include <stdlib.h>

HashTable *hash_table_create() {
  HashTable *hash_table = (HashTable *)malloc(sizeof(HashTable));
  hash_table->capacity = HASH_CAPACITY;
  hash_table->items = (HashTableItem **)calloc(HASH_CAPACITY, sizeof(HashTableItem *));
  return hash_table;
};

HashTableItem *hash_table_create_item(char *key, char *value) {
  HashTableItem *hash_item = (HashTableItem *)malloc(sizeof(HashTableItem));
  hash_item->key = key;
  hash_item->value = value;
  return hash_item;
};

void hash_table_add(HashTable *hash_table, char *key, char *value) {
  HashTableItem *hash_item = hash_table_create_item(key, value);
  int index = hash(key);
  if (hash_table->items[index] == NULL) {
    hash_table->items[index] = hash_item;
  } else {
    HashTableItem *current = hash_table->items[index];
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = hash_item;
  }
};

bool hash_table_exists(HashTable *hash_table, char *key) {
  for (int i = 0; i < HASH_CAPACITY; i++) {
    HashTableItem *current = hash_table->items[i];
    while (current != NULL) {
      if (current->key && strcmp(current->key, key) == 0) {
        return true;
      }
      current = current->next;
    }
  }
  return false;
};

char *hash_table_get(HashTable *hash_table, char *key) {
  int index = hash(key);
  HashTableItem *current = hash_table->items[index];
  while (current != NULL) {
    if (strcmp(current->key, key) == 0) {
      return current->value;
    } else {
      current = current->next;
    }
  }
  return "";
};

void hash_table_remove(HashTable *hash_table, char *key) {
  int index = hash(key);
  HashTableItem *current = hash_table->items[index];
  HashTableItem *previous = NULL;
  while (current) {
    if (strcmp(hash_table->items[index]->key, key) == 0) {
      if (previous == NULL) {
        hash_table->items[index] = current->next;
      } else {
        previous->next = current->next;
      }
      free(current->key);
      free(current->value);
      free(current);
    }
    previous = current;
    current = current->next;
  }
};

void hash_table_destroy(HashTable *hash_table) {
  for (int i = 0; i < HASH_CAPACITY; i++) {
    HashTableItem *current = hash_table->items[i];
    while (current != NULL) {
      HashTableItem *temp = current;
      current = current->next;
      if (temp->key)
        free(temp->key);
      if (temp->value)
        free(temp->value);
      free(temp);
    }
    hash_table->items[i] = NULL;
  }
  free(hash_table);
};

void test_hash_table(HashTable *hash_table);

int main(int argc, char *argv[]) {
  HashTable *hash_table = hash_table_create();
  test_hash_table(hash_table);
  return EXIT_SUCCESS;
}

void test_hash_table(HashTable *hash_table) {
  char *key1 = "hello";
  char *value1 = "world!";
  hash_table_add(hash_table, key1, value1);
  printf("value of the key \"hello\": %s\n", hash_table_get(hash_table, key1));
  hash_table_remove(hash_table, key1);
  printf("does \"hello\" exists?: %i\n", hash_table_exists(hash_table, key1));
  hash_table_destroy(hash_table);
}
