#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));

    int answer;
    int number;

    number = rand() % 100 + 1;
    puts("*********** Guess number *************");
    puts("Guess number 1 - 100");

    do
    {
        printf("%s", "Your answer: ");
        scanf("%d", &answer);

        if(answer > number)
        {
            puts("Your answer is bigger.");
        }
        if(answer < number)
        {
            puts("Your answer is smaller.");
        }
        puts("");
    }
    while(number != answer);

    puts("YES!!!");
    puts("Good job!");


    return 0;
}
