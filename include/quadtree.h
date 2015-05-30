#ifndef QUADTREE_H
#define QUADTREE_H

#include "node.h"

#define MAX_NODES 5

typedef enum
{
    TOPLEFT = 0,
    TOPRIGHT,
    BOTTOMLEFT,
    BOTTOMRIGHT,
    NUM_QUADRANTS
} QUADRANT;

struct quadtree
{
    double x;
    double y;
    double width;
    double height;
    int level;

    int node_count;
    struct node **nodes;
    struct quadtree **children;
};

struct quadtree* quadtree_create(double x, double y, double width, double height, int level);
struct quadtree* quadtree_insert(struct quadtree *quadtree, double x, double y, int id);
void quadtree_delete(struct quadtree *quadtree);
void quadtree_print(struct quadtree *quadtree);

#endif  // QUADTREE_H
