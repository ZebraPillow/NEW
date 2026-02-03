#include <stdio.h>
#include "work020201.h"
#include <stdlib.h>
int main()
{
	int *list = create_new_list();
	int number = user_number();
	int result = bisection_method(list, number);
	print_result(result, number);
/*	free_pointer(&l#ifndef WORK020201_H
#define WORK020201_H

#define LENGTH 101

int *create_new_list();
int user_number();
int bisection_method(const int *list, int number);
void print_result(int result, int number);
void free_pointer(int **p2);

#endifist);*/
	return 0;
}