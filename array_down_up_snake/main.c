// down up snake
/*     1 10 11 20 21
       2  9 12 19 22
       3  8 13 18 23
       4  7 14 17 24
       5  6 15 16 25
*/


#include <stdio.h>

int main()
{
    int N;
    printf("%s", "Enter an integer above 1: ");
    scanf("%d", &N);
    puts("\n");

    int num = 1;
    int arr[N][N];

    int count = 0;
    int i, j;
    int x = 0;
    while(count < N)
    {
        if(x == 0 || (x & 1) == 0)
        {
           for(i = 0; i < N; i++)
            {
                for(j = x; j < x + 1; j++)
                {
                    arr[i][j] = num++;
                }
            }
        }
        if((x & 1) == 1)
        {
            for(i = N-1; i >= 0; i--)
            {
                for(j = x; j < x + 1; j++)
                {
                    arr[i][j] = num++;
                }
            }
        }

        ++count;
        ++x;
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            printf("%3d ", arr[i][j]);
        }
        puts("");
    }
    puts("");


    return 0;
}
