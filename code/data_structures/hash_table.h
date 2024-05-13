#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdbool.h>

/*
 * Hash tables/maps are maps/dictionaries that uses hash functions in the
 * indexes. They are basically associative arrays with key:value in each
 * element.
 */

#define HASH_CAPACITY 128

// ASCII only key:value
typedef struct HashTableItem {
    char *key;
    char *value;
    struct HashTableItem *next;
} HashTableItem;

typedef struct {
    int capacity;
    // a pointer to an array of pointers, it points to the beginning of a block of
    // memory so [] can be used in this like items[0] or items[i]
    HashTableItem **items;
} HashTable;

HashTable *hash_table_create();
HashTableItem *hash_table_create_item(char *key, char *value);
void hash_table_add(HashTable *hash_table, char *key, char *value);
bool hash_table_exists(HashTable *hash_table, char *key);
char *hash_table_get(HashTable *hash_table, char *key);
void hash_table_remove(HashTable *hash_table, char *key);
void hash_table_destroy(HashTable *hash_table);

#endif // !HASH_TABLE_H
