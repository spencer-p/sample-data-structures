#include <stdlib.h>
#include <stdbool.h>

#include "btree.h"

typedef struct node {
	int key;            // The key of this node
	char *value;        // The value this node contains
	struct node *left;  // The node to the left (less than)
	struct node *right; // The node to the right (greater than)
} node;

btree new_btree() {
	// insert is fine with NULL being passed, so this is our initial value
	return NULL;
}

node *new_node() {
	// Note that calloc will set the pointers to NULL.
	return calloc(1, sizeof(node));
}

void free_btree(btree *root) {
	if (*root == NULL) {
		return;
	}

	free_btree(&(*root)->left);
	free_btree(&(*root)->right);
	free(*root);
	*root = NULL;
}

btree insert(btree root, int key, char *value) {
	// If there is no tree here, make one!
	if (root == NULL) {
		root = new_node();
		root->key = key;
		root->value = value;
		return root;
	}

	// Otherwise we have to find which side to put the value in
	// Choose a "destination" (pointer to the left or right pointer)
	node **dest;
	if (key <= root->key) {
		dest = &root->left;
	} else {
		dest = &root->right;
	}

	// Insert recursively
	*dest = insert(*dest, key, value);

	// Root didn't change - return it
	return root;
}

char *get(btree root, int key) {
	if (root == NULL) {
		return NULL; // Key not found
	}

	if (key == root->key) {
		return root->value;
	} else if (key < root->key) {
		return get(root->left, key);
	} else /* key > root-> key */ {
		return get(root->right, key);
	}
}
