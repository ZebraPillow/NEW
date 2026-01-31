#include <stdio.h>
#include "test0129.h"

int main()
{
	List_t list = create_empty_list();
	insert_list(&list, 0, 10);//头插
	print_list(&list);//10
	insert_list(&list, 0, 20);//头插
	print_list(&list);//20 10
	insert_list(&list, 2, 30);//尾插
	print_list(&list);//20 10 30
    
	if(insert_list(&list, 10, 100) == 0)
    {
        printf("insert pos 10 error\n");//insert pos 10 error
    }
	print_list(&list);//20 10 30
	insert_list(&list, 1, 40);//中间插
	print_list(&list);//20 40 10 30
	
	delete_list(&list, 1);
	print_list(&list);//20 10 30

	if(delete_list(&list, 5) == 0)
    {
        printf("delete pos 5 error\n");//delete pos 5 error
    }
	print_list(&list);//20 10 30
	return 0;
}
