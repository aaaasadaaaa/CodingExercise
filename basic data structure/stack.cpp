#include "stack.h"
#include <iostream>

using namespace std;
int main(){
    Stack<int> stack;
    int num[] = {1 , 2 , 3 , 4 , 5 , 6 , 7,8,9,8,7,6,5,4,3,2,1,2,3,4,5,6};
    for (int i = 0; i < sizeof(num)/sizeof(int); i++){
        stack.push(num[i]);
    }
    /*while (!stack.IsEmpty()){
        cout << stack.top() << endl;
        stack.pop();
    }*/
    while (!stack.IsEmpty()){
        cout << stack.Top_and_pop() << endl;
    }
}
