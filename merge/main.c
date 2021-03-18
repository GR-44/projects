/*  This program combines two ordered lists into one.
    Function ListNode* merge(ListNode_ptr *, ListNode_ptr *) receives pointers to the first node of each list that needs to be merged
    and returns a pointer to the first node of the merged list.

*/



#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct listNode
{
	int data;
	struct listNode *next_ptr;
};

typedef struct listNode ListNode;
typedef ListNode *ListNode_ptr;

void printlist(ListNode_ptr current_ptr);
ListNode* merge(ListNode_ptr *s_ptr, ListNode_ptr *s_ptr_2);
void insert(ListNode_ptr *s_ptr);
int del(ListNode_ptr *s_ptr_2);

int main(void)
{
	ListNode_ptr start_ptr = NULL;
	ListNode_ptr start_ptr_2 = NULL;
	int i;

	srand(time(0));
	for(i = 1; i <= 10; i++)
	{
		insert(&start_ptr);
		insert(&start_ptr_2);
	}
	puts("List #1:");
	printlist(start_ptr);

	puts("");
	puts("List #2:");
	printlist(start_ptr_2);

	puts("United list:");
	printlist(merge(&start_ptr, &start_ptr_2));

	puts("List #1:");
	printlist(start_ptr);

	puts("");
	puts("List #2:");
	printlist(start_ptr_2);

	return 0;
}

void printlist(ListNode_ptr current_ptr)
{
	if(current_ptr == NULL)
		puts("List is empty.\n");
	else
	{
		while(current_ptr != NULL)
		{
			printf("%d --> ", current_ptr->data);
			current_ptr = current_ptr->next_ptr;
		}

		puts("NULL\n");
	}
}

void insert(ListNode_ptr *s_ptr)
{
	ListNode_ptr new_ptr;
	ListNode_ptr previous_ptr;
	ListNode_ptr current_ptr;
	int num;

	new_ptr = malloc(sizeof(ListNode));

	if(new_ptr != NULL)
	{
		num = rand() % 20 + 1;
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

ListNode* merge(ListNode_ptr *s_ptr, ListNode_ptr *s_ptr_2)
{
	ListNode_ptr new_ptr;
	ListNode_ptr previous_ptr;
	ListNode_ptr current_ptr;
	int num;

	while(*s_ptr_2 != NULL)
	{
		num = del(s_ptr_2);

		new_ptr = malloc(sizeof(ListNode));

		if(new_ptr != NULL)
		{
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

	return *s_ptr;
}

int del(ListNode_ptr *s_ptr_2)
{
	ListNode_ptr temp_ptr;
	int num;

	temp_ptr = *s_ptr_2;
	num = temp_ptr->data;
	*s_ptr_2 = (*s_ptr_2)->next_ptr;
	free(temp_ptr);

	return num;
}
