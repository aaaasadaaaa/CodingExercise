#include <iostream>
#include <string>

using namespace std;

string input(void);
int count_word(string);
string catch_word(string);
void split(int*, string);

int main() {
	string data = input();
	cout << data << endl;
	int num = count_word(data);
	int * info;
	info = new int[num];
	split(info,data);
	int **graph;
	graph = new int *[info[0]];
	for (int i = 0; i < info[0]; i++) {
		graph[i] = new int [info[0]];
	}
	for (int i = 0; i < info[0]; i++) {
		for (int j = 0; j < info[0]; j++) {
			graph[i][j] = 0;
		}
	}
	for (int i = 1; i < num; i = i + 3) {
		if (graph[info[i + 1]][info[i + 2]] > info[i + 3] || graph[info[i + 1]][info[i + 2]] == 0){
			graph[info[i + 1]][info[i + 2]] = info[i + 3];
			graph[info[i + 2]][info[i + 1]] = info[i + 3];
		}
	}
	for (int i = 0; i < info[0]; i++) {
		for (int j = 0; j < info[0]; j++) {
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
	
}

string input(void) {
	int symb = 1000;
	int num_elem = 0;
	int num = 0;
	string strdata = "";
	string con = "";
	int swit = 0;
	while (num_elem < symb) {
		getline(cin, con);
		int n = count_word(con);
		num_elem += n;
		strdata = strdata + " " + con + " ";
		if (num_elem >= 2 && swit == 0) {
			symb = 2 + 3 * atoi(catch_word(strdata).c_str());
			swit = 1;
		}
		//num_elem += n;
		//strdata += con;
	}
	return strdata;
}

int count_word(string str) {
	int num = 0;
	string now,next;
	for (int i = 0; i < str.size() - 1; i++) {
		now = str[i];
		next = str[i + 1];
		if (now != " "  && next == " " ) {
			num += 1;
		}
	}
	if (str[str.size() - 1] != ' ') {
		num += 1;
	}
	return num;
}
string catch_word(string str){
	int num = 0;
	string con = "";
	//cout << "str " << str << endl;
	for (int i = 0; i < str.size() - 1; i++) {
		if (str[i] != ' ') {
			//cout << "Y" << endl;
			con += str[i];
			//cout << str[i] << "con " << con << endl;
		}
		if (str[i] != ' ' && str[i + 1] == ' ') {
			num += 1;
			
		}
		if (num == 2)
			break;
		con = "";
	}
	return con;
}

void split(int * info, string data){
	string con = "";
	int pos= 0;
	for (int i = 0; i < data.size() - 1; i++){
		if (data[i] != ' '){
			con += data[i];
		}
		if (data[i] != ' ' && data[i + 1] == ' '){
			info[pos] = atoi(con.c_str());
			con = "";
			pos += 1;
		}
	}
}