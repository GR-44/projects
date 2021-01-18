#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 25

struct listNode
{
	int data;
	struct listNode *next_ptr;
};

typedef struct listNode ListNode;
typedef ListNode *ListNode_ptr;

void insert(ListNode_ptr *s_ptr);
double average(ListNode_ptr *s_ptr, int num);
int sum(ListNode_ptr *s_ptr);
void printlist(ListNode_ptr current_ptr);

int main(void)
{
	ListNode_ptr start_ptr = NULL;
	int i;

	srand(time(0));
	for(i = 1; i <= SIZE; i++)
	{
		insert(&start_ptr);
	}
	puts("List #1:");                 // âûâîä ñïèñêà
	printlist(start_ptr);

	puts("");
	printf("Sum = %d\n", sum(&start_ptr));
	printf("Average = %.3lf\n", average(&start_ptr, SIZE));

	return 0;
}

void insert(ListNode_ptr *s_ptr) // âñòàâêà íîâîãî óçëà â ñïèñîê
{
	ListNode_ptr new_ptr;
	ListNode_ptr previous_ptr;
	ListNode_ptr current_ptr;
	int num;

	new_ptr = malloc(sizeof(ListNode));

	if(new_ptr != NULL)
	{
		num = rand() % 101;
		new_ptr->data = num;
		new_ptr->next_ptr = NULL;

		previous_ptr = NULL;
		current_ptr = *s_ptr;

		while(current_ptr != NULL && num > current_ptr->data)
		{
			previous_ptr = current_ptr;
			current_ptr = current_ptr->next_ptr;
		}

		if(previous_ptr == NULL)
		{
			new_ptr->next_ptr = *s_ptr;
			*s_ptr = new_ptr;
		}
		else
		{
			previous_ptr->next_ptr = new_ptr;
			new_ptr->next_ptr = current_ptr;
		}
	}
	else
	{
		printf("%d not inserted. No memory available.\n", num);
	}
}

void printlist(ListNode_ptr current_ptr)
{
	if(current_ptr == NULL)
	{
		puts("List is empty.\n");
	}
	else
	{
		//puts("The list is:");

		while(current_ptr != NULL)
		{
			printf("%d --> ", current_ptr->data);
			current_ptr = current_ptr->next_ptr;
		}

		puts("NULL\n");
	}
}

int sum(ListNode_ptr *s_ptr)
{
	ListNode_ptr current_ptr;

	current_ptr = *s_ptr;

	int summary = 0;

	if(current_ptr == NULL)
	{
		puts("List is empty.\n");
	}
	else
	{
		while(current_ptr != NULL)
		{
			summary += current_ptr->data;
			current_ptr = current_ptr->next_ptr;
		}

	}

	return summary;
}

double average(ListNode_ptr *s_ptr, int num)
{
	ListNode_ptr current_ptr;

	current_ptr = *s_ptr;

	double avera = 0;
	int summary = 0;

	if(current_ptr == NULL)
	{
		puts("List is empty.\n");
	}
	else
	{
		while(current_ptr != NULL)
		{
			summary += current_ptr->data;
			current_ptr = current_ptr->next_ptr;
		}


	}

	avera = (double)summary / num;

	return avera;
}
