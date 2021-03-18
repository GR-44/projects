#include<stdio.h>

struct hardware
{
	int record;
	char tool_name[20];
	int quantity;
	double price;
};

int enterChoice(void);
void textFile(FILE *readPtr);
void updateRecord(FILE *fPtr);
void newRecord(FILE *fPtr);
void deleteRecord(FILE *fPtr);

int main(void)
{
	FILE *hf_ptr; // óêàçàòåëü ôàéëà credit.dat
	int choice;

	if((hf_ptr = fopen("hardware.dat", "rb+")) == NULL)
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
					textFile(hf_ptr);
					break;

				case 2:
					updateRecord(hf_ptr);
					break;

				case 3:
					newRecord(hf_ptr);
					break;

				case 4:
					deleteRecord(hf_ptr);
					break;

				default:
					puts("incorrect");
					break;
			}
		}

		fclose(hf_ptr);
	}

	return 0;
}

void textFile(FILE *readPtr)
{
	FILE *writePtr; // óêàçàòåëü ôàéëà hardware.txt
	struct hardware tool = {0, "", 0, 0.0};

	if((writePtr = fopen("hardware.txt", "w")) == NULL)
	{
		puts("File could not be opened.");
	}
	else
	{
		rewind(readPtr); // âîçâðàùàåò óêàçàòåëü ôàéëà íà íà÷àëî
		fprintf(writePtr, "%-10s%-20s%-10s%16s\n", "Record #", "Tool name", "Quantity", "Price");

		puts("");
		puts("File hardware:");
		printf("%-10s%-20s%-10s%16s\n", "Record #", "Tool name", "Quantity", "Price");
		puts("");

		while(!feof(readPtr))
		{
			fread(&tool, sizeof(struct hardware), 1, readPtr);

			if(tool.record != 0)
			{
				printf("%-10d%-20s%5d%20.2lf$\n", tool.record, tool.tool_name, tool.quantity, tool.price);
			}
		}

		fclose(writePtr);
	}
}

void updateRecord(FILE *fPtr)
{
	int record_num;

	struct hardware tool = {0, "", 0, 0.0};

	printf("%s", "Enter record number to update (1 - 100): ");
	scanf("%d", &record_num);

	fseek(fPtr, (record_num - 1) * sizeof(struct hardware), SEEK_SET);

	fread(&tool, sizeof(struct hardware), 1, fPtr);

	if(tool.record == 0)
	{
		printf("Record #%d has no information.\n", record_num);
	}
	else
	{
		printf("%-10d%-20s%-10d%10.2lf\n", tool.record, tool.tool_name, tool.quantity, tool.price);

		printf("%s", "To change Tool name enter 1 or 2 to skip it: ");
		int num;
		scanf("%d", &num);
		if(num == 1)
		{
			printf("%s", "Enter Tool name: ");
			getchar();
			gets(tool.tool_name);
		}

		printf("%s", "To change Quantity enter 1 or 2 to skip it: ");
		scanf("%d", &num);
		if(num == 1)
		{
			printf("%s", "Enter quantity: ");
			scanf("%d", &tool.quantity);
		}

		printf("%s", "To change Price enter 1 or 2 to skip it: ");
		scanf("%d", &num);
		if(num == 1)
		{
			printf("%s", "Enter new price: ");
			scanf("%lf", &tool.price);
		}

		printf("%-10d%-20s%-10d%10.2lf\n", tool.record, tool.tool_name, tool.quantity, tool.price);
		fseek(fPtr, (record_num - 1) * sizeof(struct hardware), SEEK_SET);
		fwrite(&tool, sizeof(struct hardware), 1, fPtr);
	}
}

void deleteRecord(FILE *fPtr)
{
	struct hardware tool;
	struct hardware blank_record = {0, "", 0, 0.0};

	int record_num;

	printf("%s", "Enter record number to delete (1 - 100): ");
	scanf("%d", &record_num);

	fseek(fPtr, (record_num - 1) * sizeof(struct hardware), SEEK_SET);

	fread(&tool, sizeof(struct hardware), 1, fPtr);

	if(tool.record == 0)
	{
		printf("Record #%d does not exist.\n", record_num);
	}
	else
	{
		fseek(fPtr, (record_num - 1) * sizeof(struct hardware), SEEK_SET);
		fwrite(&blank_record, sizeof(struct hardware), 1, fPtr);
	}
}

void newRecord(FILE *fPtr)
{
	struct hardware tool = {0, "", 0, 0.0};
	int record_num;

	printf("%s", "Enter new record number (1 - 100): ");
	scanf("%d", &record_num);

	fseek(fPtr, (record_num - 1) * sizeof(struct hardware), SEEK_SET);

	fread(&tool, sizeof(struct hardware), 1, fPtr);

	if(tool.record != 0)
	{
		printf("Record #%d already contains information.\n", tool.record);
	}
	else
	{
		printf("%s", "Enter tool name: ");
		getchar();
		gets(tool.tool_name);

		printf("%s", "Enter quantity, price.\n? ");
		scanf("%d%lf", &tool.quantity, &tool.price);

		tool.record = record_num;

		fseek(fPtr, (tool.record - 1) * sizeof(struct hardware), SEEK_SET);
		fwrite(&tool, sizeof(struct hardware), 1, fPtr);
	}
}

int enterChoice(void)
{
	int menuChoice;

	printf("%s", "\nEnter your choice\n"
		"1 - store a formatted text file of hardware called \"hardware.txt\" for printing\n"
		"2 - update a record\n"
		"3 - add a new record\n"
		"4 - delete a record\n"
		"5 - end program\n? ");

	scanf("%d", &menuChoice);

	return menuChoice;
}
