#include <stdio.h>
#include <stdlib.h>

void vacant_first(int []);
void vacant_econom(int []);
void menu();

int main()
{
    int ss[11] = {0};
    int check1 = 0, check2 = 0;
    int choice;
    int place;
    int flag;
    int i;

    puts("********************");
    puts("FLIGHT TICKETS");
    puts("********************");

    menu();
    printf("Your choice: ");
    scanf("%d", &choice);
    system("cls");
    while(choice != -1)
    {
        switch(choice)
        {
            case 1:
                vacant_first(ss);
                flag = 0;
                for(i = 1; i < 6; i++)
                {
                    if(ss[i] == 1)
                    {
                        ++check1;
                    }
                }
                if(check1 == 5)
                {
                    int num;
                    puts("");
                    puts("ALL FIRST CLASS TICKETS SOLD!");
                    puts("");
                    printf("If you like to buy economy class ticket press 1 and 2 to cancel.\n");
                    printf("Your choice: ");
                    scanf("%d", &num);
                    system("cls");
                    if(num == 1)
                    {
                        choice = 2;
                        flag = 1;
                        break;
                    }
                    else
                    {
                        puts("");
                        puts("NEXT FLIGHT IN 3 HOURS.");
                        break;
                    }
                }
                puts("");
                printf("Choose a place: ");
                scanf("%d", &place);
                system("cls");

                if(place >= 1 && place <= 5)
                {
                    if(ss[place] == 0)
                    {
                        ss[place] = 1;
                    }
                    else
                    {
                        puts("THIS PLACE IS ALREADY BUSY!");
                        choice = 1;
                        flag = 1;
                        break;
                    }
                }
                else
                {
                    puts("Wrong place!");
                    choice = 1;
                    flag = 1;
                    break;
                }

                puts("");
                printf("***************************\n");
                printf("TICKET\n");
                printf("Class: First\n");
                printf("Seat: %d\n", place);
                printf("***************************\n");
                break;

            case 2:
                vacant_econom(ss);
                flag = 0;
                for(i = 6; i < 11; i++)
                {
                    if(ss[i] == 1)
                    {
                        ++check2;
                    }
                }
                if(check2 == 5)
                {
                    int num;
                    puts("");
                    puts("ALL ECONOMY CLASS TICKETS SOLD!");
                    puts("");
                    printf("If you like to buy first class ticket press 1 and 2 to cancel.\n");
                    printf("Your choice: ");
                    scanf("%d", &num);
                    system("cls");
                    if(num == 1)
                    {
                        choice = 1;
                        flag = 1;
                        break;
                    }
                    else
                    {
                        puts("");
                        puts("NEXT FLIGHT IN 3 HOURS.");
                        break;
                    }
                }
                puts("");
                printf("Choose a place: ");
                scanf("%d", &place);
                system("cls");
                if(place >= 6 && place <= 10)
                {
                    if(ss[place] == 0)
                    {
                        ss[place] = 1;
                    }
                    else
                    {
                        puts("THIS PLACE IS ALREADY BUSY!");
                        choice = 2;
                        flag = 1;
                        break;
                    }
                }
                else
                {
                    puts("Wrong place!");
                    choice = 2;
                    flag = 1;
                    break;
                }
                puts("");
                printf("***************************\n");
                printf("TICKET\n");
                printf("Class: Economy\n");
                printf("Seat: %d\n", place);
                printf("***************************\n");
                break;

            default:
                menu();
                break;

        }
        check1 = 0;
        check2 = 0;
        if(flag == 0)
        {
            menu();
            printf("Your choice: ");
            scanf("%d", &choice);
            system("cls");
        }
    }

    return 0;
}
void menu()
{
    puts("");
    puts("To buy first class ticket press 1");
    puts("To buy economy class ticket press 2");
    puts("To exit press -1");
    puts("");
}

void vacant_first(int ss[])
{
    int i;
    puts("");
    puts("Vacancy:");
    for(i = 1; i < 6; i++)
    {
        if(ss[i] == 0)
        {
            printf("First class seat[%d]: %15s\n", i, "vacant");
        }
        else
        {
            printf("First class seat[%d]: %15s\n", i, "busy");
        }
    }
}

void vacant_econom(int ss[])
{
    int i;
    puts("");
    puts("Vacancy:");
    for(i = 6; i < 11; i++)
    {
        if(ss[i] == 0)
        {
            printf("Economy class seat[%2d]: %15s\n", i, "vacant");
        }
        else
        {
            printf("Economy class seat[%2d]: %15s\n", i, "busy");
        }
    }
}
