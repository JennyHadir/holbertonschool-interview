# 0x0E. Linear search in skip list

## Requirements
### General

* Allowed editors: vi, vim, emacs
* All your files will be compiled on Ubuntu 14.04 LTS
* Your programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
* All your files should end with a new line
* Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
* You are not allowed to use global variables
* No more than 5 functions per file
* In the following examples, the main.c files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own main.c files at compilation. Our main.c files might be different from the one shown in the examples
* The prototypes of all your functions should be included in your header file called search.h
* Don’t forget to push your header file
* All your header files should be include guarded

## Tasks
0. [Linear search in a skip list]() : Looking for a specific value in a singly linked list always leads to browse every element of the list. A common way to optimize the time complexity of a search in a singly linked list is to modify the list itself by adding an “express lane” to browse it. A linked list with an express lane is called a skip list.

Write a function that searches for a value in a sorted skip list of integers.

  * Prototype : skiplist_t *linear_skip(skiplist_t *list, int value);
  * Where list is a pointer to the head of the skip list to search in
  * A node of the express lane is placed every index which is a multiple of the square root of the size of the list (see example below)
  * And value is the value to search for
  * You can assume that list will be sorted in ascending order
  * Your function must return a pointer on the first node where value is located
  * If value is not present in list or if head is NULL, your function must return NULL
  * Every time you compare a value in the list to the value you are searching, you have to print this value (see example below)
