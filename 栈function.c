#include <stdio.h>
#include <stdlib.h>
#include "test0131.h"

Stack_t *create_empty_stack(int len)
{
	Stack_t *stack = (Stack_t*)malloc(sizeof(Stack_t));// 栈的结构体对象
	stack->data = (int*)malloc(sizeof(int)*len);// 动态创建顺序存储结构
	stack->max_len = len;// 数组大小
	stack->top = 0;// 栈针
	return stack;
}

void clear_stack(Stack_t *p)
{
	p->top = 0;
}

void del_stack(Stack_t *p)
{
	free(p->data);
	free(p);
}

int is_empty_stack(const Stack_t *p)
{
	return p->top == 0;
}

int is_full_stack(const Stack_t *p)
{
	return p->top == p->max_len;
}

void push_stack(Stack_t *p, int x)
{
	if( is_full_stack(p) )
		return ;
	p->data[p->top++] = x;
}

void pop_stack(Stack_t *p)
{
	if( is_empty_stack(p) )
		return ;
	p->top--;
}

int top_stack(const Stack_t *p)
{
	return p->data[p->top-1];
}