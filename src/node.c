#include "node.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

struct node** node_new_array(int size)
{
    struct node **nodes = malloc(sizeof(struct node*) * size);
    assert(nodes != NULL);

    return nodes;
}

void node_free_array(struct node **nodes, int node_count)
{
    assert(nodes != NULL);

    for(int i = 0; i < node_count; i++)
    {
        free(nodes[i]);
    }

    free(nodes);
}

struct node* node_insert(struct node **nodes, int index, double x, double y, int id)
{
    assert(nodes != NULL);

    struct node *node = malloc(sizeof(struct node));
    node->x = x;
    node->y = y;
    node->id = id;

    nodes[index] = node;
    return node;
}

struct node* node_remove(struct node **nodes, int index, int *count)
{
    assert(nodes != NULL);
    struct node *ret_node = nodes[index];

    node_shift_nodes(nodes, index, *count);
    *count = *count - 1;

    return ret_node;
}

void node_shift_nodes(struct node **nodes, int index, int count)
{
    assert(nodes != NULL);

    for(int i = index; i < count - 1; i++)
    {
        nodes[i] = nodes[i + 1];
    }
}

struct node* node_find_by_id(struct node **nodes, int size, int id)
{
    assert(nodes != NULL);

    struct node *finder = NULL;

    for(int i = 0; i < size; i++)
    {
        if(nodes[i] == NULL)
        {
            break;
        }
        if(id == nodes[i]->id)
        {
            finder = NULL;
            break;
        }
    }

    return finder;
}
