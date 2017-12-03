#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <string>

using namespace std;

const int N = 1000000;
const int L = 36;
const int M = 300000;
const int D = 4;

struct node {
	int a = -1;
	node* next = nullptr;
}typedef node;



int main() {
	node *Sequence = new node[pow(2, L/3*2)];
	char *Reference = new char[N];
	string *dna = new string[N];
	char *realdna = new char[N];

	ifstream ReferenceDNA;
	ReferenceDNA.open("ReferenceDNA.txt");
	for (int i = 0; i < N; i++) {
		Reference[i] = ReferenceDNA.get();
		dna[i] = Reference[i];
	}
	ReferenceDNA.close();
	//Reference DNA 불러와서 Reference DNA배열에 저장
	ifstream ReferencDNA;
	ReferencDNA.open("DNA.txt");
	for (int i = 0; i < N; i++) {
		realdna[i] = ReferencDNA.get();
	}
	ReferencDNA.close();
	//필요없음

	
	ifstream IndexFile;
	IndexFile.open("ReferenceDNAindex.txt");
	for (int i = 0; i < pow(2, L / 3 * 2);) {
		int number=0;
		node *ptr = &Sequence[i];
		while(1){
			char temp = IndexFile.get();
			if (temp == ' ') {
				if (IndexFile.get() == '\n') {
					ptr->a = number;
					i++;
					break;
				}
				else
					IndexFile.seekg(-1,ios::cur);
				ptr->a = number;
				node *newnode = new node;
				ptr->next = newnode;
				ptr = ptr->next;
				number = 0;
			}
			else if (temp == '-') {
				ptr->a = -1*(int)(IndexFile.get()-'0');
				IndexFile.get();
				IndexFile.get();
				i++;
				break;
			}
			else
				number = number * 10 + (int)(temp - '0');
		}
	}
	IndexFile.close();
	//INDEX 읽어와서 Sequence에 저장


	ifstream Reads;
	Reads.open("reads.txt");
	for (int i = 0; i < M; i++) {
		int number = 0;
		char* read = new char[L];
		for (int j = 0; j < L; j++) {
			read[j] = Reads.get();
		}
		for (int j = 0; j < L / 3; j++) {
			char ch = read[j];
			int value;
			if (ch == 'A')
				value = 0;
			else if (ch == 'C')
				value = 1;
			else if (ch == 'G')
				value = 2;
			else
				value = 3;
			number = 4 * number + value;
		}
		node *ptr = &Sequence[number];
		while (ptr != nullptr) {
			int deadline = 0;
			for (int j = L / 3; j < L; j++) {
				if (Reference[ptr->a + j] != (char)read[j])
					deadline++;
				if (deadline > D) {
					break;
				}
			}
			if (deadline <= D) {
				for (int j = 0; j < L; j++) {
					dna[ptr->a + j] += (char)read[j];
					Reference[ptr->a + j] = (char)read[j];
				}
			}
			ptr = ptr->next;
		}
		while (Reads.get() != '\n');
		delete[] read;
	}
	Reads.close();

	int abc = 0;
	int dis = 0;
	ofstream FINAL;
	FINAL.open("FINAL.txt");
	for (int i = 0; i < N; i++) {
		//FINAL << Reference[i];
		int size = dna[i].size();
		if (size > 1) {
			int a = 0;
			int c = 0;
			int g = 0;
			int t = 0;
			for (int j = 1; j < dna[i].size(); j++) {
				if (dna[i][j] == 'A')
					a++;
				else if (dna[i][j] == 'C')
					c++;
				else if (dna[i][j] == 'G')
					g++;
				else if (dna[i][j] == 'T')
					t++;
			}
			if (c <= a&&g <= a&&t <= a)
				FINAL << 'A';
			else if (a <= c&&g <= c&&t <= c)
				FINAL << 'C';
			else if (a <= g&&c <= g&&t <= g)
				FINAL << 'G';
			else if (a <= t&&c <= t&&c <= t)
				FINAL << 'T';
		}
		else {
			FINAL << dna[i][0];
			if (dna[i][0] != realdna[i])
				dis++;
			abc++;
		}
	}
	FINAL.close();
	cout << abc << "헤헤" << dis << endl;

	/*ofstream FINAL;
	FINAL.open("FINAL.txt");
	for (int i = 0; i < N; i++) {
		FINAL << Reference[i];
	}
	FINAL.close();
	cout << "헤헤" << endl;*/
}