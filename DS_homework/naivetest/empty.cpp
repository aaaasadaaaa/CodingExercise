#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main(){
	string str = "a";
	char *c = new char[str.size()];
	strcpy(c,str.c_str());
	cout << int(c[0]) << endl;
}
