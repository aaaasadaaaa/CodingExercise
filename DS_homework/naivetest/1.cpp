#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cmath>
int priority_queue();
int pop(int);
int find_depth(int);
using namespace std;
struct node {
	int frequency;
	char name;
	string code;
	node * left_child;
	node * right_child;
	node * parent;
	string leaf;

};
struct node queue[256];
struct node leaf_node[256];
struct node container[511];
struct node container2[511];
struct node heap[511];
node empty;
empty.left_child = &empty;
empty.right_child = &empty;
int main(int argc, char const *argv[]) {
	int num_of_node = priority_queue();
	int num_of_leafnode = num_of_node;
    int order = 0;
    int num = num_of_node;
    node u;
    while (num_of_node != 1) {
		container[2 * order] = queue[0];
		container[2 * order + 1] = queue[1];
		queue[num_of_node].frequency = container[2 * order].frequency + container[2 * order + 1].frequency;
		container2[order] = queue[num_of_node];
		queue[num_of_node].left_child = &container[2 * order];
		queue[num_of_node].right_child = &container[2 * order + 1];
		container[2 * order + 1].parent = &container2[order];
		container[2 * order].parent = &container2[order]
		num_of_node = pop(num_of_node);
		order += 1;
		for (int i = 1; i < num_of_node; i++) {
			if (queue[num_of_node - i].frequency < queue[num_of_node - i - 1].frequency) {
				u = queue[num_of_node - i];
				queue[num_of_node - i] = queue[num_of_node - i - 1];
				queue[num_of_node - i - 1] = u;
			}
			else
				break;
		}
		num += 1;
	}
	queue[0].leaf = "root";
	heap[1] = queue[0];
	heap[1].code = "0";
    int num_ = pow(2,find_depth(num_of_leafnode)) ;
	for (int i = 1; i < num_; i++) {
		heap[2 * i] = *heap[i].left_child;
		heap[2 * i].code = heap[i].code + "0";
		heap[2 * i + 1] = *heap[i].right_child;
		heap[2 * i + 1].code = heap[i].code + "1";
	}
	for (int i = 1; i <= num; i++){
		cout << "heap" << " " << heap[i].name << " " << heap[i].frequency << endl;
	}
	int k = 0;
	int num__ = pow(2,ceil(log10(num) / log10(2)));
    cout << num__ << endl;
	for (int i = 0; i < num__; i++) {
        cout << heap[i].name <<endl;
		if (heap[i].leaf == "leaf" && heap[i].frequency != 0) {
			leaf_node[k] = heap[i];
			k += 1;
		}
	}
}
int find_depth(int leafnode){
	int i = 0;
	int count1 = 0;
	int count2 = 0;
	node k;
	while (leafnode > 0){
		if (container[i].leaf == "leaf"){
			k = container[i];
			while (k.leaf != "root"){
				k = *k.parent;
				count2 += 1;
			}
			if (count2 > count1)
				count1 = count2;
			count2 = 0;
		}
	}
}
int priority_queue(){
    char info[256];
    int freq[256];
    char in = getchar();
    int num_of_info = 0;
    int symb = 0;
    while (in != EOF){
        if (num_of_info == 0){
            info[0] = in;
            freq[0] = 1;
            num_of_info += 1;
        }
        else{
            for (int i = 0; i < num_of_info; i++){
                if (in == info[i]){
                    freq[i] += 1;
                    symb = 1;
					break;
                }
            }
            if (symb == 0){
                info[num_of_info] = in;
                freq[num_of_info] = 1;
                num_of_info += 1;
            }
            symb = 0;
        }
        in = getchar();
    }
    int k;
	char j;
	for (int w = 1; w < num_of_info; w++) {
		for (int i = 0; i < num_of_info - w; i++) {
			if (freq[i] >= freq[i + 1]) {
				if (freq[i] > freq[i + 1] || info[i] > info[i + 1]) {
					k = freq[i];
					freq[i] = freq[i + 1];
					freq[i + 1] = k;
					j = info[i];
					info[i] = info[i + 1];
					info[i + 1] = j;
				}
			}
		}
	}
	for (int i = 0; i < num_of_info; i++) {
		queue[i].name = info[i];
		queue[i].frequency = freq[i];
		queue[i].left_child = &empty;
		queue[i].right_child = &empty;
		queue[i].leaf = "leaf";
        cout << queue[i].name << " " << queue[i].frequency << " " << queue[i].leaf << endl;
	}
    return num_of_info;
}
int pop(int num) {
	for (int i = 0; i < num ; i++) {
		queue[i] = queue[i + 2];
	}
	return num - 1;
}