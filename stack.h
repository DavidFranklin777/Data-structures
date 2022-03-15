#ifndef STACK_H
#define STACK_H

#include<iostream>

using namespace std;

class Stack
{
public:
    int totalSize;
    int *stackArray;
    int top;            // element pointing to the top, we initialize it with -1 to indicate that the stack is empty

    Stack(int size):
        totalSize(size),
        top(-1)
    {
        stackArray = new int[totalSize];
    }

    bool isEmpty()
    {
        return (top == -1);
    }

    bool isFull()
    {
        return (top == totalSize -1);
    }

    void push(int data)
    {
        if(isFull())
        {
            cout << "Stack is full. Please resize before you insert any elements!\n";
        }
        else
        {
            stackArray[++top] = data;
        }
    }

    int pop()
    {
        if(isEmpty())
        {
            cout << "Stack is empty\n";
            return -1;
        }

        else
        {
            return stackArray[--top];
        }
    }

    int peek()
    {
        if (isEmpty())
        {  cout << "Stack is empty\n";
            return -1;
        }
        else
            return stackArray[top];
    }

    void resize(int newSize)
    {
        if (newSize>totalSize)
        {
            totalSize = newSize;
            int *temp = new int[newSize];
            for (int i =0; i<newSize; i++)
            {
                temp[i] = stackArray[i];
            }
            delete stackArray;
            stackArray = temp;
        }
    }

    void printStack()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
        }
        else
        {
            for (int i=0; i<=top; i++)
            {
                cout << stackArray[i] << " ";
            }
            cout << endl;
        }

    }

    ~Stack()
    {
        delete stackArray;
    }
};

#endif // STACK_H
