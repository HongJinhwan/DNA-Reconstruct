#include <iostream>
#include <fstream>

using namespace std;

const int N = 1000000;

int main() {
	int disequi = 0;
	int temp = 0;
	ifstream origin;
	ifstream make;
	origin.open("DNA.txt");
	make.open("FINAL.txt");
	for (int i = 0; i < N; i++) {
		if (origin.get() != make.get()) {
			disequi++;
			temp++;
		}
		if (i % 9999 == 0 && i != 0) {
			cout << i - 9999 << "~" << i << ":" << temp << endl;
			temp = 0;
		}

	}
	cout << "N개중에 불일치 " << disequi << "개";
	cin >> disequi;
}