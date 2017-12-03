//2013112056 홍진환
#include <iostream>
#include <fstream>
#include <time.h>
#include <math.h>

using namespace std;

const int N = 1000000;
const int L = 36;

struct node {
	int a = -1;
	node* next = nullptr;
}typedef node;

int main() {
	char *ReferenceDNA = new char[N];
	node *index = new node[pow(2, L/3*2)];

	ifstream ReferenceFile;
	ReferenceFile.open("ReferenceDNA.txt");
	for (int i = 0;i<N;i++) {
		ReferenceDNA[i] = ReferenceFile.get();
	}
	ReferenceFile.close();
	//unsigned char에 배정하는 과정


	for (int i = 0; i < N-L/3; i ++) {
		int number = 0;
		for (int j = i; j < i+L/3; j++) {
			int value;
			if (ReferenceDNA[j] == 'A')
				value = 0;
			else if (ReferenceDNA[j] == 'C')
				value = 1;
			else if (ReferenceDNA[j] == 'G')
				value = 2;
			else
				value = 3;
			number = value + number * 4;
		}
		if (index[number].a == -1)
			index[number].a = i;
		else {
			node *temp = new node;
			node *ptr = &index[number];
			while (ptr->next != nullptr) {
				ptr = ptr->next;
			}
			ptr->next = temp;
			temp->a = i;
		}
	}

	ofstream IndexFile;
	IndexFile.open("ReferenceDNAindex.txt");
	for (int i = 0; i < pow(2, L / 3*2); i++) {
		node *ptr=&index[i];
		do {
			if (ptr->a == 0)
				IndexFile << '*';
			IndexFile << ptr->a << " ";
			ptr=ptr->next;
		} while (ptr != NULL);
		IndexFile << "\n";
	}
	IndexFile.close();
}