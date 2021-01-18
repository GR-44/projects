#include <stdio.h>
#include <stdlib.h>

struct stackNode
{
    char data;
    struct stackNode *next_ptr;
};

typedef struct stackNode StackNode;
typedef StackNode *StackNode_ptr;

void convert_to_postfix(char infix[], char postfix[]);
int precedence(char operator1, char operator2);
void push(StackNode_ptr *top_ptr, char value);
char pop(StackNode_ptr *top_ptr);
//char stack_top(StackNode_ptr top_ptr);
//int is_empty(StackNode_ptr top_ptr);
void print_stack(StackNode_ptr top_ptr);

int main()
{
    //StackNode_ptr stack_ptr;
    char infix[60];
    char postfix[60];

    convert_to_postfix(infix, postfix);

    printf("\n Infix Expression : %s ", infix);
    printf("\n Postfix Expression : %s ", postfix);
    printf("\n Thank you\n ");

    return 0;
}

void print_stack(StackNode_ptr top_ptr)
{
    if(top_ptr == NULL)
    {
        puts("The stack is empty.\n");
    }
    else
    {
        puts("The stack is:");

        while(top_ptr != NULL)
        {
            printf("\'%c\' --> ", top_ptr->data);
            top_ptr = top_ptr->next_ptr;
        }

        puts("NULL\n");
    }
}

/*int is_empty(StackNode_ptr top_ptr)
{
    return top_ptr == NULL;
}*/

void push(StackNode_ptr *top_ptr, char value)
{
    StackNode_ptr new_ptr;
    new_ptr = malloc(sizeof(StackNode));

    if(new_ptr != NULL)
    {
        new_ptr->data = value;
        new_ptr->next_ptr = *top_ptr;
        *top_ptr = new_ptr;
    }
    else
    {
        printf("%c not inserted. No memory available.\n", value);
    }
}

char pop(StackNode_ptr *top_ptr)
{
    StackNode_ptr temp_ptr;
    int pop_value;

    temp_ptr = *top_ptr;
    pop_value = (*top_ptr)->data;
    *top_ptr = (*top_ptr)->next_ptr;
    free(temp_ptr);

    return pop_value;
}

/*char stack_top(StackNode_ptr top_ptr)
{
    int pop_value;
}*/

int precedence(char operator1, char operator2)
{
    int k, p1, p2;
    char oprList[] = {'+', '-', '*', '/', '%', '^', '('};
    int prioList[] = {0,0,1,1,2,3,4};
    if( operator2 == '(' )
        return 0;
    for(k = 0; k < 6; k ++)
    {
        if(operator1 == oprList[k])
            p1 = prioList[k];
    }
    for(k = 0; k < 6; k ++)
    {
        if(operator2 == oprList[k])
            p2 = prioList[k];
    }
    if(p1 < p2)
        return 1;
    else
        return 0;
}

void convert_to_postfix(char infix[], char postfix[])
{
    StackNode_ptr stack_ptr = NULL;

    int j = 0;
    int i = 0;
    char k;
    printf("\n Enter Infix Expression : ");
    gets(infix);
    while((k = infix[i++]) != '\0')
    {
        switch(k)
        {

        case ' ' :
            break;

        case '(' :
        case '+' :
        case '-' :
        case '*' :
        case '/' :
        case '^' :
        case '%' :
            if(stack_ptr == NULL)
            {
                push(&stack_ptr, k);
            }
            else
            {
                if(k != '(' )
                    {
                        while(precedence(k, stack_ptr->data) == 1 && stack_ptr != NULL)
                            {
                                postfix[j] = pop(&stack_ptr);
                                j++;
                                if(stack_ptr == NULL)
                                    break;
                            }
                    }
                    push(&stack_ptr, k);
            }
            break;

        case ')' :
            while(stack_ptr->data != '(' )
            {
                postfix[j] = pop(&stack_ptr);
                j++;
            }

            pop(&stack_ptr);
            break;

        default :
            postfix[j] = k;
            j++;
        }
    }

    while(stack_ptr != NULL)// && stack_ptr->data != '(')
    {
        postfix[j] = stack_ptr->data;

        j++;
        stack_ptr = stack_ptr->next_ptr;
    }

    postfix[j] = '\0';

    print_stack(stack_ptr);

}


















