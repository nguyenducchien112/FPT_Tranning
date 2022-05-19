#include<iostream>

using namespace std;

float plus(float a, float b); // plus 2 numbers.
float minus(float a, float b); // subtract 2 numbers.
float multiply(float a, float b); // multiply 2 numbers.
float divide(float a, float b); // divide 2 numbers.
void operation(float a, float b, float (*p2Func)(float, float)); // p2Func is a function pointer.

float plus(float a, float b)
{
	return a + b;
}

float minus(float a, float b)
{
	return a - b;
}

float multiply(float a, float b)
{
	return a * b;
}

float divide(float a, float b)
{
	if (b != 0)
	{
		return a / b;
	}
	else
	{
		return 0;
	}
}

void operation(float a, float b, float (*p2Func)(float, float))
{
	float EX = p2Func(a, b);
	cout << EX << endl;
}

int main()
{
	float a, b;
	char select;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "select : ";
	cin >> select;

	switch (select)
	{
	case '+':
		cout << "plus 2 numbers : ";
		operation(a, b, &::plus);
		break;
	case '-':
		cout << "subtract 2 numbers : ";
		operation(a, b, &::minus);
		break;
	case '*':
		cout << " multiply 2 numbers : ";
		operation(a, b, &multiply);
		break;
	case '/':
		cout << "divide 2 numbers : ";
		operation(a, b, &divide);
		break;
	default:
		break;
	}
	return 0;
}