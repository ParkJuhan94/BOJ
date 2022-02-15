/*
https://codesyun.tistory.com/75       ����
*/
#include <iostream>
using namespace std;

//	���� ����
void star(int i, int j, int n) {
	if (i / n % 3 == 1 && j / n % 3 == 1) {		//	��ĭ ����
		cout << " ";
	}
	else if (n / 3 == 0) {						//	��ĭ �˻簡 ������ �� * ���. 27->9->3->1->0
		cout << "*";
	}
	else {	
		star(i, j, n / 3);						//	��ĭ �˻� �ɰ���
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
	/*
	star(0,0,27) -> star(0,0,9) -> star(0,0,3) -> star(0,0,1) -> star(0,0,0)
	star(0,1,27)
	star(0,2,27)
	star(0,3,27)
	star(0,4,27)
	star(0,5,27)

	star(1,1,27) -> star(1,1,9) -> star(1,1,3) -> star(1,1,1) -> star(1,1,0)
	
	
	star(27,27,27) 
	*/
}