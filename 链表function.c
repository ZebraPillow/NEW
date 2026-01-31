#include <stdio.h>
#include <stdlib.h>
#include "test0130.h"

Link_node_t *create_link_list()
{
	Link_node_t *p = (Link_node_t*)malloc(sizeof(Link_node_t));
	p->next = NULL;
	return p;
}

void print_list(const Link_node_t *p)
{
	Link_node_t *node = p->next;
	int i = 0;
	while( node!=NULL )
	{
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
}

int is_empty(const Link_node_t *p)
{
	if( p->next==NULL )
		return 1;
	return 0;
}

int length_link_list(const Link_node_t *p)
{
	Link_node_t *node = p->next;
	int length = 0;
	while( node!=NULL )
	{
		node = node->next;
		length++;
	}
	return length;
}

int get_link_list(const Link_node_t *p, int pos, int *data)
{
	Link_node_t *node = p->next;
	int i = 0;
	while( node!=NULL )
	{
		if( i++==pos )
		{
			*data = node->data;
			return 1;
		}
		node = node->next;
	}
	return 0;
}

int insert_link_list(Link_node_t *p, int pos, int x)
{
	Link_node_t *node = p;
	int i = 0;
	while( node!=NULL )
	{
		if( i++ == pos )
		{
			Link_node_t *new_node = (Link_node_t*)malloc(sizeof(Link_node_t));
			new_node->data = x;
			new_node->next = node->next;
			node->next = new_node;
			return 1;
		}
		node = node->next;
	}
	return 0;
}

int delete_link_list(Link_node_t *p, int pos)
{
	Link_node_t *node = p;
	int i = 0;
	while( node->next!=NULL )
	{
		if( i++ == pos )
		{
			Link_node_t *t = node->next;
			node->next = node->next->next;
			free(t);
			return 1;
		}
		node = node->next;
	}
	return 0;
}

void clear_link_list(Link_node_t *p)
{
	Link_node_t *node = p->next;
	p->next = NULL;
	while( node!=NULL )
	{
		Link_node_t *node1 = node;
		node = node->next;
		free(node1);
	}
}

void free_link_list(Link_node_t *p)
{
	Link_node_t *node = p;
	while( node!=NULL )
	{
		Link_node_t *node1 = node;
		node = node->next;
		free(node1);
	}
}