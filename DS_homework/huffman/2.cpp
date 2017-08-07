#include <cstdlib>
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
char info[128];
int freq[128];

int get_freq(string);
void priority_queue(int);

struct node {
	int frequency;
	string name;
	node * left_p;
	node * right_p;
};
struct node queue[128];
int main() {
	string text;
	getline(cin, text);
	int num_of_node = get_freq(text);
	priority_queue(num_of_node);
	for (int i = 0; i < num_of_node; i++){
		cout << queue[i].name << "  " << queue[i].frequency << endl;
	}

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
