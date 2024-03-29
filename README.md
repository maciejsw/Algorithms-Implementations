# Algorithms-Implementations
Collection of simple algorithms and data structures I've implemented on laboratory classes.
## List of projects and their properties:
### Hashtables
Count the number of occurences of each word in the text given in the input. Store these numbers in a hash table: the word should be interpreted as a key (type string), and the number of occurences as a value (type int). Use the method of collision resolving suggested by the teacher.
You can use an array of fixed, constant size, but allocate it dynamically! The maximum number of elements in a test is 100000. Choose the appropriate size of the array.

Input:

The text (any number of words with only lower case letters, separated by spaces or new line characters). The words starting with character '?' and '-' should be interpreted as commands:
- '?': print the number of occurences of the given word on the screen,
- '-': remove the information about the given word from your hash table (from this point you should start counting the occurences of this word from 0),
- 'q': exit.
### BST
Implement a binary search tree (BST). Each element of a tree should have a key (unsigned integer).
Your program should support the following operations:
- \+ - add a new element with a given key to the tree,
- \- - remove an element with a given key from the tree (ignore this operation if there is no such an element in the tree),
- ? - search the tree for an element with a given key, write '1' if the element was found, or '0' if not,
- m - write the key of the minimum element in the tree,
- M - write the key of the maximum element in the tree,
- q - quit the program.
### Heap
Implement a max/min heap and the following operations:
- \+ v (add a number v to the heap)
- \- (remove the maximum from the max heap (minimum from the min heap respectively) and write it on the screen)
- p (write all elements of the heap in the order in which they are stored in an array)
- r n v1 ...vn (remove all elements from the heap and create a heap out of n new elements, of the values given by v1 ...vn)
- s (change the orientation of the heap – from max to min or from min to max; s operation can be requested multiple times)
- q (exit the program)

Additional remarks:
- Operation 'r' is not the same as a sequence of '+' operations.
- If both children are equal the child of the lesser index is swapped.
### Quick-sort
Sort a given set of large integers (with arbitrarily large number of digits).

Input:
- In the first line: the number of elements of the input set (N).
- In the next N lines: the numbers to sort.
### Stack
Implement a LIFO stack, using a linked list implementation. Every element of the list should contain a key of type int (signed integer), and some pointers that are required by your stack implementation.
Your program should support the following operations:
- i - insert (push) a new element to your stack,
- d - delete (pop) an element from your stack and print its key on the screen (if underflow occurs, the '!' character should be printed),
- g - get an element of the list from given position and print its key on the screen (if the given index is greater or equal the size of your list, you should print the '?' character),
- q - quit the program.

The element at the bottom of the stack should be interpreted as an element on position 0, the second element is on position 1, etc. The top element of the stack is at index size-1.
