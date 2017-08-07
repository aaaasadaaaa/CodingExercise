#include <string>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
using namespace std;

struct node {
	int hash_code;
	string name = "";
	int frequency = 1;
	bool del = false;
	bool extra = false;
};

struct element {
	node elem;
	element * next = NULL;
};

string input(const char*);
int count_stop_word(string);
int count_word(string);
void get_key(string, string, node);
//int append_value(int, int);
//int decide_length(int, int, int);
void append_table(node, element);
//int get_freq(int, node);
int get_length(string *, node *, int,int,int);
void append_element(element *, element *, int);
void output(element *,int);
int hash_value(string,int);
int ten_two(int);
int two_ten(int);
void split(string,string*);
void get_key(string *, node *,int,int);
void print(element);
bool empty(string);
bool int_or_str(string);
int mod (int,int,int);

bool int_or_str(string str){
	char *c = new char[str.size()];
	strcpy(c,str.c_str());
	for (int i = 0; i < str.size(); i++){
		if (int(c[i]) > 57 || int(c[i] < 48)){
			//cout << "str" << endl;
			return false;
		}
	}
	return true;
}

bool empty(string x){
	if (x == "\n"|| x == "\r" || x == " " || x == "\t" )
		return true;
	else
		return false;
}
void output(struct element * hash_table, int length){
	cout << "[" << endl;
	for (int i = 0; i < length; i++) {
		if (hash_table[i].next == NULL){
			cout << "{}";
			if (i != length - 1)
				cout << "," ;
			cout << endl;
		}
		else{
			cout << "{";
			print(hash_table[i]);
		//if (i != length - 1)
			cout << "}";
			if (i != length - 1)
				cout << "," ;
			cout << endl;
		}
	}
	cout << "]" << endl;
}

int main(int argc, char const *argv[]) {
	int load_factor = 1; 
	int length = 1;
	string stop;
	string word;
	for (int i = 1; i < argc; i = i + 2) {
		//cout << argv[i] << endl;
		const char a[] = "-f";
		const char b[] = "-s";
		const char c[] = "-l";
		const char d[] = "-w";
		if (strcmp(a,argv[i]) == 0)
			load_factor = atoi(argv[i + 1]);
		if (strcmp(c,argv[i]) == 0)
			length = atoi(argv[i + 1]);
		if (strcmp(b,argv[i]) == 0)
			stop = input(argv[i + 1]);
		if (strcmp(d,argv[i]) == 0)
			word = input(argv[i + 1]);
	}

	int num_stop = count_word(stop);
	int num_word = count_word(word);
	int diff = num_word - num_stop;
	node *key;
	string *value;
	string * stop_word;
	string * key_word;
	//cout << 1 << endl;
	stop_word = new string[num_stop];
	split(stop, stop_word);
	key_word = new string[num_word];
	split(word, key_word);
	key = new node[num_word];
	value = new string[num_word];
	for (int i = 0; i < num_word; i++){
		key[i].name = key_word[i];
		for (int j = 0; j < num_stop; j++){
			if (key_word[i] == stop_word[j])
				key[i].del = true;
		}
	}
	
	//get_key(key_word, key,num_stop,num_word); //find the name and hash value for every node
	//cout << length << endl;
	length = get_length(value,key,num_word,length,load_factor);
	//cout << "length = " << length << endl;
	element * hash_table, *all_elem;
	string symb = "symbol";
	hash_table = new element[length];
	all_elem = new element[num_word];
	for (int i = 0; i < num_word; i++) {
		all_elem[i].elem = key[i];
	}
	append_element(hash_table, all_elem, num_word);
	//for (int i = 0; i < length; i++){
	//	cout << all_elem[i].elem.name << " " << all_elem[i].elem.hash_code <<endl;
	//}
	output(hash_table,length);
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
	for (int i = 1; i < str.size(); i++) {
		pre = str[i - 1];
		now = str[i];
		if ((!empty(pre)) && empty(now)){
			num_word = num_word + 1;
		}
	}
	return num_word;
}

