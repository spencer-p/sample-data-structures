# Sample Binary Search Tree

This is a simple, unbalanced binary search tree written in C. Note that `btree`
is used as an abbreviation for binary tree. Also, be aware that for this
example, a "binary tree" object is really just a pointer to a node in the tree!
A binary tree's child nodes are also binary trees, and the root is just the
special case of a node with no parent.

## Questions to consider

1. Looking at the functions `insert`, `get`, and `free_btree`, what can we say
   about the role of recursion in dealing with binary trees? How do these
   methods take advantage of recursion?
1. Why does `new_btree` return `NULL`? Why does `insert` return the root after
   it's done? Hint: These two are related.
1. Try executing `main.c` by hand. What does the tree look like after each set
   of insertions? Does the order of insertion matter? What happens when we
   insert two (key, value) pairs that both have the key 5?
1. Going forward -- how do we avoid creating a binary tree that looks more like
   a linked list?

## More technical questions

1. Explain the use of pointers in `free_btree`.

## Notes for nerds

You may notice that I didn't implement a `delete` function. I deliberately
didn't write it because it's more complex than the insert operation and is
difficult to quickly grasp.

Why did I have `insert` return the root? I really wanted the `new_btree`
function to _not_ need to start with a key-value pair and still be able to
insert to any `btree` object. One nice solution is to adopt the `realloc` way of
doing things, so that we can mess with the pointer if we want:
```
tree = insert(tree, 1, "foo");
```
Then the insert method is free to change the pointer, and even accepts `NULL`,
which is convenient in many situations (imagine you have an array of binary
trees, all set to NULL, and you want to insert some values -- it's much easier
to just do it than check if they're NULL and make a new tree first). 
