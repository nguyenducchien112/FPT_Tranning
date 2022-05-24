#include<iostream>
#include <assert.h>

using namespace std;

class CFraction
{
private:
	int num;
	int den;
public:
	CFraction();
	CFraction(int, int);
	void input(CFraction& m_CFraction);
	void output(CFraction m_CFraction);
	void print();
	friend CFraction operator+ (const CFraction&, const CFraction&);
	friend CFraction operator- (const CFraction&, const CFraction&);
	friend CFraction operator* (const CFraction&, const CFraction&);
	friend CFraction operator/ (const CFraction&, const CFraction&);
};

CFraction::CFraction()
{
	this->num = 0;
	this->den = 0;
}

CFraction::CFraction(int num, int den)
{
	this->num = num;
	this->den = den;
}

void CFraction::input(CFraction& m_CFraction)
{
	cout << "num : ";
	cin >> m_CFraction.num;
	cout << "den : ";
	cin >> m_CFraction.den;
}

void CFraction::output(CFraction m_CFraction)
{
	cout << "return : " << m_CFraction.num << "/" << m_CFraction.den << endl;
}
/******************************************************
Function : operator+
Input : 2 Fraction
output : plus 2 Fraction
******************************************************/
CFraction operator+ (const CFraction& CFraction1, const CFraction& CFraction2)
{
	assert(CFraction1.den != 0);
	assert(CFraction2.den != 0);
	CFraction CFraction3;
	CFraction3.num = CFraction1.num * CFraction2.den + CFraction1.den * CFraction2.num;
	CFraction3.den = CFraction1.den * CFraction2.den;
	return CFraction3;
}
/******************************************************
Function : operator-
Input : 2 Fraction
output : Subtraction 2 Fraction
******************************************************/
CFraction operator- (const CFraction& CFraction1, const CFraction& CFraction2)
{
	assert(CFraction1.den != 0);
	assert(CFraction2.den != 0);
	CFraction CFraction3;
	CFraction3.num = CFraction1.num * CFraction2.den - CFraction1.den * CFraction2.num;
	CFraction3.den = CFraction1.den * CFraction2.den;
	return CFraction3;
}
/******************************************************
Function : operator*
Input : 2 Fraction
output : multiply 2 Fraction
******************************************************/
CFraction operator* (const CFraction& CFraction1, const CFraction& CFraction2)
{
	assert(CFraction1.den != 0);
	assert(CFraction2.den != 0);
	CFraction CFraction3;
	CFraction3.num = CFraction1.num * CFraction2.num;
	CFraction3.den = CFraction1.den * CFraction2.den;
	return CFraction3;
}
/******************************************************
Function : operator/
Input : 2 Fraction
output : division 2 Fraction
******************************************************/
CFraction operator/ (const CFraction& CFraction1, const CFraction& CFraction2)
{
	assert(CFraction1.den != 0);
	assert(CFraction2.den != 0);
	CFraction CFraction3;
	CFraction3.num = CFraction1.num * CFraction2.den;
	CFraction3.den = CFraction1.den * CFraction2.num;
	return CFraction3;
}

int main()
{
	CFraction x, y;
	cout << "Fraction 1 : " << endl;
	x.input(x);
	cout << "Fraction 2 : " << endl;
	y.input(y);
	cout << "===================out put===================" << endl;
	cout << "plus 2 Fraction : " << endl;
	CFraction plus = x + y;
	plus.output(plus);

	cout << "minus 2 Fraction : " << endl;
	CFraction minus = x - y;
	minus.output(minus);

	cout << "multiply 2 Fraction : " << endl;
	CFraction multiply = x * y;
	multiply.output(multiply);

	cout << "divide 2 Fraction : " << endl;
	CFraction divide = x / y;
	divide.output(divide);

	return 0;
}