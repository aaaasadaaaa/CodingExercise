#include <iostream>
#include <string>
using namespace std;
struct leaf {
	bool visited = false;
	int  parent = 0;
};
string input(void);
int count_word(string);
string catch_word(string);
void split(int*, string);
int component(leaf *, int *,int, int **);
int traversal(leaf *, int **, int, int);
string spantree(leaf *, int, int, int **, int);
void pop(int *, int);
void insert(int *, int, int, int);
void change(int *, int, int);
int smallest_city(string);
//void sort(int *);

int main() {
	string data = input();
	//cout << data << endl;
	int num = count_word(data);
	int * info;
	//cout << "num " << num << endl;
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
	for (int i = 1; i < num - 1; i = i + 3) {
		//cout << info[i + 1] << " " << info[i + 2] << " " << info[i + 3] << endl;
		if (graph[info[i + 1]][info[i + 2]] > info[i + 3] || graph[info[i + 1]][info[i + 2]] == 0){
			graph[info[i + 1]][info[i + 2]] = info[i + 3];
			graph[info[i + 2]][info[i + 1]] = info[i + 3];
		}
	}
	//cout << 1 << endl;
	//for (int i = 0; i < info[0]; i++) {
	//	for (int j = 0; j < info[0]; j++) {
	//		cout << graph[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	int * root;
	root = new int[info[0]];
	leaf * vertix;
	vertix = new leaf[info[0]];
	int num_set = component(vertix, root, info[0],graph);
	
	/*for (int i = 0; i < info[0]; i++) {
		cout << "node " << i << " set " << vertix[i].parent << endl;
	}
	cout << "num set " << num_set << endl;*/

	string * regions;
	regions = new string [num_set];
	for (int i = 0; i < num_set; i++) {
		regions[i] = spantree(vertix, root[i + 1], i + 1, graph, info[0]);
		//cout << regions[i] << endl;
	}
	pop(root,info[0]);
	int token;
	string token2 = "";
	for(int i = 0; i < num_set - 1; i++) {
		for (int j = 0; j < num_set - i - 1; j++) {
			if (root[j] < root[j + 1]) {
				change(root, j, j + 1);
				token2 = regions[j];
				regions[j] = regions[j + 1];
				regions[j + 1] = token2;
			} 
			if (root[j] == root[j + 1] && root[j] > 1) {
				if (smallest_city(regions[j]) < smallest_city(regions[j + 1])) {
					change(root, j, j + 1);
					token2 = regions[j];
					regions[j] = regions[j + 1];
					regions[j + 1] = token2;
				}
			}
		} 
	}
	cout << "[" << endl;
	int sum = 0;
	//for (int i = 0; i < info[0]; i++) {
	//	sum += root[i];
	//}
	for (int i = 0; i < num_set; i++) {
		if (root[i] == 1)
			break;
		int * y;
		y = new int[3 * (root[i] - 1)];
		split(y, regions[i]);
		for(int j = 0; j < 3 * (root[i] - 1) - 1; j = j + 3) {
			for(int k = 2; k < 3 * (root[i] - 1) - 1 - j; k = k + 3) {
				if (y[k] <= y[k + 3]) {
					change(y, k, k + 3);
					change(y, k - 1, k + 2);
					change(y, k - 2, k + 1);
				}
			}
		}
		for (int j = 0; j < 3 * (root[i] - 1) ; j = j + 3) {
			//cout << y[j] << " " << y[j + 1] << endl;
			if (y[j] > y[j + 1])
				change(y, j, j + 1);
		}
		int symb = 0;
		cout << "[" << endl;
		for (int u = 0; u < 3 * (root[i] - 1) - 2; u = u + 3) {
			if(symb == 0) {
				cout << '[' << y[u] << "," << y[u + 1] << "," << y[u + 2] << "]";
				symb += 1;
			}
			else{
				cout <<","<< endl << "[" << y[u] << "," << y[u + 1] << "," << y[u + 2] << "]";
			}
		}
		cout << endl ;
		sum += root[i];
		if (info[0]   == sum) {
			cout << "]" << endl;
		}
		else{
			cout << "]," << endl;
		}
	}
	for (int i = 0; i < info[0] - sum; i++) {
		if (i != info[0] - sum - 1)
			cout << "[\n]," << endl;
		else
			cout << "[\n]" << endl;
	}
	cout << "]" <<endl;
	//cout << "num " << num_set << endl;
	return 0;
}
int smallest_city(string data) {
	int num = count_word(data);
	int * list;
	list = new int[num];
	split(list, data);
	int small = 0;
	
	for (int i = 0; i < num ; i = i + 3) {
		//cout << i << " " << list[i] << endl;
		//cout << i + 1 << " " << list[i + 1] << endl;
 		if (small == 0) {
			if (list[i] < list[i + 1])
				small = list[i];
			else
				small = list[i + 1];
		}
		else{
			if(list[i] < list[i + 1]){
				if (small > list[i])
					small = list[i];
			}
			else{
				if (small > list[i + 1])
					small = list[i + 1];
			}
		}
	}

	return small;
}
void change(int * list, int pos1, int pos2) {
	int token;
	token = list[pos1];
	list[pos1] = list[pos2];
	list[pos2] = token;
}
void pop(int * list, int num) {
	for (int i = 1; i < num; i++) {
		list[i - 1] = list[i];
	}
	list[num - 1] = 0;
}
void insert(int * list, int pos, int num, int data) {
	for (int i = num - 2; i > pos; i = i - 1) {
		list[i + 1] = list[i];
	}
	list[pos] = data;
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
			//cout << catch_word(strdata) << endl;
			symb = 2 + 3 * atoi(catch_word(strdata).c_str());
			//cout << "symb " <<symb << endl;
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
	for (int i = 0; i < str.size() ; i++) {
		if (str[i] != ' ') {
			//cout << "Y" << endl;
			con += str[i];
			//cout << str[i] << "con " << con << endl;
		}
		if (str[i] != ' ' && str[i + 1] == ' ') {
			num += 1;
			if (num == 2)
				break;
			else
				con = "";
			
		}
	}
	return con;
}

