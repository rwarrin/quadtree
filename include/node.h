#ifndef NODE_H
#define NODE_H

struct node
{
    double x;
    double y;
    int id;
};

struct node** node_new_array(int size);
void node_free_array(struct node **nodes, int node_count);
struct node* node_insert(struct node **nodes, int index, double x, double y, int id);
struct node* node_remove(struct node **nodes, int index, int *count);
void node_shift_nodes(struct node **nodes, int index, int count);
struct node* node_find_by_id(struct node **nodes, int size, int id);
void node_print(struct node **nodes, int count);

#endif  // NODE_H
