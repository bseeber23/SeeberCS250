/*
    .cpp file for SpecialStack
    Braden Seeber
    11/24/24
*/
#include "SpecialStack.h"
#include <stack>
#include <iostream>
using namespace std;

SpecialStack::SpecialStack()
{
    //ctor
}

void SpecialStack::push(int value)
{
    stack.push(value);//pushes value on stack
}

void SpecialStack::pop()
{
    if (stack.empty()) {
        throw 1; //error, cant pop an empty stack
    }
    stack.pop();
}

void SpecialStack::printStack() const //print stack top to bottom
{
    if (stack.empty()) {
        cout << "Stack is empty." << endl;
        return;
    }

    std::stack<int> temp = stack;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
}

void SpecialStack::popOdd()//remove latest added odd number
{
    if (stack.empty()) {
        throw 1;//error
    }

    std::stack<int> temp;
    bool found = false;

    while (!stack.empty()) {
        if (!found && stack.top() % 2 != 0) {//checks for odd number
            stack.pop();
            found = true;
            break;
        }
        temp.push(stack.top());
        stack.pop();
    }

    while (!temp.empty()) { //puts elements back to main stack
        stack.push(temp.top());
        temp.pop();
    }

    if (!found) {
        throw 1;
    }
}

void SpecialStack::popEven()//pop latest even number
 {
    if (stack.empty()) {
        throw 1;
    }

    std::stack<int> temp;
    bool found = false;

    while (!stack.empty()) {
        if (!found && stack.top() % 2 == 0) {//checks for even number
            stack.pop();
            found = true;
            break;
        }
        temp.push(stack.top());
        stack.pop();
    }

    while (!temp.empty()) {
        stack.push(temp.top());
        temp.pop();
    }

    if (!found) {
        throw 1;
    }
}
