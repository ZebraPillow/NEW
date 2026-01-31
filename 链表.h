#ifndef TEST0130_H
#define TEST0130_H

typedef struct Node_t
{
	int data;
	struct Node_t *next;
}Link_node_t;

Link_node_t *create_link_list();
int is_empty(const Link_node_t *p);
int length_link_list(const Link_node_t *p);
int get_link_list(const Link_node_t *p, int pos, int *data);
int insert_link_list(Link_node_t *p, int pos, int x);
int delete_link_list(Link_node_t *p, int pos);
void print_list(const Link_node_t *p);
void clear_link_list(Link_node_t *p);
void free_link_list(Link_node_t *p);

#endif