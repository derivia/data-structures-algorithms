#include <math.h>
#include <string.h>

int hash(char *string, int prime, int buckets) {
  long hash = 0;
  int len_string = strlen(string);
  // iterates on each char of the string
  // calculates the characters "contribution"
  //
  for (int i = 0; i < len_string; i++) {
    hash += (long)pow(prime, len_string - (i + 1)) * string[i];
    hash = hash % buckets;
  }
  return (int)hash;
}
