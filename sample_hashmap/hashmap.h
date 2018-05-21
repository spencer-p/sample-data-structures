typedef struct private_hashmap* hashmap;

hashmap new_hashmap(int capacity);
void free_hashmap(hashmap *hm);
void insert(hashmap hm, char *key, char *value);
char *get(hashmap hm, char *key);
void delete(hashmap hm, char *key);
unsigned short hash(char *string);
