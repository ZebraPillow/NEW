#include <stdio.h>
#include "test0129.h"


List_t create_empty_list()
{
//	List_t *p = (List_t*)malloc(size*sizeof(List_t))
	List_t p = {{0}, 0};
	return p;
}

int is_full(const List_t *p)
{
	// 返回运算结果
	return p->size == MAX_DATA_SIZE;
}

int is_empty(const List_t *p)
{
	return p->size == 0;
}

void clear_list(List_t *p)
{
	p->size = 0;
}

void print_list(const List_t *p)
{
	int i;
	for( i=0; i < p->size; i++)
		printf("%d ", p->data[i]);
	printf("\n");
}

int	list_size(const List_t *p)
{
	return p->size;
}

int insert_list(List_t *p, int pos, int x)
{
	if( is_full(p) || pos<0 || pos > p->size )
		return 0;
	int i;
	for( i = p->size; i>pos; i-- )
		p->data[i] = p->data[i-1];
	p->data[pos] = x;
	p->size++;
	return 1;
}

int delete_list(List_t *p, int pos)
{
	if( is_empty(p) || pos<0 || pos > p->size )
		return 0;
	int i;
	for( i = pos; i < p->size; i++ )
		p->data[i] = p->data[i+1];
	p->size--;
	return 1;
}