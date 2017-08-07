#include <string>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

struct node {
	int hash_code;
	string name = "";
	int frequency = 1;
	bool del = false;
};

struct element {
	node elem;
	element * next = NULL;
};

string input(const char*);
int count_stop_word(string);
int count_word(string);
void get_key(string, string, node);
int append_value(int, int);
int decide_length(int, int, int);
void append_table(node, element);
int get_freq(int, node);
int get_length(int, node, int,int,int);
void append_element(element, element,int);
void output(element,int);
int hash_value(string,int);
int ten_two(int);
int two_ten(int);
void split(string,string);
void get_key(string, string, node,int,int);
void print(element);

int main(int argc, char const *argv[]) {
	int load_factor = 1; 
	int length = 1;
	string stop;
	string word;
	for (int i = 1; i < argc; i = i + 2) {
		if (argv[i] == "-f")
			load_factor = atoi(argv[i + 1]);
		if (argv[i] == "-l")
			length = atoi(argv[i + 1]);
		if (argv[i] == "-s")
			stop = input(argv[i + 1]);
		if (argv[i] == "-w")
			word = input(argv[i + 1]);
	}
	int num_stop = count_word(stop);
	int num_word = count_word(word);
	node *key;
	int *value;
	string * stop_word;
	string * key_word;
	stop_word = new string[num_stop];
	split(stop, *stop_word);
	key_word = new string[num_word];
	split(word, *key_word);
	key = new node[num_word - num_stop];
	value = new int[num_word - num_stop];
	
	get_key(*stop_word,*key_word, *key,num_stop,num_word); //find the name and hash value for every node
	length = get_length(*value,*key, num_word - num_stop,length,load_factor);
	element * hash_table, *all_elem;
	string symb = "symbol";
	hash_table = new element[length];
	all_elem = new element[num_word = num_stop];
	for (int i = 0; i < num_word - num_stop; i++) {
		all_elem[i].elem = key[i];
	}
	append_element(*hash_table, *all_elem,num_word - num_stop);
	output(*hash_table,length);
}

string input(const char* file) {
	ifstream in(file, ios::in);
	istreambuf_iterator<char> beg(in), end;
	string strdata(beg, end);
	in.close();
	return strdata;
}

int count_word(string str) {
	int num_word = 0;
	string pre;
	string now;
	for (int i = 0; i < str.size(); i++) {
		pre = str[i - 1];
		now = str[i];
		if ((!pre.empty()) && now.empty())
			num_word += 1;
	}
	return num_word;
}

void get_key(string *stop, string *word, node *key,int num_stop,int num_word) {
	int key_pos = 0;
	for (int i = 0; i < num_word; i++) {
		int symb = 0;
		for (int j = 0; j < num_stop; j++) {
			if (word[i] == stop[j]) {
				symb = 1;
				break;
			}
		}
		if (symb == 0) {
			key[key_pos].name = word[i];
			key_pos += 1;
		}
	}
}
int get_length(int *value, node *key, int num,int length,int load_factor) {
	int num_value = 0;
	int key_num = 0;

	while (key_num != num){
		key[key_num].hash_code = hash_value(key[key_num].name,length);
		int symb = 0;
		for (int i = 0; i < num_value; i++) {
			if (key[key_num].hash_code = value[i])
				symb = 1;
		}
		if (symb == 0) {
			value[num_value] = key[key_num].hash_code;
			num_value += 1;
		}
		if (num_value < load_factor * length) {
			length = 2 * length + 1;
			num_value = 0;
			key_num = 0;
		}
	}

}
void append_element(element *hash_table, element *key ,int num_key) {
	for (int i = 0; i < num_key; i++) {
		if (key[i].elem.del == false) {
			element h = hash_table[key[i].elem.hash_code];
			while (h.next != NULL) {
				h = *h.next;
			}
			h.next =  &key[i];
			for (int j = i; j < num_key; j++) {
				if (key[j].elem.name == key[i].elem.name) {
					key[j].elem.del = true;
					key[i].elem.frequency += 1;
				}

			}
		}
	}
}
void output(element *hash_table,int length) {
	cout << "[" << endl;
	for (int i = 0; i < length; i++) {
		if (hash_table[i].next == NULL)
			cout << "{}" << endl;
		else
			print(hash_table[i]);
		if (i != length - 1) 
			cout << ",";
		cout << endl;
	}
	cout << "]" << endl;
}
void print(element h) {
	cout << "{";
	if (h.next == NULL)
		cout << "\"" << h.elem.name << "\":" << h.elem.frequency << ",";
	else {
		print(*h.next);
		if (h.elem.name != "")
			cout << "\"" << h.elem.name << "\":" << h.elem.frequency << ",";
	}
	cout << "}";
	
}
int hash_value(string word,int length) {
	try {
		int num = atoi(word.c_str());
		return num % length;
	}
	catch (...) {
		string * weight;
		weight = new string[word.size()];
		string multibyte;
		char con[8];
		for (int i = 0; i < word.size(); i++) {
			sprintf(con,"%8d", ten_two(int(word[i])));
			weight[i] = con;
			multibyte += weight[i];
		}
		return two_ten(atoi(multibyte.c_str())) % length;
	}
}
int ten_two(int x) {
	int w = x;
	int y = 0;
	int r = 0;
	while (w != 0) {
		y = w % 2;
		r = r * 10 + y;
		w = w / 2;
	}
	return r;
}
int two_ten(int t) {
	int w = t;
	int y = 0;
	int r = 0;
	int i = 0;
	while (w != 0){
		y = w % 10;
		r = r + y * pow(2, i);
		w = w / 10;
		i += 1;
	}
	return r;
}

