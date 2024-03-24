#ifndef HASH_TABLE_H
#define HASH_TABLE_H

/*
 * Hash tables/maps are maps/dictionaries that uses hash functions in the
 * indexes. They are basically associative arrays with key:value in each
 * element. Duplicate keys in hash tables are not permitted.
 */

// ASCII only key:value
typedef struct {
  char *key;
  char *value;
} HashTableItem;

typedef struct {
  int capacity;
  int size;
  // a pointer to an array of pointers, it points to the beginning of a block of memory
  // so [] can be used in this like items[0] or items[i]
  HashTableItem **items;
} HashTable;

HashTable *hash_table_create(); 
HashTableItem *hash_table_item_create(char *key, char *value); 
void hash_table_item_destroy(HashTableItem *item);
void hash_table_destroy(HashTable *hash_table);

#endif // !HASH_TABLE_H
