#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

void print_key(btree t, int key) {
	printf("The value for %d is %s\n", key, get(t, key));
}

int main() {
	btree tree = new_btree();

	// Add some values
	printf("Adding values...\n");
	tree = insert(tree, 8, "Rachel Carson");
	tree = insert(tree, 5, "Porter");
	tree = insert(tree, 9, "Oprah College");
	tree = insert(tree, 10, "College Ten");
	tree = insert(tree, 1, "Cowell");
	tree = insert(tree, 5, "Whoops!");

	// Print those values
	print_key(tree, 1);
	print_key(tree, 5);
	print_key(tree, 8);
	print_key(tree, 9);
	print_key(tree, 10);

	// Get rid of that tree
	free_btree(&tree);

	// Do it again
	tree = new_btree();

	// Add some values
	printf("Adding values...\n");
	tree = insert(tree, 10, "College Ten");
	tree = insert(tree, 9, "Oprah College");
	tree = insert(tree, 8, "Rachel Carson");
	tree = insert(tree, 1, "Cowell");
	tree = insert(tree, 5, "Whoops!");
	tree = insert(tree, 5, "Porter");

	// Print those values
	print_key(tree, 1);
	print_key(tree, 5);
	print_key(tree, 8);
	print_key(tree, 9);
	print_key(tree, 10);

	// Free tree
	free_btree(&tree);
}