int component(leaf * vertix, int * root, int num, int ** graph) {
	int sum = 0; 
	int i = 1;
	while (sum < num) {
		root[i] = traversal(vertix, graph, num, i);
		//cout << "root " << root[i] << endl;
		sum += root[i];
		i += 1;
		//cout << "node num " << sum << endl; 
	}
	return i - 1;
}
int traversal(leaf * vertix, int ** graph, int num, int set) {
	//cout << "set " << set << endl;
	int vertix_num = 0;
	for (int i = 0; i < num; i++) {
		//cout << "node " << i << " set " << vertix[i].parent << endl;
		if (vertix[i].parent == 0) {
			//cout << "original " << i << endl;
			int * con;
			con = new int[num];
			for (int k = 0; k < num; k++) {
				con[k] = 0;
			}
			int length = 0;
			insert(con, length, num, i);
			length = length + 1;
			vertix[i].parent = set;
			vertix[i].visited = true;
			while (length != 0) {
				//cout << "vertix_num " << vertix_num << endl;
				for (int k = 0; k < num; k++) {
					//cout << con[vertix_num] << " " << k << " " << graph[con[vertix_num]][k] << " " << vertix[k].visited <<  endl;
					if (graph[con[0]][k] != 0 && vertix[k].visited == false) {
						insert(con, length, num, k);
						length += 1;
						vertix[k].visited = true;
						vertix[k].parent = set;
					}
				
				}
				//cout << "length " << length << endl;
				pop(con, num);
				length = length - 1;
				vertix_num += 1;
				//for (int j = 0; j < num; j++) {
				//	cout << "con" << j << " " << con[j] << endl;
				//}
			}
		break;
		}
		
	}
	return vertix_num;
}
string spantree(leaf * vertix, int num, int set, int ** graph, int num_vertix) {

	string road = "";	
	int num_node = 0;
	for (int i = 0; i < num_vertix; i++) {
		if (vertix[i].parent == set) {
			int * node;
			node = new int[num];
			//cout << "s " << set << " node " << i << endl;
			node[0] = i;
			num_node += 1;
			while(num_node < num) {
				int pos1,pos2;
				int con = 10000000;
				for (int k = 0; k < num_node; k++) {
					for (int j = 0; j < num_vertix; j++) {
						//cout << "con " << con << " road " << graph[k][j] << endl;
						//cout << "start " << k << " ter " << j << endl;
						if (graph[node[k]][j] != 0) {
							if (graph[node[k]][j] < con) {
								con = graph[node[k]][j];
								pos1 = node[k];
								pos2 = j;
							}
						}
					}
				}
				//cout << "s " << pos1 << " t " << pos2 << " r " << con << endl;
				graph[pos1][pos2] = 0;
				graph[pos2][pos1] = 0;
				node[num_node] = pos2;
				num_node += 1; 
				string pos1_,pos2_,con_;
				char con1[10],con2[10],con3[10];
				sprintf(con1,"%d",pos1);
				sprintf(con2,"%d",pos2);
				sprintf(con3,"%d",con);
				pos1_ = con1;
				pos2_ = con2;
				con_ = con3;
				road += pos1_ + " " + pos2_ + " " + con_ + " ";
			}
			break;
		}
	}
	return road;
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