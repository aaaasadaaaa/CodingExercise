#include <stdio.h>
#include <ctype.h>
void input(int, int*, int*, char*);
int main(){

    char container[100];
    int num_node;
    int inorder[10000];
    int postorder[10000];
    input(num_node, inorder, postorder,container);


}

void input(int num_node, int * inorder, int * postorder){
    int num = 0;
    int order = 0;
    char a;
    while(num != 3){
        a = getchar();
        if(isdigit(a)){
            container[order] = a;
            order++
        }
        if(num == 0){
            if(a == " " || a = "\n"){
                num_node = atoi(container)
                for()

            }

        }
        if(a == ' '){

            order = 0;
        }
    }
}
