#include "stack.h"
#include <iostream>

using namespace std;
template <typename T>
Stack<T>::Stack(){
    array = new T[20];
    Top_of_stack = -1;
    max_length =  20;
}

template <typename T>
Stack<T>::Stack(int Stacksize){
    array = new T[Stacksize];
    Top_of_stack = -1;
    max_length = Stacksize;
}

template <typename T>
int Stack<T>::length(){
    return max_length;
}

template <typename T>
Stack<T>::~Stack(){
    delete array;
}

template <typename T>
bool Stack<T>::IsEmpty(){
    if (Top_of_stack == -1) return true;
    return false;
}

template <typename T>
bool Stack<T>::IsFull(){
    if (Top_of_stack == length()) return true;
    return false;
}

template <typename T>
void Stack<T>::push(T element){
    if (IsFull())
        cout << "stack is full" << endl;
    else{
        array[Top_of_stack + 1] = element;
        Top_of_stack++;
    }
}

template <typename T>
void Stack<T>::pop(){
    Top_of_stack--;
}

template <typename T>
T Stack<T>::top(){
    return array[Top_of_stack];
}

template <typename T>
T Stack<T>::Top_and_pop(){
    Top_of_stack--;
    return array[Top_of_stack + 1];
}
