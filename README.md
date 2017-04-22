# Insertion and Selection Sort in C
This is a C program that implements both Insertion Sort and Selection Sort algorithms. Both algorithms perform sorts on doubly linked lists containing randomly generated positive integers. The program behavior is defined by removing or popping a list node from a first list of integers and adding it to the tail of a second list. Before a list node is popped its contents will be printed to the screen. Once the new list node is added to the second list the program will call either Selection Sort or Insertion Sort on the second list. Next, the program will print the newly sorted contents of the list to the screen to demonstrate correctness. Lastly, these steps will repeat until all the list nodes from the first list are added to the second list.

## Build
```c
make all
```

## Usage
```c
/bin$ ./sort
```

## Example Output
```c
Selection Sort
------------------------------------------------------------
Unsorted List:
64, 60, 91, 28, 63, 22, 50, 93, 87, 36, 94, 16, 78, 87, 84

Step 1: Sorted List
64

Unsorted List:
60, 91, 28, 63, 22, 50, 93, 87, 36, 94, 16, 78, 87, 84

Step 2: Sorted List
60, 64

Unsorted List:
91, 28, 63, 22, 50, 93, 87, 36, 94, 16, 78, 87, 84

Step 3: Sorted List
60, 64, 91

...

Insertion Sort
------------------------------------------------------------
Unsorted List:
36, 68, 24, 63, 31, 83, 30, 68, 69, 12, 37, 73, 27, 41, 27

Step 1: Sorted List
36

Unsorted List:
68, 24, 63, 31, 83, 30, 68, 69, 12, 37, 73, 27, 41, 27

Step 2: Sorted List
36, 68

Unsorted List:
24, 63, 31, 83, 30, 68, 69, 12, 37, 73, 27, 41, 27

Step 3: Sorted List
24, 36, 68

...
```

## Built With
* Red Hat Enterprise Linux release 2.6.32
* GNU Compiler Collection (GCC) release 4.4.7 
* GNU Make release 3.81

## Author
* **Jarid Bredemeier**