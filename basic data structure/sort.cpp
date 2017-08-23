#include <iostream>

using namespace std;

int heap_sort(int * array){
	
}

void insertion_sort(int * array, int head, int tail){
	int length = tail - head + 1;
	for (int i = head + 1; i <= tail; i++){
		int key = array[i];
		int k = i;
		while (key < array[k - 1] && k > head){
			array[k] = array[k - 1];
			k--;
		}
		array[k] = key;
	}
}

void merge(int * array, int head, int middle, int tail){
	int n1 = middle - head + 1;
	int n2 = tail - middle;
	int * L = new int[n1];
	int * R = new int[n2];
	int l = 0, r = 0, k = head;
	for (int i = 0; i < n1; i++){
		L[i] = array[head + i];
	}
	for (int i = 0; i < n2; i++){
		R[i] = array[middle + 1 + i];
	}
	while (l < n1 && r < n2){
		if (L[l] < R[r]){
			array[k] = L[l];
			l++;
		}
		else{
			array[k] = R[r];
			r++;
		}
		k++;
	}
	while (l < n1){
		array[k] = L[l];
		k++;
		l++;
	}
	while (r < n2){
		array[k] = R[r];
		r++;
		k++;
	}
	delete L, R;
}

void merge_sort(int * array, int head, int tail){
    int middle = (head + tail) / 2;
    if (tail - head < 7){
    	insertion_sort(array, head, tail);
    }
    else{
    	merge_sort(array, head, middle);
    	merge_sort(array, middle + 1, tail);
    	merge(array, head, middle, tail);
    }
}

int main(){
	int num[] = {11,10,9,8,7,6,5,4,3,2,1};
	int test[] = {1,3,6,7,4,5, 9};
	int length = sizeof(num) / sizeof(int);
	merge_sort(num, 0, length - 1);

	//insertion_sort(num, 2, 7);
	for (int i = 0; i < length; i++){
		cout << num[i] << " ";
	}
	cout << endl;
}
