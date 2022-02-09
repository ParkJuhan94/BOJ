/*
https://codesyun.tistory.com/75       Âü°í
*/
#include <iostream>
using namespace std;

void star(int i, int j, int n) {
	if (i / n % 3 == 1 && j / n % 3 == 1) {		//	ºóÄ­ Àû¹ß
		cout << " ";
	}
	else if (n / 3 == 0) {						//	ºóÄ­ °Ë»ç°¡ ³¡³µÀ» ¶§ * Ãâ·Â. 27->9->3->1->0
		cout << "*";
	}
	else {	
		star(i, j, n / 3);						//	ºóÄ­ °Ë»ç ÂÉ°³±â
	}
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			star(i, j, n);
		}
		cout << '\n';
	}
}