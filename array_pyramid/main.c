//  2 2 2       3 3 3 3 3
//  2 1 2       3 2 2 2 3
//  2 2 2       3 2 1 2 3
//              3 2 2 2 3
//              3 3 3 3 3

#include <stdio.h>

int main()
{
    int N;
    printf("%s", "Enter an integer above 1: ");
    scanf("%d", &N);
    puts("\n");

    int M = N + (N - 1);

    int arr[M][M];

    int count = 0;
    int step = M / 2;
    int num = N;
    int f_1 = 1;
    int f_2 = 1;
    int f_3 = 0;
    int f_4 = 1;
    int i, j, i2, j2, i3, i4, j3, j4;
    int N1, N2, N3, N4;
    N1 = N2 = N3 = N4 = M;

    while(count < step)
    {
        for(i = count; i < f_1; i++)
        {
            for(j = count; j < N1 ; j++)
            {
                arr[i][j] = num;
            }
        }
        for(i2 = f_2; i2 < N2; i2++)
        {
            for(j2 = N2-1; j2 > N2-2; j2--)
            {
                arr[i2][j2] = num;
            }
        }
        for(i3 = N3-1; i3 < N3; i3++)
        {
            for(j3 = N3-2; j3 >= f_3; j3--)
            {
                arr[i3][j3] = num;
            }
        }

        for(i4 = N4-2; i4 >= f_4; i4--)
        {
            for(j4 = count; j4 < f_4; j4++)
            {
                arr[i4][j4] = num;
            }
        }

        if(count == step - 1)
        {
            arr[M/2][M/2] = 1;
            break;
        }

        ++count;
        ++f_1;
        --N1;
        ++f_2;
        --N2;
        --N3;
        ++f_3;
        --N4;
        ++f_4;
        --num;
    }


    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < M; j++)
        {
            printf("%2d ", arr[i][j]);
        }
        puts("");
    }
    puts("");

    return 0;
}
