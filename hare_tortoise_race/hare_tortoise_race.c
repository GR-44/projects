#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<dos.h>

int main()
{
	short road[71];
	short i, step;
	for(i = 0; i < 71; i++)
	{
		road[i] = i;
	}
	short h_move;
	short t_move;
	char h = 'H';
	char t = 'T';
	short hare = 1;
	short tortoise = 1;
	short fast_move = 3;
	short slip_tortoise = 6;
	short slow_move = 1;
	short hare_sleep= 0;
	short big_jump = 9;
	short big_slip = 12;
	short little_jump = 1;
	short little_slip = 2;

	puts("BANG !!!!!");
	puts("AND THE'RE OFF !!!!!");
	puts("");

	srand(time(0));
	for(step = 1; step <= 200; step++)
	{
		t_move = rand() % 10 + 1;
		if(t_move >= 1 && t_move <=5)
		{
			tortoise += fast_move;
		}
		if(t_move >= 6 && t_move <=7)
		{
			tortoise -= slip_tortoise;
		}
		if(t_move >= 8 && t_move <=10)
		{
			tortoise += slow_move;
		}

		h_move = rand() % 10 + 1;
		if(h_move >= 1 && h_move <= 2)
		{
			hare += hare_sleep;
		}
		if(h_move >= 3 && h_move <= 4)
		{
			hare += big_jump;
		}
		if(h_move == 5)
		{
			hare -= big_slip;
		}
		if(h_move >= 6 && h_move <= 8)
		{
			hare += little_jump;
		}
		if(h_move >= 9 && h_move <= 10)
		{
			hare -= little_slip;
		}

		if(hare <= 0)
		{
			hare = 1;
		}
		if(tortoise <= 0)
		{
			tortoise = 1;
		}

		for(i = 1; i < 71; i++)
		{
			if(hare == road[i])
			{
				printf("%2c", h);
			}
			else
			{
				printf("  ");
			}
		}
		puts("");
		for(i = 1; i < 71; i++)
		{
			if(tortoise == road[i])
			{
				printf("%2c", t);
			}
			else
			{
				printf("  ");
			}
		}

		puts("");
		puts("");
		puts("");
		if(hare >= 70)
		{
			puts("Hare WINS !!!");
			printf("Step: %d\n", step);
			break;
		}
		if(tortoise >= 70)
		{
			puts("Tortoise WINS !!!");
			printf("Step: %d\n", step);
			break;
		}
		sleep(1);
		//system("cls");
	}



}
