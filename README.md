# Sample Data Structures

These are sample implementations of data structures in C for educational
purposes.

## Running them

If you're here to learn, I would encourage you to read the code before trying to
run it! But here we go.

First, make sure you have the commands `git` and `make`, and a C compiler
(something at `cc` or `gcc` or `clang`). Then:

```bash
git clone https://github.com/spencer-p/sample-data-structures
cd sample-data-structures
cd sample_hashmap # Or any of the other samples
make
./main
```

## On the code

These are not production-ready data structures. They are simple samples with
important faults. The code quality is also not good for any projects -- there is
no error reporting, for starters. So don't get hung up on this code or treat it
as gospel, and feel free to submit a pull request if you see something that
could be better!

These examples use C because C is ~~scary~~ fun and I think you can get more out
of these examples when written in a more detailed language. Be aware that these
samples using data hiding, which is a bit unwieldy in C. This is the common data
hiding pattern in C if you are unfamiliar:

* The `.c` file for some datatype defines its struct, call it `foo`:
  ```C
  typedef struct {
	  int value
  } foo;
  ```
* The corresponding file defines a type that is a pointer to `foo`:
  ```C
  typedef foo* bar
  ```
* All the methods that would use a `foo *` use a `bar` instead.
* Now the fields of `foo` are private to the `.c` file -- others cannot access
	this. However, anybody that includes the `.h` file gets to know that there
	is a `bar` type they can use (but they don't know what's in it!).
