#ifndef TEST0131_H
#define TEST0131_H

typedef struct Stack_t
{
	int *data;
	int max_len;
	int top;
}Stack_t;

Stack_t *create_empty_stack(int len);
void clear_stack(Stack_t *p);
void del_stack(Stack_t *p);
int is_empty_stack(const Stack_t *p);
int is_full_stack(const Stack_t *p);
void push_stack(Stack_t *p, int x);
void pop_stack(Stack_t *p);
int top_stack(const Stack_t *p);

#endif