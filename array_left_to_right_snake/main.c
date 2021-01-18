// горизонтальная змейка слева направо (left to right snake)
 /*    1  2  3  4  5
      10  9  8  7  6
      11 12 13 14 15
      20 19 18 17 16
      21 22 23 24 25
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

    for(int i = 0; i < N; i++)
    {
        if(i == 0 || (i & 1) == 0)
        {
            for(int j = 0; j < N; j++)
            {
                arr[i][j] = num++;
            }
        }
        if((i & 1) == 1)
        {
            for(int j = N-1; j >= 0; j--)
            {
                arr[i][j] = num++;
            }
        }
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



