//2013112056 ȫ��ȯ
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>

using namespace std;

const int N = 1000000;
const int M = 300000;
const int L = 36;

int main() {
	srand((unsigned int)time(NULL)); //�����õ� : �ð�

	char ch[N];
	ifstream MyGenomeSeq;
	MyGenomeSeq.open("DNA.txt");
	for (int i = 0; i < N; i++) {
		ch[i] = MyGenomeSeq.get();
	}
	MyGenomeSeq.close();
	//MyGenomeSequence �о��

	ofstream myfile;
	myfile.open("reads.txt");
	for (int i = 0; i < M; i++) {
		int temp =
			(rand() % 10) * 100000
			+ (rand() % 10) * 10000
			+ (rand() % 10) * 1000
			+ (rand() % 10) * 100
			+ (rand() % 10) * 10
			+ (rand() % 10);
		if (temp > N - L)
			i--;
		else {
			for (int j = 0; j < L; j++) {
				myfile << ch[temp+j];
			}
			myfile << endl;
		}
	}
	myfile.close();
	// ���� 50�� ������Ʈ�� ����
}