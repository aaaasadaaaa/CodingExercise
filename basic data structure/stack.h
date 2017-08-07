#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack{
private:
    T * array;
    int Top_of_stack;
    int max_length;
public:
    Stack();
    Stack(int);

    ~Stack();
    int length();
    bool IsEmpty();
    bool IsFull();
    void push(T element);
    void pop();
    T top();
    T Top_and_pop();

};
#include "stack.hpp"
#endif
