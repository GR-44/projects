/*  моделирование торговли на фьючерсах в течение года 100 трейдерами */


#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define NEGATIVEPERCENT 60

int main()
{
    srand(time(0));
    int contract = 1;
    int sdelka, number, sum, i;
    int num_sdelka;
    int deposit = 1000;
    int trader;
    int month = 1;
    int num, loss;
    int average = 0, count = 0;
    int positive = 0, totalPos = 0;
    int negative = 0, totalNeg = 0;
    int choice;
    int plus_deposit = 0;
    int minus_deposit = 0;
    int final_deposit[200000] = {0};

    puts("Deposit = 1000$");
    puts("");

	for (trader = 1; trader <= 100; trader++)
 	{
 		for(month = 1; month <= 12; month++)
 		{
 			//num_sdelka = rand() % 5 + 4;
 			puts("");
 			printf("Month [%2d]\n", month);
			for (sdelka = 1; sdelka <= 10; sdelka++)
			{
				number = rand() % 100 + 1;
				if (number > NEGATIVEPERCENT)
		 		{
		 		    choice = rand() % 4 + 1;
		 		    switch(choice)
		 		    {
                        case 1:
                            num = 50;
                            break;

                        case 2:
                        case 3:
                        case 4:
                            num = 100;
                            break;

                        default:
                            break;
		 		    }

    				//num = rand() % 11;
    				sum = num * (rand() % 11) * contract;
		 			deposit += sum;
    				++positive;
    				++totalPos;
    				printf("%d$ ", sum);
	 			}
				if (number <= NEGATIVEPERCENT)
 				{
 				    choice = rand() % 4 + 1;
		 		    switch(choice)
		 		    {
                        case 1:
                            loss = 30;
                            break;

                        case 2:
                        case 3:
                        case 4:
                            loss = 63;
                            break;

                        default:
                            break;
		 		    }
 					loss = loss * contract;
					deposit -= (63 * contract);
   					++negative;
   					++totalNeg;
			 		printf("-%d$ ", loss);
		 		}
				if (deposit <= 0)
	 			{
     				printf("Null deposit at sdelka = %d\n", sdelka);
      				break;
		 		}


			}
			//puts("");
  		}
        ++final_deposit[deposit];
        if (deposit > 0)
        {
            ++plus_deposit;
            average += deposit;
            ++count;
        }
        if (deposit <= 0)
        {
            ++minus_deposit;
        }
        puts("");
        printf("Trader [%d] deposit = %d$\n", trader, deposit);
        printf("Number of positive trades: %d\n", positive);
    	printf("Number of negative trades: %d\n", negative);
        printf("Contracts: %d\n", contract);
        puts("");
        deposit = 1000;
        positive = 0;
        negative = 0;
        contract = 1;
        month = 1;
    }

	puts("");
    printf("%s%21s\n\n", "Size of deposit:", "People:");

    int j;
    for (j = 0; j < 200000; j++)
    {
        if (final_deposit[j] > 0)
        {
            printf("Final deposit [%6d$] \t %3d\n", j, final_deposit[j]);
        }
    }

    average = average / count;
    puts("");
    printf("Average deposit: [%d$]\n", average);
    puts("");
    printf("Total positive trades: %d\n", totalPos);
    printf("Total negative trades: %d\n", totalNeg);
    puts("");
    printf("Number of deposit plus: %d\n", plus_deposit);
    printf("Number of deposit minus: %d\n", minus_deposit);

}
