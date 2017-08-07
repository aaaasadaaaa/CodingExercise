#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main(int argc, char const * argv[]){
	string str = argv[1];
	cout << "size" << str.size() << endl;
	char *c = new char[str.size()];
	strcpy(c,str.c_str());
	for (int i = 0; i < str.size(); i++){
		cout << c[i] << endl;
		if (int(c[i]) > 57 && int(c[i] < 48))
			cout << "str" << endl;
	}
	cout << "int" << endl;
}
