#ifndef TEST0129H
#define TEST0129H
#define MAX_DATA_SIZE 100

typedef struct List_t
{
	int data[MAX_DATA_SIZE];
	int size;
}List_t;

List_t create_empty_list();
int is_full(const List_t *p);
int is_empty(const List_t *p);
void clear_list(List_t *p);
void print_list(const List_t *p);
int	list_size(const List_t *p);
int insert_list(List_t *p, int pos, int x);
int delete_list(List_t *p, int pos);

#endif