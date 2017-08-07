#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cmath>
int priority_queue();
int pop(int);
void freq_out(int);
int ten_two(int);
int two_ten(int);
using namespace std;
struct node {
	int frequency;
	char name;
	string code;
	node * left_child;
	node * right_child;
	string leaf;
}; 
string text = "";
int out[256];
string code[256];
struct node queue[256];
struct node leaf_node[256];
struct node container[511];
struct node heap[511];
int find_depth(node);
node empty;
node empty2;
int main(int argc, char const *argv[]) {
	int num_of_node = priority_queue();
	int num_of_leafnode = num_of_node;
    int order = 0;
    int num = num_of_node;
    node u;
	empty.left_child = &empty;
	empty.right_child = &empty;
	/*empty2.left_child = &empty;
	empty2.right_child = &empty;*/

    while (num_of_node != 1) {
		container[2 * order] = queue[0];
		container[2 * order + 1] = queue[1];
		queue[num_of_node].frequency = container[2 * order].frequency + container[2 * order + 1].frequency;
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
	queue[0].leaf = "root";
	heap[1] = queue[0];
	heap[1].code = "";

    int num_ = pow(2,find_depth(queue[0])) ;
	for (int i = 1; i < num_; i++) {
		heap[2 * i] = *heap[i].left_child;
		heap[2 * i].code = heap[i].code + "1";
		heap[2 * i + 1] = *heap[i].right_child;
		heap[2 * i + 1].code = heap[i].code + "0";
	}
	int k = 0;
	for (int i = 0; i < num_; i++) {
        
		if (heap[i].leaf == "leaf" && heap[i].frequency != 0) {
			leaf_node[k] = heap[i];
			cout << heap[i].name << " " <<heap[i].code <<endl;
			k += 1;
		}
	}
	for (int i = 0; i < num; i++){
		out[int(leaf_node[i].name)] = leaf_node[i].frequency;
		code[int(leaf_node[i].name)] = leaf_node[i].code;
	}
	char begin[] = "HUFFMAN";
	for (int i = 0; i < 8; i++){
		putchar(int(begin[i]));
	}
	for (int i = 0; i < 256; i++){
		freq_out(out[i]);
	}
	string out_code = "";
	for (int i = 0; i < text.size(); i++){
		out_code = out_code + code[int(text[i].c_str())]
	}
	while (out_code.size() % 8 != 0){
		out_code = out_code + "0";
	}
	string o = "";
	for (int i = 0; i < (out_code.size / 8); i++){
		o = o + out_code[8 * i + 7] + out_code[8 * i + 6] + out_code[8 * i + 5] + out_code[8 * i + 4] + out_code[8 * i + 3] + out_code[8 * i + 2] + out_code[8 * i + 1] + out_code[8 * i];
		putchar(two_ten(o.c_str()))
	}
	

}
int find_depth(node a){
	int depth;
	if (a.leaf == "leaf")
		depth = 1;
	else
		depth = fmax(find_depth(*a.left_child),find_depth(*a.right_child)) + 1;
	return depth;
}
int freq_out(int freq){
	int num = ten_two(freq);
	string str,str1,str2,str3,str4;
	int out1,out2,out3,out4;
	sprintf(str,"%32s",num);
	for (int i = 0; i < 8; i++){
		str1 = str1 + str[i]
	}
	for (int i = 8; i < 16; i++){
		str2 = str2 + str[i]
	}
	for (int i = 16; i < 24; i++){
		str3 = str3 + str[i]
	}
	for (int i = 24; i < 32; i++){
		str4 = str4 + str[i]
	}
	out4 = two_ten(atoi(str1.c_str()));
	out3 = two_ten(atoi(str2.c_str()));
	out2 = two_ten(atoi(str3.c_str()));
	out1 = two_ten(atoi(str4.c_str()));
	putchar(out1);
	putchar(out2);
	putchar(out3);
	putchar(out4);
}
int ten_two(int k){
	int w = k;
	int y = 0;
	int r = 0;
	while(w != 0){
		y = w % 2;
		r = r * 10 + y;
		w = w / 2;
	}
	return r;
}
int two_ten(int t){
	int w = t;
	int y = 0;
	int r = 0;
	int i = 0;
	while(w != 0){
		y = w % 10;
		r = r + y * pow(2,i);
		w = w / 10;
		i += 1;
	}
	return r;
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
	}
	seekg(0,ios::beg);
	string con;
	char in2 = getchar();
	while (in2 != EOF){
		con = in2;
		text = text + con;
		in2 = getchar();
	}
    return num_of_info;
}
int pop(int num) {
	for (int i = 0; i < num ; i++) {
		queue[i] = queue[i + 2];
	}
	return num - 1;
}