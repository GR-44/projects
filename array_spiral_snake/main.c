//  spiral snake
/*  1  2  3  4 5
   16 17 18 19 6
   15 24 25 20 7
   14 23 22 21 8
   13 12 11 10 9
*/


#include <stdio.h>

int main()
{
    int N;
    printf("%s", "Enter an integer above 1: ");
    scanf("%d", &N);
    puts("\n");

    int arr[N][N];

    if((N & 1) == 0)
    {
        int count = 0;
        int step = N / 2;
        int num = 1;
        int f_1 = 1;
        int f_2 = 1;
        int f_3 = 0;
        int f_4 = 1;
        int i, j, i2, j2, i3, i4, j3, j4;
        int N1, N2, N3, N4;
        N1 = N2 = N3 = N4 = N;

        while(count < step)
        {
            if(count == step-1)
            {
                for(i = count; i < N - count; i++)
                {
                    for(j = count; j < N - count; j++)
                    {
                        arr[i][j] = num++;
                        if((i == count+1) && (j == count))
                            arr[i][j] += 1;
                        if((i == count+1) && (j == count+1))
                            arr[i][j] -= 1;
                    }
                }
                break;
            }

            for(i = count; i < f_1; i++)
            {
                for(j = count; j < N1 ; j++)
                {
                    arr[i][j] = num++;
                }
            }
            for(i2 = f_2; i2 < N2; i2++)
            {
                for(j2 = N2-1; j2 > N2-2; j2--)
                {
                    arr[i2][j2] = num++;
                }
            }
            for(i3 = N3-1; i3 < N3; i3++)
            {
                for(j3 = N3-2; j3 >= f_3; j3--)
                {
                    arr[i3][j3] = num++;
                }
            }
            for(i4 = N4-2; i4 >= f_4; i4--)
            {
                for(j4 = count; j4 < f_4; j4++)
                {
                    arr[i4][j4] = num++;
                }
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
        }
    }

    if((N & 1) == 1)
    {
        int count = 0;
        int step = N / 2;
        int num = 1;
        int f_1 = 1;
        int f_2 = 1;
        int f_3 = 0;
        int f_4 = 1;
        int i, j, i2, j2, i3, i4, j3, j4;
        int N1, N2, N3, N4;
        N1 = N2 = N3 = N4 = N;

        while(count < step)
        {
            for(i = count; i < f_1; i++)
            {
                for(j = count; j < N1 ; j++)
                {
                    arr[i][j] = num++;
                }
            }
            for(i2 = f_2; i2 < N2; i2++)
            {
                for(j2 = N2-1; j2 > N2-2; j2--)
                {
                    arr[i2][j2] = num++;
                }
            }
            for(i3 = N3-1; i3 < N3; i3++)
            {
                for(j3 = N3-2; j3 >= f_3; j3--)
                {
                    arr[i3][j3] = num++;
                }
            }

            for(i4 = N4-2; i4 >= f_4; i4--)
            {
                for(j4 = count; j4 < f_4; j4++)
                {
                    arr[i4][j4] = num++;
                }
            }

            if(count == step - 1)
            {
                arr[N/2][N/2] = num++;
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
