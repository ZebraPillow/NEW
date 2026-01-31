#include <stdio.h>
#include "test0131.h"

int main()
{
	Stack_t* stack = create_empty_stack(10);
	push_stack(stack, 101);
	push_stack(stack, 111);
	push_stack(stack, 121);
	push_stack(stack, 131);  
    printf("%d\n", top_stack(stack));//131
	clear_stack(stack);
	push_stack(stack, 141);
	pop_stack(stack);
	push_stack(stack, 151);
	push_stack(stack, 161);
	push_stack(stack, 171);
	printf("%d\n", top_stack(stack));//171

    while(!is_empty_stack(stack))
    {
        printf("%d\n", top_stack(stack));//171 161 151
        pop_stack(stack);
    }
	return 0;
}