#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <string>
using namespace std;

string input(const char* file) {
	ifstream in(file);
	istreambuf_iterator<char> beg(in), end;
	string strdata(beg, end);
	in.close();
	return strdata;
}
int main(int argc, char const *argv[]) {
	string str = input(argv[1]);
	cout << str << endl;
}
