#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main()
{
	Queue_t *queue = create_empty_queue(5);
	push_queue(queue, 10);
	push_queue(queue, 20);
	push_queue(queue, 30);
	push_queue(queue, 40);

	if( !is_full_queue(queue))
		push_queue(queue, 50);
	if( !is_full_queue(queue))
		push_queue(queue, 60);
	printf("size:%d\n", size_queue(queue));
	while( !is_empty_queue(queue) )
	{
		printf("%d\n", top_queue(queue));
		pop_queue(queue);	
	}
	return 0;
}