#include<iostream>
using namespace std;

int* get_even_num(int* arr, int* sz){
    int size = *sz = *arr,chiso = 0;
    int* p = new int[*sz];
    for (int i = 0; i < size; i++)
    {
        if (*(arr + i) % 2 == 0)
        {
            *(p + chiso) = *(arr + i);
            chiso++;
        }
        else
        {
        	(*sz)--;
		}
    }
    return p;
}

int main(){
    int test[] = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int sz;
    int* a = get_even_num(test, &sz);
    for (int i = 0; i < sz; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl << sz;
    return 0;
}
