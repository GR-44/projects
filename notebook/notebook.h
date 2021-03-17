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

void encrypt(char *text);
void decrypt(char *text);
int pass();

void listFile(FILE *readPtr)
{
	struct notebook note = {0, 0, 0, 0, ""};

	rewind(readPtr); // возвращает указатель файла на начало

	puts("");
	system("cls");
	puts("List of notes:");

	while(!feof(readPtr))
	{
		fread(&note, sizeof(struct notebook), 1, readPtr);

		if(note.number != 0)
		{
			printf("%-4d   %02d.%02d.%04d\t", note.number, note.day, note.month, note.year);
			int i;
			char code[5000];
			decrypt(note.record);
			strncpy(code, note.record, 25);

			for(i = 0; i <= 25; i++)
			{
				printf("%c", code[i]);
			}
			putchar('\n');

		}
	}
	puts("");

}

void openFile(FILE *fPtr)
{
	int note_num;

	struct notebook note = {0, 0, 0, 0, ""};

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
		system("cls");
		puts("Note:");

		char code[5000];
		int i;
		decrypt(note.record);
		strcpy(code, note.record);

		if(note.number != 0)
		{
			printf("%s\n", code);
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
	system("cls");
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
		int i;
		char code[5000];

		printf("%s", "Enter the date (dd/mm/yyyy): ");
		scanf("%d%*c%d%*c%d", &note.day, &note.month, &note.year);

		printf("%s\n", "Note:");
		getchar();
		fgets(code, 5000, stdin);
		encrypt(code);

		strcpy(note.record, code);
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

	while (scanf("%d", &menuChoice) == 0 || (menuChoice < 1 || menuChoice > 5))
	{
		puts("Wrong input! Enter an integer 1 - 5.");
		printf("%s", "Your choice: ");
		getchar();
	}
	return menuChoice;
}

int check(char *password)
{
	char check_pass[20];
	(strlen(password) <= 20) ? strcpy(check_pass, password) : strncpy(check_pass, password, 20);
    char pass[20] = "pass";
    if(strcmp(pass, password) == 0)
    {
        return 1;
    }

    return 0;
}

int pass()
{
    char password[20];
	char c;
	int i = 0;
	int attempt = 3;
	puts("\n\n\n\n");
	printf("%30s", "Enter password: ");
	while (1)
	{
		c = getch();
		if (c == 13)
			break;

		if (c == 8 && i != 0)
			--i;

		if (c != 13 && c != 8)
		{
			password[i] = c;
			++i;
		}
	}

	password[i] = '\0';
	int flag = 1;

	while(flag)
    {
        if(check(password))
        {
            flag = 0;
        }
        else
        {
			i = 0;

            --attempt;
            if(attempt == 0)
            {
                return 0;
            }

            puts("");
            printf("%10s%d%19s", "Attempt: ", attempt, "Enter password: ");
            while(1)
            {
                c = getch();
                if(c == 13)
                    break;

				if(c == 8 && i != 0)
					--i;

				if (c != 13 && c != 8)
				{
					password[i] = c;
					++i;
				}
            }

            password[i] = '\0';
        }
    }

	return 1;
}

void encrypt(char *text)
{
    while(*text)
    {
	 	*text = ((*text + 31) ^ 8742) - 17;
        ++text;
    }
}

void decrypt(char *text)
{
    while(*text)
	{
		*text = ((*text + 17) ^ 8742) - 31;
		++text;
	}
}

#endif // NOTEBOOK_H




























