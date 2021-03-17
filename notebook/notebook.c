#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#include "notebook.h"

int main(void)
{
	system("chcp 1251");    // russion language   
  	system("cls");              

	if(!pass())
	{
		return 1;
	}

    puts("\n\n");
    puts("******************************************************************************************");
    puts("================================ Access granted ==========================================");
    puts("******************************************************************************************");
    puts("\n\n");

	FILE *nf_ptr; 
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


















