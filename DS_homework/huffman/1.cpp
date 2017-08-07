#include <cstdlib>
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
char info[128];
int freq[128];
int get_freq(string);

struct node {
	int frequency;
	string name;
	node * left_p;
	node * right_p;
};

int main() {
	string text;
	getline(cin, text);
	int num_of_node = get_freq(text);
	for (int i = 0; i < num_of_node; i++) {
		cout << info[i] << "  " << freq[i] << endl;
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