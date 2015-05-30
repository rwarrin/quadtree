#include "quadtree.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

static bool quadtree_node_is_within_quadtree(struct quadtree *quadtree, double x, double y);
static void quadtree_distribute_nodes_to_children(struct quadtree *quadtree);
static void quadtree_split(struct quadtree *quadtree);

struct quadtree* quadtree_create(double x, double y, double width, double height, int level)
{
    struct quadtree *tree = malloc(sizeof(struct quadtree));
    assert(tree != NULL);

    tree->x = x;
    tree->y = y;
    tree->width = width;
    tree->height = height;
    tree->level = level;

    tree->nodes = node_new_array(MAX_NODES);
    tree->node_count = 0;

    tree->children = NULL;

    return tree;
}

void quadtree_delete(struct quadtree *quadtree)
{
    if(quadtree == NULL)
    {
        return;
    }

    if(quadtree->children != NULL)
    {
        for(int quadrant = 0; quadrant < NUM_QUADRANTS; quadrant++)
        {
            quadtree_delete(quadtree->children[quadrant]);
        }
        free(quadtree->children);
    }

    node_free_array(quadtree->nodes, quadtree->node_count);

    free(quadtree);
}

struct quadtree* quadtree_insert(struct quadtree *quadtree, double x, double y, int id)
{
    if(quadtree->children != NULL)
    {
        for(int quadrant = 0; quadrant < NUM_QUADRANTS; quadrant++)
        {
            if(quadtree_node_is_within_quadtree(quadtree->children[quadrant], x, y))
            {
                return quadtree_insert(quadtree->children[quadrant], x, y, id);
            }
        }
        if(quadtree->node_count < MAX_NODES)
        {
            node_insert(quadtree->nodes, quadtree->node_count, x, y, id);
            quadtree->node_count++;
            return quadtree;
        }

        return NULL;
    }
    else if(quadtree->children == NULL)
    {
        if(quadtree->node_count < MAX_NODES)
        {
            node_insert(quadtree->nodes, quadtree->node_count, x, y, id);
            quadtree->node_count++;
            return quadtree;
        }
        else
        {
            quadtree_split(quadtree);
            return quadtree_insert(quadtree, x, y, id);
        }
    }

    return NULL;
}

void quadtree_print(struct quadtree *quadtree)
{
    if(quadtree == NULL)
    {
        return;
    }

    if(quadtree->children != NULL)
    {
        for(int quadrant = 0; quadrant < NUM_QUADRANTS; quadrant++)
        {
            quadtree_print(quadtree->children[quadrant]);
        }
    }

    printf("QUADTREE Level: %d, position: (%0.2f, %0.2f) size: (%0.2f, %0.2f)\n",
            quadtree->level, quadtree->x, quadtree->y, quadtree->width, quadtree->height);
    printf("\tContains %d of %d nodes.\n", quadtree->node_count, MAX_NODES);
    printf("\tNode data: ");
    node_print(quadtree->nodes, quadtree->node_count);
    printf("\n");
}

static bool quadtree_node_is_within_quadtree(struct quadtree *quadtree, double x, double y)
{
    if( (quadtree->x < x) && ((quadtree->x + quadtree->width) > x) )
    {
        if( (quadtree->y < y) && ((quadtree->y + quadtree->height) > y) )
        {
            return true;
        }
    }

    return false;
}

static void quadtree_distribute_nodes_to_children(struct quadtree *quadtree)
{
    assert(quadtree != NULL);

    for(int i = 0; i < quadtree->node_count; i++)
    {
        for(int quadrant = 0; quadrant < NUM_QUADRANTS; quadrant++)
        {
            if(quadtree_node_is_within_quadtree(quadtree->children[quadrant], quadtree->nodes[i]->x, quadtree->nodes[i]->y))
            {
                struct node *node = node_remove(quadtree->nodes, i, &quadtree->node_count);
                quadtree_insert(quadtree->children[quadrant], node->x, node->y, node->id);
                free(node);
                i--;
                break;
            }
        }
    }
}

static void quadtree_split(struct quadtree *quadtree)
{
    assert(quadtree != NULL);

    double half_width = quadtree->width / 2.0;
    double half_height = quadtree->height / 2.0;
    double x_mid = quadtree->x + half_width;
    double y_mid = quadtree->y + half_width;
    int next_level = quadtree->level + 1;

    quadtree->children = malloc(sizeof(struct quadtree*) * NUM_QUADRANTS);
    assert(quadtree->children != NULL);

    quadtree->children[TOPLEFT] = quadtree_create(quadtree->x, quadtree->y, half_width, half_height, next_level);
    quadtree->children[TOPRIGHT] = quadtree_create(x_mid, quadtree->y, half_width, half_height, next_level);
    quadtree->children[BOTTOMLEFT] = quadtree_create(quadtree->x, y_mid, half_width, half_height, next_level);
    quadtree->children[BOTTOMRIGHT] = quadtree_create(x_mid, y_mid, half_width, half_height, next_level);

    quadtree_distribute_nodes_to_children(quadtree);
}

