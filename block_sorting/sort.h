#include <math.h>

#ifndef SORT_H
#define SORT_H

typedef enum{false, true} bool;

int int_pow(int number, int power);                 // возведение в степень целых положительных чисел, возвращает INT
int numpos(int number);                             // определяет количество разрядов в числе.
void block_sort(int *arr, int n);                   // (блочная)поразрядная сортировка целых положительных чисел в пределах INT_MAX
void block_sort_minus(int *arr, int n);             // (блочная)поразрядная сортировка целых положительных и отрицательных чисел в пределах INT_MAX
void bubble_sort(int *arr, int n);

int numpos(int number)                              // определяет количество разрядов в числе.
{
    int count = 0;
    if(number < 0)
    {
        number = -number;
    }

    while(1)
    {
        number /= 10;
        ++count;
        if(number == 0) break;
    }

    return count;
}
void block_sort(int *arr, int n)                    // (блочная)поразрядная сортировка целых положительных чисел в пределах INT_MAX
{
    int i, j;

    int **ss = (int**) malloc(10*sizeof(int*));
    for (int i=0; i < 10; i++)
    {
        ss[i] = (int*)malloc(n*sizeof(int));
    }

    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < n; j++)
        {
            ss[i][j] = -1; // = 0;
        }
    }

    int max_number = 0;
    for(i = 0; i < n; i++)
    {
        if(arr[i] > max_number)
        {
            max_number = arr[i];
        }
    }

    int number_position = numpos(max_number);

	int num;
	int sum;
	int div_step = 0;
	int step = 1;
	int decade;
	int index;
	for(decade = 1; decade <= number_position; decade++)
	{
        j = 0;
        num = 0;
        for(i = 0; i < n; i++)
        {
            sum = int_pow(10, step);                    // sum = pow(10, 2) - программа выдает ошибку, sum = 99!!!!!!!!!
            index = arr[i]%sum / int_pow(10, div_step);
            ss[index][j++] = arr[i];
        }
        ++step;
        ++div_step;

        for(i = 0; i < 10; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(ss[i][j] != -1)
                {
                    arr[num++] = ss[i][j];
                    ss[i][j] = -1;
                }
            }
        }
	}
    for (i = 0; i < 10; i++)
    {
        free(ss[i]);
    }
    free(ss);
}

void block_sort_minus(int *arr, int n)                       //  (блочная)поразрядная сортировка целых положительных и отрицательных чисел в пределах INT_MAX
{
    int i, j = 0, k = 0;
    int pos = 0;
    int neg = 0;
    for (i=0; i < n; i++)
    {
        if(arr[i] < 0)
        {
            ++neg;
        }
        else
        {
            ++pos;
        }
    }

    int *negative = (int*) malloc(neg * sizeof(int));
    int *positive = (int*) malloc(pos * sizeof(int));

    for (i = 0; i < n; i++)
    {
        if(arr[i] < 0)
        {
            negative[j] = arr[i];
            ++j;
        }
        else
        {
            positive[k] = arr[i];
            ++k;
        }
    }

    // обработка отрицательных чисел
    int **ss = (int**) malloc(10*sizeof(int*));
    for (int i=0; i < 10; i++)
    {
        ss[i] = (int*)malloc(neg*sizeof(int));
    }

    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < neg; j++)
        {
            ss[i][j] = 0;
        }
    }

    int min_number = 0;
    for(i = 0; i < neg; i++)
    {
        if(negative[i] < min_number)
        {
            min_number = negative[i];
        }
    }

    int number_position = numpos(min_number);

	int num;
	int sum;
	int div_step = 0;
	int step = 1;
	int decade;
	int index;

	for(decade = 1; decade <= number_position; decade++)
	{
        j = 0;
        num = 0;
        for(i = 0; i < neg; i++)
        {
            sum = int_pow(10, step);                                                //sum = pow(10, step) - программа выдает ошибку, sum = 99!!!!!!!!!
            index = abs(negative[i])%sum / int_pow(10, div_step);
            ss[index][j++] = negative[i];
        }
        ++step;
        ++div_step;

        for(i = 0; i < 10; i++)
        {
            for(j = 0; j < neg; j++)
            {
                if(ss[i][j] < 0)
                {
                    negative[num++] = ss[i][j];
                    ss[i][j] = 0;
                }
            }
        }
	}
    for (i = 0; i < 10; i++)
    {
        free(ss[i]);
    }
    free(ss);

    // обработка положительных чисел
    ss = (int**) malloc(10*sizeof(int*));
    for (int i=0; i < 10; i++)
    {
        ss[i] = (int*)malloc(pos*sizeof(int));
    }


    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < pos; j++)
        {
            ss[i][j] = -1;
        }
    }

    int max_number = 0;
    for(i = 0; i < pos; i++)
    {
        if(positive[i] > max_number)
        {
            max_number = positive[i];
        }
    }

    number_position = numpos(max_number);

	div_step = 0;
	step = 1;

	for(decade = 1; decade <= number_position; decade++)
	{
        j = 0;
        num = 0;
        for(i = 0; i < pos; i++)
        {
            sum = int_pow(10, step);                     // sum = pow(10, step) - программа выдает ошибку, sum = 99!!!!!!!!!
            index = positive[i]%sum / int_pow(10, div_step);
            ss[index][j++] = positive[i];
        }
        ++step;
        ++div_step;

        for(i = 0; i < 10; i++)
        {
            for(j = 0; j < pos; j++)
            {
                if(ss[i][j] != -1)
                {
                    positive[num++] = ss[i][j];
                    ss[i][j] = -1;
                }
            }
        }
	}
    for (i = 0; i < 10; i++)
    {
        free(ss[i]);
    }
    free(ss);

    num = 0;
    for(i = neg-1; i >= 0; i--)
    {
        arr[num++] = negative[i];
    }
    for(i = 0; i < pos; i++)
    {
        arr[num++] = positive[i];
    }

    free(negative);
    free(positive);
}

int int_pow(int number, int power)
{
    int total = 1;

    if(power == 0) return 1;

    if(power > 0)
    {
        for(int i = 1; i <= power; i++)
        {
            total *= number;
        }
    }

    return total;
}

void bubble_sort(int *arr, int n)
{
    int i, temp;
    bool swapped;

    do
    {
        swapped = false;
        for(i = 0; i < n; i++)
        {
            if(arr[i+1] < arr[i])
            {
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                swapped = true;
            }
        }
    }while(swapped);
}




#endif