void get_key(string *word, node *key,int num_stop,int num_word) {
	int key_pos = 0;
	for (int i = 0; i < num_word; i++) {
			key[key_pos].name = word[i];
			key_pos += 1;
	}
}
int get_length(string *value, node *key, int num,int length,int load_factor) {
	int num_value = 0;
	int key_num = 0;

	while (key_num != num){
		//cout << key[key_num].name << endl;
		//cout << length << endl;
		key[key_num].hash_code = hash_value(key[key_num].name,length);
		//cout << length << " ";
		//cout << key[key_num].name << " " << key[key_num].hash_code;
		int symb = 0;
		for (int i = 0; i < num_value; i++) {
			//cout << key[key_num].hash_code << " " << value[i] << endl;
			if (key[key_num].name == value[i]){
				symb = 1;
			}
		}
		//cout << "symb" << " " << symb << endl;
		if (symb == 0) {
			value[num_value] = key[key_num].name;
			num_value += 1;
		}
		//cout << " " << num_value << endl;
		key_num += 1;
		//cout << num_value << " " << load_factor << " " << length << endl;
		if (num_value * 100 >= load_factor * length) {
			//cout << key[key_num].name << endl;
			key[key_num].extra = true;
			length = 2 * length + 1;
			for (int i = 0; i < num_value; i++){
				value[i] = "";
			}
			num_value = 0;
			key_num = 0;
		}
	}
	return length;
}
void append_element(element *hash_table, element *key ,int num_key) {
	for (int i = 0; i < num_key; i++){
		if (key[i].elem.extra == true){
			//cout << 1 << endl;
			hash_table[key[i].elem.hash_code].next = &key[i];
			key[i].elem.del = true;
		}
	}
	for (int i = 0; i < num_key; i++) {
		if (key[i].elem.del == false) {
			//cout << 1 << endl;
			element *h;
			h = &hash_table[key[i].elem.hash_code];
			//cout << 1 << endl;
			//cout << *h.elem.name << endl;
			while (h->next != NULL) {
				//cout << 1 << endl;
				h = h->next;
				//cout << 1 << endl;
				//cout << h.elem.name << endl;
			}
			//cout << 1 << endl;
			h->next = &key[i];
			//cout << 1 << endl;
			for (int j = i + 1; j < num_key; j++) {
				if (key[j].elem.name == key[i].elem.name) {
					key[j].elem.del = true;
					key[i].elem.frequency += 1;
				}

			}
		}
	}
}
/*void output(element *hash_table, int length){
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
}*/
void split(string word, string * word_) {
	int num_word = 0;
	string next;
	string now;
	string container;
	int symb = 1;
	for (int i = 0; i < word.size() - 1; i++) {
		now = word[i];
		next = word[i + 1];
		if (!empty(now))
			symb = 1;
		if (symb == 1)
			container += now;
		if ((!empty(now)) && empty(next)) {
			word_[num_word] = container;
			num_word += 1;
			container = "";
			symb = 0;
		}
	}
}
void print(element h) {
	//cout << "{";
	if (h.next == NULL)
		cout << "\"" << h.elem.name << "\":" << h.elem.frequency ;
	else {
		print(*h.next);
		if (h.elem.name != "")
			cout << "," <<  "\"" << h.elem.name << "\":" << h.elem.frequency ;
	}
	//cout << "},";
}
/*void output(element *hash_table, int length){
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
}*/


int hash_value(string word,int length) {
	if (int_or_str(word))
		return atoi(word.c_str()) % length;
	else{
		char *byte = new char[word.size()];
		strcpy(byte,word.c_str());
		int sum = 0;
		for (int i = 0; i < word.size();i++){
			//cout << int(byte[i]) << " " << mod(int(byte[i]),word.size() - 1 - i,length) << endl;
			sum += mod(int(byte[i]),word.size() - 1 - i,length);
		}
		//cout << sum << endl;
		return sum % length;
		/*string * weight;
		weight = new string[word.size()];
		string multibyte;
		char con[8];
		for (int i = 0; i < word.size(); i++) {
			sprintf(con,"%d", ten_two(int(word[i])));
			//cout << con << endl;
			weight[i] = con;
			while (weight[i].size() != 8)
				weight[i] = "0" + weight[i];
			multibyte += weight[i];
			//cout << multibyte << endl;
		}
		//cout << two_ten(atoi(multibyte.c_str())) << endl;
		int k = two_ten(atoi(multibyte.c_str())) % length;
		if (k < 0)
			k = k + length;
		return k;*/
	}
}
int mod(int a,int time,int length){
	int x = a;
	if (time == 0)
		return x % length;
	for (int i = 0; i < time; i++){
		x = (x % length * 256) % length;
	}
	return x;
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

