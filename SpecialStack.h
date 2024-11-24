/*
    Header file for SpecialStack
    Braden Seeber
    11/24/24
*/
#ifndef SPECIALSTACK_H
#define SPECIALSTACK_H
#include <stack>
#include <iostream>
using namespace std;


class SpecialStack
{
    public:
        SpecialStack();
        void push(int value); //adds to stack
        void pop();//removes top element from stack
        int peek() const;//returns top element of stack
        bool empty() const;//checks if stack is empty
        void printStack() const;//prints stack
        void popOdd();//removes latest added odd number
        void popEven();//removes latest added even number


    protected:

    private:
        stack<int> stack;
};

#endif // SPECIALSTACK_H
