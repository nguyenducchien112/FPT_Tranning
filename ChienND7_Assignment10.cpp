#include<iostream>
using namespace std;

class String
{
public:
	char* str;
	//String();
	friend String operator + (const String&, const String&);
	friend ostream& operator << (ostream&, String&);
	friend istream& operator >> (istream&, String&);
};
String operator+ (const String& string1, const String& string2)
{
	int i, j = 0 ,x1,x2;
	x1 = strlen(string1.str);
	x2 = strlen(string2.str);
	for (i = x1; i < x1 + x2; i++) 
	{
		string1.str[i] = string2.str[j];
		j++;
	}
	string1.str[i] = '\0';

	return string1;
}
istream& operator >> (istream& is, String& str_obj)
{
	str_obj.str = new char[100];
	is >> str_obj.str;
	return is;
}
ostream& operator << (ostream& os, String& str_obj)
{
	os << str_obj.str;
	return os;
}

int main() {
	String string1, string2, str;
	cout << "input String 1 : ";
	cin >> string1;
	cout << "Input string 2 : ";
	cin >> string2;

	str = string1 + string2;
	cout << str;

	return 0;
}