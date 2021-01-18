#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#ifndef NOTEBOOK_H
#define NOTEBOOK_H

struct notebook
{
	int number;
	int day;
	int month;
	int year;
	char record[5000];
};

void listFile(FILE *readPtr)
{
	FILE *writePtr; // указатель файла notes.txt
	struct notebook note = {0, 0, 0, 0, ""};

	if((writePtr = fopen("notes.txt", "w")) == NULL)
	{
		puts("File could not be opened.");
	}
	else
	{
		rewind(readPtr); // возвращает указатель файла на начало
		//fprintf(writePtr, "%-s%-12s  %-15s\n", "Номер заметки", "DD/MM/YYYY", "Заметка");

		puts("");
		puts("List of notes:");

		while(!feof(readPtr))
		{
			fread(&note, sizeof(struct notebook), 1, readPtr);

			if(note.number != 0)
			{
				printf("%-4d   %02d.%02d.%04d\t", note.number, note.day, note.month, note.year);
				int i;
				for(i = 0; i <= 25; i++)
				{
					printf("%c", note.record[i]);
				}
				putchar('\n');

			}
		}

		fclose(writePtr);
	}
}

void openFile(FILE *fPtr)
{
	FILE *writePtr; // указатель файла notes.txt

	int note_num;

	struct notebook note = {0, 0, 0, 0, ""};

	if((writePtr = fopen("notes.txt", "w")) == NULL)
	{
		puts("File could not be opened.");
	}
	else
	{
		printf("%s", "Enter note number: ");
		scanf("%d", &note_num);

		fseek(fPtr, (note_num - 1) * sizeof(struct notebook), SEEK_SET);

		fread(&note, sizeof(struct notebook), 1, fPtr);

		if(note.number == 0)
		{
			printf("Note #%d has no information.\n", note_num);
		}
		else
		{
			puts("");
			puts("Note:");

			if(note.number != 0)
			{
				printf("%s\n", note.record);
			}

			fclose(writePtr);
		}
	}
}

void deleteRecord(FILE *fPtr)
{
	struct notebook note;
	struct notebook blank_note = {0, 0, 0, 0, ""};

	int note_num;

	printf("%s", "Enter note number: ");
	scanf("%d", &note_num);

	fseek(fPtr, (note_num - 1) * sizeof(struct notebook), SEEK_SET);

	fread(&note, sizeof(struct notebook), 1, fPtr);

	if(note_num == 0)
	{
		printf("Note #%d does not exist.\n", note_num);
	}
	else
	{
		fseek(fPtr, (note_num - 1) * sizeof(struct notebook), SEEK_SET);
		fwrite(&blank_note, sizeof(struct notebook), 1, fPtr);
	}
}

void newRecord(FILE *fPtr)
{
	struct notebook note = {0, 0, 0, 0, ""};
	int note_num;

	printf("%s", "Enter note number: ");
	scanf("%d", &note_num);

	fseek(fPtr, (note_num - 1) * sizeof(struct notebook), SEEK_SET);

	fread(&note, sizeof(struct notebook), 1, fPtr);

	if(note.number != 0)
	{
		printf("Note #%d has already information.\n", note.number);
	}
	else
	{
		printf("%s", "Enter the date in format(dd mm yyyy): ");
		scanf("%d%d%d", &note.day, &note.month, &note.year);

		printf("%s\n", "Note:");
		getchar();
		gets(note.record);

		note.number = note_num;

		fseek(fPtr, (note.number - 1) * sizeof(struct notebook), SEEK_SET);
		fwrite(&note, sizeof(struct notebook), 1, fPtr);
	}
}

int enterChoice(void)
{
	int menuChoice;

	printf("%s", "\nChoose:\n"
		"1 - List of notes.\n"
		"2 - Show a note.\n"
		"3 - Add a new note.\n"
		"4 - Delete note.\n"
		"5 - Exit.\n? ");

	while(scanf("%d", &menuChoice) == 0 || (menuChoice < 1 || menuChoice > 5))
    {
        printf("Wrong input!!!  Enter an integer from 1 to 5: ");
        fflush(stdin);
    }

	return menuChoice;
}

int check(char password[])
{
    char pass[20] = "pass";
    if(strcmp(pass, password) == 0)
    {
        return 1;
    }

    return 0;
}

void pass()
{
    char password[20];
	char c;
	int i;
	int attempt = 3;

	int flag = 1;

	while(flag)
    {
        //puts("");
        system("cls");
        puts("\n\n\n\n");
        printf("%10s%d%19s", "Attempt: ", attempt, "Enter password: ");
            //scanf("%s", password);
        for (i = 0; ; i++)
        {
            c = getch();
            if(c == 13 || c == 10)
            {
                break;
            }
            password[i] = c;
                //putch('');
        }

        password[i] = '\0';

        if(check(password))
        {
            flag = 0;
        }
        else
        {
            --attempt;
            if(attempt == 0)
            {
                _Exit(0);
            }
        }

    }
}


#endif // NOTEBOOK_H
