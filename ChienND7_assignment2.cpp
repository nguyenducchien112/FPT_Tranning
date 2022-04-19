#include<math.h>
#include<iostream>
using namespace std;

int main()
{
    int n, j, i, k;
    cin >> n;
    n = (n / 2) * 2 + 1;//cho n luon la so le
    int space = n / 2, dausao = 1;
    for (i = 1; i <= (n / 2 + 1); i++)
    {
        for (j = 1; j <= space; j++)cout << " ";
        for (k = 1; k <= dausao; k++)cout << "*";
        cout << endl;
        space--; dausao += 2;
    }
    space = 1; dausao = n - 2;

    for (i = 1; i <= (n / 2 + 1); i++)
    {
        for (j = 1; j <= space; j++)cout << " ";
        for (k = 1; k <= dausao; k++)cout << "*";
        cout << endl;
        space++; dausao -= 2;
    }
    return 0;
}