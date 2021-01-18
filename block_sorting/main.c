/*  Реализация блочной(поразрядной) сортировки в пределах INT_MAX  */


#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include "sort.h"

#define N 1000


int main()
{
	srand(time(0));
	int i;
	int arr[N];

	puts("Before sorting");
	for(i = 0; i < N; i++)
	{
	    arr[i] = rand() % 90 - 50;              // случайные отрицательные и положительные числа
		printf("%d ", arr[i]);
	}
	puts("");
	puts("");

	block_sort_minus(arr, N);
	//bubble_sort(arr, N);

	puts("");
	puts("After sorting");
	for(i = 0; i < N; i++)
	{
		printf("%d ", arr[i]);
	}
	puts("\n");
	puts("End");


	return 0;
}




