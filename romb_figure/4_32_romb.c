#include <stdio.h>

int main()
{
	int counter, x = 1, star = 1;
	printf("Enter an odd number from 3 to 31: ");
	scanf("%d", &counter);

	int num = counter/2;
	int sum = counter - 2;
	int num1 = 1;
	while(x <= counter)
	{
		if(x <= (counter/2))
		{
			int i, j, j1;
			for(x; x <= (counter/2); x++)
			{
				for(j = num; j > 0; j--)
				{
					printf("  ");
				}
				for(j1 = 1; j1 <= star; j1++)
				{
					printf(" *");
				}
				num -= 1;
				star += 2;
				printf("\n");
			}
		}
		if(x == ((counter/2)+1))
		{
			int k;
			for(k = 1; k <= counter; k++)
			{
				printf(" *");
			}
			printf("\n");
		}

		if(x > ((counter/2)+1))
		{
			int i1, j2, j3;
			for(i1 = 1; i1 <= 1; i1++)
			{
				for(j2 = 1; j2 <= num1; j2++)
				{
					printf("  ");

				}
				for(j3 = 1; j3 <= sum; j3++)
				{
					printf(" *");
				}
				num1++;
				sum -= 2;
				printf("\n");
			}
		}
	   x++;
	}
}
