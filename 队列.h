#ifndef QUEUE_H
#define QUEUE_H

typedef struct Queue_t
{
	int *data;
	int max_len;
	int front;
	int rear;
}Queue_t;

Queue_t *create_empty_queue(int len);
int is_empty_queue(const Queue_t *p);
int is_full_queue(const Queue_t *p);
void push_queue(Queue_t *p, int x);
void pop_queue(Queue_t *p);
int top_queue(const Queue_t *p);
int size_queue(const Queue_t *p);

#endif