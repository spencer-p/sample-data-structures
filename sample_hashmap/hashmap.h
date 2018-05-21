typedef struct private_hashmap* hashmap;

// new_hashmap creates a new hashmap with the given capacity.
hashmap new_hashmap(int capacity);

// free_hashmap takes a pointer to a hashmap and frees it.
void free_hashmap(hashmap *hm);

// size returns the amount of items in the hashmap.
int size(hashmap hm);

// capacity returns the amount of items that can be stored in the hashmap.
int capacity(hashmap hm);

// insert sets the value for a given key in a hashmap. hm[key] = value.
void insert(hashmap hm, char *key, char *value);

// get returns the string value for a given key. hm[key].
char *get(hashmap hm, char *key);

// delete removes the value for a given key.
void delete(hashmap hm, char *key);

// hash computes the BSD checksum of the input string.
unsigned short hash(char *string);
