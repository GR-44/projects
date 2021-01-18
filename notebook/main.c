#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#include "notebook.h"

int main(void)
{
	system("chcp 1251");        // текущая кодовая страница 1251
  	system("cls");              // очистка консоли

	pass();

    puts("\n\n");
    puts("******************************************************************************************");
    printf("%50s", "Access granted\n");
    puts("******************************************************************************************");
    puts("\n\n");

	FILE *nf_ptr; // указатель файла credit.dat
	int choice;

	if((nf_ptr = fopen("notes.dat", "rb+")) == NULL)
	{
		puts("File could not be opened.");
	}
	else
	{
		while((choice = enterChoice()) != 5)
		{
			switch(choice)
			{
				case 1:
					listFile(nf_ptr);
					break;

				case 2:
					openFile(nf_ptr);
					break;

				case 3:
					newRecord(nf_ptr);
					break;

				case 4:
					deleteRecord(nf_ptr);
					break;

				default:
					puts("incorrect");
					break;
			}
		}

		fclose(nf_ptr);
	}

	return 0;
}


















