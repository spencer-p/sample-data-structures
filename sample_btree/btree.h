typedef struct node* btree;

// Create a new tree
btree new_btree();

// Free a tree
void free_btree(btree *root);

// Insert a tree. Returns the tree's root. Similar to realloc, use like so:
// my_tree = insert(my_tree, 1, "my string");
btree insert(btree root, int key, char *value);

// Retrieve the value for a given key.
char *get(btree root, int key);
