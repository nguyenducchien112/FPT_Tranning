#include <iostream>
#include <string>
using namespace std;

#define SIZE 100

template <class T>
class Stack
{
private:
    int top;
    T st[SIZE];
public:
    Stack();
    void push(T x);
    T pop();
};


template <class T>
Stack<T>::Stack()
{
    top = -1;
}

template <class T>
void Stack<T>::push(T x)
{
    cout << "Insert data " << x << endl;
    st[++top] = x;
}

template <class T>
T Stack<T>::pop()
{
    return st[top--];
}

int main()
{
    Stack<int> interger_stack;
    Stack<string> s_stack;

    interger_stack.push(23);
    interger_stack.push(6);
    interger_stack.push(2022);

    s_stack.push("ChienND7 ");
    s_stack.push("GAM.PDC ");

    cout << interger_stack.pop() << " removed from the stack" << endl;

    cout << s_stack.pop() << "removed from the stack" << endl;

    return 0;
}