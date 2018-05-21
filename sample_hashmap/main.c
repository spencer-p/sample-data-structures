#include <stdio.h>
#include <stdlib.h>
#include "hashmap.h"

void print_key(hashmap hm, char *key) {
	printf("The value for %s is %s\n", key, get(hm, key));
}

int main(int argc, char **argv) {
	// Hashing tests
	if (argc > 1) {
		int cap = atoi(argv[1]);
		for (int i = 2; i < argc; i++) {
			printf("hash(\"%s\")%%%d = %d\n", argv[i], cap, hash(argv[i])%cap);
		}
		return 0;
	}

	hashmap dict = new_hashmap(16);

	// Add some values
	printf("Adding values...\n");
	insert(dict, "Joe", "Porter");
	insert(dict, "Carol", "Crown");
	insert(dict, "Bill", "Oakes");
	insert(dict, "Susan", "Stevenson");

	// Print those values
	print_key(dict, "Joe");
	print_key(dict, "Carol");
	print_key(dict, "Bill");
	print_key(dict, "Susan");

	// Remove a value
	printf("Removing Joe...\n");
	delete(dict, "Joe");

	// Print those values again
	print_key(dict, "Joe");
	print_key(dict, "Carol");
	print_key(dict, "Bill");
	print_key(dict, "Susan");

	free_hashmap(&dict);
}
