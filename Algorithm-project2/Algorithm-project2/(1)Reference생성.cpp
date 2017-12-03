#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

const int N = 1000000;
const int ERROR = 50;

int main() {
	srand((unsigned int)time(NULL)); //·£´ý½Ãµå : ½Ã°£

	char dna[4] = { 'A','C','G','T' };
	char ch[N];
	ifstream MyGenomeSeq;
	MyGenomeSeq.open("DNA.txt");
	for (int i = 0; i < N; i++) {
		ch[i] = MyGenomeSeq.get();
	}
	MyGenomeSeq.close();
	//MyGenomeSequence ÀÐ¾î¿È
	for (int i = 0; i < N; i++) {
		if (rand() % 50 == 0) {
			ch[i] = dna[rand()%4];
		}
	}


	ofstream ReferenceDNA;
	ReferenceDNA.open("ReferenceDNA.txt");
	for (int i = 0; i < N; i++) {
			ReferenceDNA << ch[i];
	}
	ReferenceDNA.close();
}