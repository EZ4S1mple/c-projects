#include "iostream"
#include <cmath>
#include <limits>
#include <map>

using namespace std;

const char quit_code = 'q';
const char reset_code = 'r';
double num1, num2, result;

char operation;
bool first_cal = true;

double addition(double a, double b)
{
	return a + b;
}

double subtraction(double a, double b)
{
	return a - b;
}

double times(double a, double b)
{
	return a * b;
}

double divide(double a, double b)
{
	return a / b;
}

double root(double a, double b = 2)
{
	return pow(a, 1.0 / b);
}

double exp(double a, double b)
{
	return pow(a, b);
}

double modula(double a, double b)
{
	return fmod(a, b);
}

double get_valid_input()
{
	double number;
	while (!(cin >> number))
	{
		cout << "Invalid input. Please enter a number: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	return number;
}

char get_valid_operation()
{
	char op;
	while (op == 'q' || op == 'r')
	{
		cin >> op;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return op;
}

void handle_quit()
{
	cout << "Exit " << "\n";
	exit(0);
}

void handle_reset()
{
	cout << " Reset " << "\n";
	result = 0;
	cin.clear();
	cout << "Please enter the first number: " << "\n";
	num1 = get_valid_input();
	result = num1;
	first_cal = true;
}

bool Is_quit(char operation)
{
	return operation == 'q';
}

bool Is_reset(char operation)
{
	return operation == 'r';
}

void handle_cal(double num1, double num2, char operation, double &result)
{
	map<char, double (*)(double, double)> operations = {
		{'+', addition},
		{'-', subtraction},
		{'*', times},
		{'/', divide},
		{'^', exp},
		{'%', modula}};
	if (operation == '/' || operation == '%' && num2 == 0)
	{

		cout << "Error: Can not divide 0." << "\n";
		num2 = get_valid_input();
		if (num2 == 0)
			return;
	}

	if (operations.find(operation) != operations.end())
	{
		result = operations[operation](num1, num2);
		cout << num1 << ' ' << operation << ' ' << num2 << " = " << result << "\n";
	}
	else
	{

		cout << "Error: Invalid operation." << "\n";
	}
}

int main()
{

	while (true)
	{
		if (first_cal)
		{
			cout << "Please enter the first number: " << "\n";
			num1 = get_valid_input();
			result = num1;
		}

		else
		{
			cout << "Current result : " << result << endl;

			num1 = result;
		}

		while (true)
		{
			cout << "Please enter the operator (q to exit or r to reset): " << "\n";
			operation = get_valid_operation();

			if (Is_quit(operation))
			{
				handle_quit();
			}
			else if (Is_reset(operation))
			{
				handle_reset();
				break;
			}

			cout << "Please enter the second number: " << "\n";
			num2 = get_valid_input();

			handle_cal(num1, num2, operation, result);
			first_cal = false;
			break;
		}
	}

	return 0;
}
