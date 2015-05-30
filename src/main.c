#include "quadtree.h"
#include "node.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    struct node **nodes = node_new_array(10);
    int node_count = 0;

    node_insert(nodes, 0, 0, 0, 0);
    node_insert(nodes, 1, 1, 1, 1);
    node_insert(nodes, 2, 2, 2, 2);
    node_insert(nodes, 3, 3, 3, 3);
    node_insert(nodes, 4, 4, 4, 4);
    node_insert(nodes, 5, 5, 5, 5);
    node_count = 6;

    node_print(nodes, node_count);
    printf("\n");
    printf("%s %d\n", (node_find_by_id(nodes, node_count, 3) != NULL ? "Found" : "Not Found"), 3);

    free(node_remove(nodes, 3, &node_count));
    node_print(nodes, node_count);
    printf("\n");
    printf("%s %d\n", (node_find_by_id(nodes, node_count, 3) != NULL ? "Found" : "Not Found"), 3);

    node_free_array(nodes, node_count);

    struct quadtree *qt = quadtree_create(0, 0, 30, 30, 0);
    quadtree_insert(qt, 3, 3, 0);
    quadtree_insert(qt, 6, 6, 1);
    quadtree_insert(qt, 9, 9, 2);
    quadtree_insert(qt, 12, 12, 3);
    quadtree_insert(qt, 15, 15, 4);
    quadtree_insert(qt, 18, 18, 5);
    quadtree_insert(qt, 21, 21, 6);
    quadtree_insert(qt, 24, 24, 7);
    quadtree_insert(qt, 27, 27, 8);
    quadtree_insert(qt, 30, 30, 9);
    quadtree_print(qt);
    quadtree_delete(qt);

    return 0;
}
