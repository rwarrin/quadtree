# QUADTREE

## About

An implementation of a quadtree data structure in C.

## Using

Include the quadtree.h and node.h header files.

Compile with the quadtree and node object files or link statically with a library.

Use the quadtree_* functions to build and manage a quadtree.

## Example

```
$ bin/app
QUADTREE Level: 1, position: (0.00, 0.00) size: (15.00, 15.00)
    Contains 4 of 5 nodes.
    Node data: [0 (3.000000, 3.000000)], [1 (6.000000, 6.000000)], [2 (9.000000, 9.000000)], [3 (12.000000, 12.000000)], 
QUADTREE Level: 1, position: (15.00, 0.00) size: (15.00, 15.00)
    Contains 3 of 5 nodes.
    Node data: [16 (21.000000, 12.000000)], [17 (24.000000, 9.000000)], [18 (27.000000, 6.000000)], 
QUADTREE Level: 1, position: (0.00, 15.00) size: (15.00, 15.00)
    Contains 3 of 5 nodes.
    Node data: [11 (6.000000, 27.000000)], [12 (9.000000, 24.000000)], [13 (12.000000, 21.000000)], 
QUADTREE Level: 1, position: (15.00, 15.00) size: (15.00, 15.00)
    Contains 4 of 5 nodes.
    Node data: [5 (18.000000, 18.000000)], [6 (21.000000, 21.000000)], [7 (24.000000, 24.000000)], [8 (27.000000, 27.000000)], 
QUADTREE Level: 0, position: (0.00, 0.00) size: (30.00, 30.00)
    Contains 5 of 5 nodes.
    Node data: [4 (15.000000, 15.000000)], [9 (30.000000, 30.000000)], [10 (3.000000, 30.000000)], [14 (15.000000, 18.000000)], [15 (18.000000, 15.000000)], 
```

## Building

From the root directory type `make` to build.

