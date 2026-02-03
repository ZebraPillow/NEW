#include <stdio.h>
#include "work020201.h"
#include <stdlib.h>
int main()
{
	int *list = create_new_list();
	int number = user_number();
	int result = bisection_method(list, number);
	print_result(result, number);
/*	free_pointer(&list);*/
	return 0;
}