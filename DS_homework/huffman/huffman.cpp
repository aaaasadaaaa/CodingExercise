#include <cstdlib>
#include <cstdio>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;
char info[128];
int freq[128];
int pop(int);
int get_freq(string);

void priority_queue(int);

struct node {
	int frequency;
	string name;
	string code;
	node * left_child;
	node * right_child;
	string leaf;
};
struct node queue[80];
struct node container[160];
struct node heap[160];
struct node leaf_node[160];
node empty;
int order = 0;
int main() {
	string text;
	getline(cin, text);
	int num_of_node = get_freq(text);
	priority_queue(num_of_node);
	for (int i = 0; i < num_of_node; i++){
		cout << "node " << i << " " << queue[i].name << " " << queue[i].frequency <<endl;
	}
	int num = num_of_node;
	node u ;
	while (num_of_node != 1) {
		container[2 * order] = queue[0];
		container[2 * order + 1] = queue[1];
		queue[num_of_node].frequency = container[2 * order].frequency + container[2 * order + 1].frequency;
		queue[num_of_node].name = "temp";
		queue[num_of_node].left_child = &container[2 * order];
		queue[num_of_node].right_child = &container[2 * order + 1];
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
	heap[1] = queue[0];
	heap[1].code = "0";

	int num_ = pow(2,floor(log10(num) / log10(2))) ;
	cout << num_ << endl;
	for (int i = 1; i < num_; i++) {
		heap[2 * i] = *heap[i].left_child;
		heap[2 * i].code = heap[i].code + "0";
		heap[2 * i + 1] = *heap[i].right_child;
		heap[2 * i + 1].code = heap[i].code + "1";
		for (int k = 1; k <= 2 * i + 1; k++){
			cout << heap[k].name << " " << heap[k].frequency << endl;
		}
		cout << i << endl;
		cout << endl;
	}
	int k = 0;
	int num__ = pow(2,ceil(log10(num) / log10(2)));
	for (int i = 0; i < num__; i++) {
		if (heap[i].leaf == "leaf") {
			leaf_node[k] = heap[i];
			cout << heap[i].name << " " << heap[i].code << endl; 
			k += 1;
		}
	}

	

}
int pop(int num) {
	for (int i = 0; i < num ; i++) {
		queue[i] = queue[i + 2];
	}
	return num - 1;
}
void priority_queue(int num_of_node) {
	int k;
	char j;
	for (int w = 1; w < num_of_node; w++) {
		for (int i = 0; i < num_of_node - w; i++) {
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
	for (int i = 0; i < num_of_node; i++) {
		queue[i].name = info[i];
		queue[i].frequency = freq[i];
		queue[i].left_child = &empty;
		queue[i].right_child = &empty;
		queue[i].leaf = "leaf";
	}
}


int get_freq(string text) {
	int num_of_info = 0;
	int symb = 0;
	for (int i = 0; i < text.size(); i++) {
		if (num_of_info == 0) {
			info[0] = text[i];
			freq[0] = 1;
			num_of_info += 1;
		}
		else {
			for (int j = 0; j <= num_of_info - 1; j++) {
				if (text[i] == info[j]) {
					freq[j] += 1;
					symb = 1;
					break;
				}
			}
			if (symb == 0) {
				info[num_of_info] = text[i];
				freq[num_of_info] = 1;
				num_of_info += 1;
			}
			symb = 0;
		}
	}
	return num_of_info;
 
}
