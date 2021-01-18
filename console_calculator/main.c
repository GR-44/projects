#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"

int main()
{
    double number;
    char symbol;
    double sum = 0;
    //printf("%25s", "Calculator");

    scanf("%lf", &number);
    scanf("%c", &symbol);
    while(1)
    {
	    if (symbol == '+')
        {
           	sum = plus(number);
           	puts("******************(press 'c' and than 'Enter' - clear, q - exit)*****************");
           	if ((sum - (int)sum) == 0)
           	{
                printf("%.0lf", sum);
            } else
            {
            	printf("%.9lf", sum);
			}
            number = sum;
        }
        if (symbol == '-')
           {
           	sum = minus(number);
            puts("******************(press 'c' and than 'Enter' - clear, q - exit)*****************");
           	if ((sum - (int)sum) != 0)
           	{
                printf("%.9lf", sum);
            } else
            {
            	printf("%.0lf", sum);
			}
            number = sum;
           }
		if (symbol == '*')
           {
           	sum = multiply(number);
           	puts("******************(press 'c' and than 'Enter' - clear, q - exit)*****************");
           	if ((sum - (int)sum) == 0)
           	{
                printf("%.0lf", sum);
            } else
            {
            	printf("%.9lf", sum);
			}
            number = sum;
           }
		if (symbol == '/')
           {
           	sum = divide(number);
           	puts("******************(press 'c' and than 'Enter' - clear, q - exit)*****************");
           	if ((sum - (int)sum) == 0)
           	{
                printf("%.0lf", sum);
            } else
            {
            	printf("%.9lf", sum);
			}
            number = sum;
           }
        if (symbol == 'c')
        {
            system("cls");
            number = 0;
            sum = 0;
            symbol = 0;
            scanf("%lf", &number);
        }
        if(symbol =='q' || symbol == 'Q')
            break;

        scanf("%c", &symbol);
    }

    return 0;
}

