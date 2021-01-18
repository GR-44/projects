#ifndef CALCULATOR_H
#define CALCULATOR_H

double plus(double a);
double minus(double a);
double multiply(double a);
double divide(double a);

double plus(double a)
{
    double num1, total = 0;
    char symbol = 0;

    scanf("%lf", &num1);
    total = a + num1;
    scanf("%c", &symbol);
    while(symbol == '+')
    {
    	num1 = 0;
		scanf("%lf", &num1);
		total = total + num1;
		scanf("%c", &symbol);
	}
	if(symbol == 13 || symbol == 10)
        return total;
	if(symbol == '-')
        total = minus(total);
	if(symbol == '*')
        total = multiply(total);
	if(symbol == '/')
        total = divide(total);

	return total;
}

double minus(double a)
{
    double num1, total = 0;
    char symbol;

    scanf("%lf", &num1);
    total = a - num1;
    scanf("%c", &symbol);
    while(symbol == '-')
    {
    	num1 = 0;
		scanf("%lf", &num1);
		if(num1 >= 0)
            total = total - num1;
		else
            total = total - num1;
		scanf("%c", &symbol);
	}
	if(symbol == 13 || symbol == 10)
        return total;
	if(symbol == '+')
        total = plus(total);
	if(symbol == '*')
        total = multiply(total);
	if(symbol == '/')
        total = divide(total);

	return total;
}

double multiply(double a)
{
    double num1, total = 0;
    char symbol;

    scanf("%lf", &num1);
    total = a * num1;
    scanf("%c", &symbol);
    while(symbol == '*')
    {
    	num1 = 0;
		scanf("%lf", &num1);
		total = total * num1;
		scanf("%c", &symbol);
	}
	if(symbol == 13 || symbol == 10)
        return total;
	if(symbol == '-')
        total = minus(total);
	if(symbol == '+')
        total = plus(total);
	if(symbol == '/')
        total = divide(total);

	return total;
}

double divide(double a)
{
    double num1, total = 0;
    char symbol;

    scanf("%lf", &num1);
    if(num1 == 0)
        puts("division by zero");
    else
        total = a / num1;

    scanf("%c", &symbol);
    while(symbol == '/')
    {
    	num1 = 0;
		scanf("%lf", &num1);
		if(num1 == 0)
            puts("division by zero");
        else
            total = a / num1;

		scanf("%c", &symbol);
	}
	if(symbol == 13 || symbol == 10)
        return total;
	if(symbol == '-')
        total = minus(total);
	if(symbol == '+')
        total = plus(total);
	if(symbol == '*')
        total = multiply(total);

	return total;
}

#endif
