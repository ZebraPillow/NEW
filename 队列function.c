#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Queue_t *create_empty_queue(int len)
{
	Queue_t *queue = (Queue_t*)malloc(sizeof(Queue_t));
	queue->data = (int*)malloc(len*sizeof(int));
	queue->max_len = len;
	queue->front = 0;
	queue->rear = 0;
	return queue;
}

int is_empty_queue(const Queue_t *p)
{
	return p->front == p->rear;
}

int is_full_queue(const Queue_t *p)
{
	return (p->rear+1)%p->max_len == p->front;
}

void push_queue(Queue_t *p, int x)
{
	if( is_full_queue(p) )
		return ;
	p->data[p->rear] = x;
	p->rear = (p->rear+1)%p->max_len;
}

void pop_queue(Queue_t *p)
{
	if( is_empty_queue(p) )
		return ;
	p->front = (p->front+1)%p->max_len;
}

int top_queue(const Queue_t *p)
{
	return p->data[p->front];
}

int size_queue(const Queue_t *p)
{
	return (p->max_len + p->rear - p->front)%p->max_len;
}