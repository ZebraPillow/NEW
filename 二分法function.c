#include <stdio.h>
#include <stdlib.h>
#include "work020201.h"

int *create_new_list()
{
	int *p1 = (int *)malloc(LENGTH*sizeof(int));
	if( p1==NULL )
		printf("create list error\n");
	int i;
	for( i=0; i<LENGTH; i++ )
		p1[i] = i;
	return p1;
}

int user_number()
{
	int *number = (int *)malloc(sizeof(int));
	if( number==NULL )
		printf("create number error\n");
	scanf("%d", number);
	return *number;
}

int bisection_method(const int *list, int number)
{
	int left = 0;
	int right = LENGTH-1;
	int mid;
	while( left<=right )
	{
		mid = (left+right)/2;
		if( number == mid )
			return mid;
		if( number < mid )
		{
			printf("%2d left\n", mid);
			right = mid-1;
		}
		else
		{
			printf("%2d right\n", mid);
			left = mid+1;
		}
	}
	return -1;
}


void print_result(int result, int number)
{
	if( result>=0 )
		printf("pos:%d, number:%d\n", result, number);
	else
		printf("search failed\n");
}

/*void free_pointer(int **p2)
{
	free(p2);// *p2
	p2 = NULL;// *p2
}*/