#include <stdlib.h>
#include <string.h>

#include "hashmap.h"

typedef struct private_hashmap {
	char **array; // Internal data structure to hold (k,v) pairs
	int cap;      // Capacity that this hashmap can hold
	int size;     // The number of elements it currently holds
} private_hashmap;

hashmap new_hashmap(int capacity) {
	hashmap new;

	// Create the hashmap struct
	new = malloc(sizeof(private_hashmap));
	if (new == NULL) {
		return NULL;
	}

	// Create the internal array
	new->array = calloc(capacity, sizeof(char*));
	if (new->array == NULL) {
		free(new);
		return NULL;
	}

	// Initialize size and count
	new->cap = capacity;
	new->size = 0;

	return new;
}

void free_hashmap(hashmap *hm_p) {
	free((*hm_p)->array);
	free(*hm_p);
	*hm_p = NULL;
}

int size(hashmap hm) {
	if (hm == NULL) return 0;
	return hm->size;
}

int capacity(hashmap hm) {
	if (hm == NULL) return 0;
	return hm->cap;
}

void insert(hashmap hm, char *key, char *value) {
	if (hm == NULL) return;
	hm->array[hash(key)%hm->cap] = value;
	hm->size++;
}

char *get(hashmap hm, char *key) {
	if (hm == NULL) return NULL;
	return hm->array[hash(key)%hm->cap];
}

void delete(hashmap hm, char *key) {
	if (hm == NULL) return;
	hm->array[hash(key)%hm->cap] = NULL;
	hm->size--;
}

unsigned short hash(char *string) {
	int len = strlen(string);
	unsigned short hash = 0;
	for (int i = 0; i < len; i++) {
		hash = (hash >> 1) + ((hash & 1) << 15); // Magic
		hash += string[i]; // Add data/entropy from string
		hash &= 0xffff; // Keep it within range of an unsigned short (16 bits)
	}
	return hash;
}
