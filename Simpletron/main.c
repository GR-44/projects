#include<stdio.h>
#include<locale.h>

int main()
{
	//setlocale(LC_ALL, "Rus");
	puts("*** Simpletron welcomes you! ***");
	puts("*** Please enter your program, one command at a time. ***");
	puts("*** I will display the current address and the question mark (?) as a hint ***");
	puts("*** The command you entered will be placed at the specified address. ***");
	puts("*** To stop entering the program, enter the number -99999. ***");
	puts("===============================================================================================");
	printf("Example: the program reads two numbers entered from the keyboard, calculates their sum and outputs it \n"
        "00? +1007 \n"
        "01? +1008 \n"
        "02? +2007 \n"
        "03? +3008 \n"
        "04? +2109 \n"
        "05? +1109 \n"
        "06? +4300 \n"
        "07? +0000 \n"
        "08? +0000 \n"
        "09? +0000 \n"
        "10? -99999 \n");
    puts("===============================================================================================");

	int memory[100] = {0};
	int accumulator = 0;
	int num;
	int counter = 0;
	int instructionCounter = 0;
	int instructionRegister = 0;
	int operationCode = 0;
	int operand = 0;

	printf("%02d?  ", counter);
	scanf("%d", &num);
	while(num != -99999)
	{
		if(num < -9999 || num > 9999)
		{
			puts("Unknown command! Repeat input.");
		}
		if(num >= -9999 && num <= 9999)
		{
			memory[counter] = num;
			++counter;
		}
		printf("%02d?  ", counter);
		scanf("%d", &num);
	}
	puts("");
	int i;
	/*for(i = 0; i < counter; i++)
	{
		printf("%d  %d\n", i, memory[i]);
	}
	printf("counter = %d\n", counter);*/
	puts("*** Program download finished ***");
	puts("*** Start to run program ***");

	puts("");
	num = 0;
	while(num <= counter)
	{
		instructionRegister = memory[instructionCounter];
		operationCode = instructionRegister / 100;
		operand = instructionRegister % 100;

		switch(operationCode)
		{
			case 10: //read
				printf("Enter an integer: ");
				scanf("%d", &memory[operand]);
				break;

			case 11: //write
				printf("Result: %d\n\n", memory[operand]);
				break;

			case 20: //load
				accumulator = memory[operand];
				break;

			case 21: //store
				memory[operand] = accumulator;
				break;

			case 30: //add
				accumulator += memory[operand];
				break;

			case 31: //subtract
				accumulator -= memory[operand];
				break;

			case 32: //divide
				accumulator /= memory[operand];
				break;

			case 33: //multiply
				accumulator *= memory[operand];
				break;

			case 40: //branch
				instructionCounter = operand;
				break;

			case 41: //branchneg
				if(accumulator < 0)
					instructionCounter = operand;
				break;

			case 42: //branchzero
				if(accumulator == 0)
					instructionCounter = operand;
				break;

			case 43: //halt
				puts("*** Simpletron finished calculations ***");
				break;

			default:
				break;
		}
		if(num != counter)
		{
			++instructionCounter;
		}
		++num;
	}

	puts("");
	printf("REGISTERS:\n");
	printf("%-20s%12d\n", "accumulator", accumulator);
	printf("%-20s%12d\n", "instructionCounter", instructionCounter);
	printf("%-20s%12d\n", "instructionRegister", instructionRegister);
	printf("%-20s%12d\n", "operationCode", operationCode);
	printf("%-20s%12d\n", "operand", operand);

	puts("");
	printf("MEMORY:\n");
	printf("%8d%6d%6d%6d%6d%6d%6d%6d%6d%6d\n", 0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
	for(i = 0; i < 100; i++)
	{
		if(i % 10 == 0)
		{
			puts("");
			printf("%2d", i);
		}
		printf(" %+05d", memory[i]);
	}
	puts("\n");

	return 0;
}
