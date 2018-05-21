# Sample Hash Map

or Hash Table, or Dictionary, etc.

This is an extremely simple hash table written in C. It is simplified to the
point that it has ~~bugs~~ features which you wouldn't normally want. Please do
not use this for any reason other than learning.

## Sample Questions

1. Execute `main.c` by hand, or run it if you like. What happens? Is what you
   expected?
1. Why do the key-value pairs not match with what we put in? Why does the
   printed size not match the number of unique pairs printed out?
1. Can there ever be more items in the hashmap than its capacity?
1. What happens if we try to put more in?
1. How can we fix this issue?
1. Usually the runtime of hashmap operations is described as O(1), but there's a
   loop in the `hash` function. Does this mean the runtime is actually more than
   O(1)? Why do we call it O(1)?
1. This sample uses an array internally to represent the data. What kinds of
   other data structures could be used to make a hashmap? Is there a "best"
   option?

## Notes for nerds

This hashmap is incapable of dealing with collisions. A simple solution would be
to store an array of linked lists, such that we expect each linked list to only
have one element, but in the event of a collision another node is appended. Each
node will also contain its string key (or the un-modulo'd hash) so that we can
differentiate between them.

I included a "hash testing" mode. If you pass any arguments to the program, it
will try to compute their hashes. For example, if you run
```bash
./main 16 Joe Carol Bill Susan
```
then you get the output
```
hash("Joe")%16 = 15
hash("Carol")%16 = 0
hash("Bill")%16 = 4
hash("Susan")%16 = 15
```
This comes in handy when trying to work out behaviour by hand.
