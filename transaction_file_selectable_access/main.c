#include<stdio.h>

struct client_data
{
	int account_num;
	char first_name[15];
	char last_name[15];
	double balance;
};

struct transact
{
	int account_num;
	double sum;
};

int main(void)
{
	int i;
	FILE *of_ptr;
	FILE *tf_ptr;
	FILE *nf_ptr;

	struct client_data client = {0, "", "", 0.0};
	struct transact blank = {0, 0.0};

	if((nf_ptr = fopen("newmast.dat", "w")) == NULL)
	{
		puts("File could not be opened");
	}
	else
	{
		for(i = 1; i <= 100; i++)
		{
			fwrite(&client, sizeof(struct client_data), 1, nf_ptr);
		}

		fclose(nf_ptr);
	}

	puts("Creat a main file.");
	puts("");

	if((of_ptr = fopen("oldmast.dat", "rb+")) == NULL)
	{
		puts("File could not be opened");
	}
	else
	{
		for(i = 1; i <= 100; i++)
		{
			fwrite(&client, sizeof(struct client_data), 1, of_ptr);
		}

		fclose(of_ptr);
	}

	if((of_ptr = fopen("oldmast.dat", "rb+")) == NULL)
	{
		puts("File could not be opened");
	}
	else
	{
		printf("%s", "Enter account number (1 - 100, 0 to end input)\n? ");
		scanf("%d", &client.account_num);

		while(client.account_num != 0)
		{
			printf("%s", "Enter First name, Last name, balance\n? ");

			//óñòàíîâèòü ïîëÿ çàïèñè name, balance
			fscanf(stdin, "%s%s%lf", client.first_name, client.last_name, &client.balance);

			// íàéòè ïîçèöèþ óêàçàííîé ïîëüçîâàòåëåì çàïèñè
			fseek(of_ptr, (client.account_num - 1) * sizeof(struct client_data), SEEK_SET);

			// çàïèñàòü èíôîðìàöèþ ïîëüçîâàòåëÿ â ôàéë
			fwrite(&client, sizeof(struct client_data), 1, of_ptr);

			printf("%s", "Enter account number\n? ");
			scanf("%d", &client.account_num);
		}
		fclose(of_ptr);
	}
	puts("");
	puts("Would you like to print main file?");
	printf("Enter 1 to print or 2 to cancel: ");
	int num;
	scanf("%d", &num);
	if(num == 1)
	{
		if((of_ptr = fopen("oldmast.dat", "rb")) == NULL)
		{
			puts("File could not be opened.");
		}
		else
		{
			printf("%-10s%-16s%-11s%10s\n", "Account", "First Name", "Last Name", "Balance");

			while(!feof(of_ptr))
			{
				fread(&client, sizeof(struct client_data), 1, of_ptr);

				if(client.account_num != 0)
				{
					printf("%-10d%-16s%-11s%10.2lf\n", client.account_num, client.first_name, client.last_name, client.balance);
				}
			}

		fclose(of_ptr);
		}
	}

	puts("");
	puts("Creat a transaction file.");
	puts("");

	if((tf_ptr = fopen("trans.dat", "rb+")) == NULL)
	{
		puts("File could not be opened");
	}
	else
	{
		for(i = 1; i <= 100; i++)
		{
			fwrite(&blank, sizeof(struct transact), 1, tf_ptr);
		}

		fclose(tf_ptr);
	}

	// ôàéë òðàíçàêöèé ñ ïðîèçâîëüíûì äîñòóïîì
	if((tf_ptr = fopen("trans.dat", "rb+")) == NULL)
	{
		puts("File could not be opened");
	}
	else
	{
		printf("%s", "Enter account number (1 - 100, 0 to end input)\n? ");
		scanf("%d", &blank.account_num);

		while(blank.account_num != 0)
		{
			printf("%s", "Enter sum\n? ");

			//óñòàíîâèòü ïîëÿ çàïèñè name, balance
			fscanf(stdin, "%lf", &blank.sum);

			// íàéòè ïîçèöèþ óêàçàííîé ïîëüçîâàòåëåì çàïèñè
			fseek(tf_ptr, (blank.account_num - 1) * sizeof(struct transact), SEEK_SET);

			// çàïèñàòü èíôîðìàöèþ ïîëüçîâàòåëÿ â ôàéë
			fwrite(&blank, sizeof(struct transact), 1, tf_ptr);

			printf("%s", "Enter account number\n? ");
			scanf("%d", &blank.account_num);
		}
		fclose(tf_ptr);
	}
	puts("");
	puts("Would you like to print transaction file?");
	printf("Enter 1 to print or 2 to cancel: ");

	scanf("%d", &num);
	if(num == 1)
	{
		if((tf_ptr = fopen("trans.dat", "rb")) == NULL)
		{
			puts("File could not be opened.");
		}
		else
		{
			printf("%-10s%10s\n", "Account", "Sum");

			while(!feof(tf_ptr))
			{
				fread(&blank, sizeof(struct transact), 1, tf_ptr);

				if(blank.account_num != 0)
				{
					printf("%-10d%10.2lf\n", blank.account_num, blank.sum);
				}
			}

		fclose(tf_ptr);
		}
	}

	return 0;
}
