#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int n, l, i, min = 2143000000, tmpMin, first, flag = 0;
	vector<int> arr(n);
	vector<int> d(n);

	for (i = 0; i < n; i++) {
		scanf("%d", arr[i]);
	}

	for (i = 0; i - l + 1 <= 0; i++ ) {
		d[i] = arr[0];
	}	
	first = i;	//	 first = 3
	for (i = first - l + 1; i < first; i++) {
		//	flag �� 1�� �ٲ�������� �ش� �����쿡 ���� min�� �����ϴ� ��.
		if (arr[i] == min) {
			flag = 1;
		}
		tmpMin = min;
		if (arr[i] < min) {
			min = arr[i];			
		}		
	}	
	d[first] = min;

	//	�����̵� ������ ��ĭ�� �̵�
	for (i = first + 1; i < n; i++) {
		if (flag == 1) {
			if (arr[i] < min) {
				d[i] = arr[i];
			}
			else if (arr[i] == min) {
				flag = 1;
				d[i] = arr[i];
			}			
		}
		else {	//	���� �����쿡�� �ߺ� min ��������
			if (arr[i - l] == min) {
				if (arr[i] < tmpMin){
					min = arr[i];
				}
				else if (arr[i] == tmpMin) {
					flag = 1;

					min = tmpMin;
				}
			}
			if (arr[i] < min) {
				d[i] = arr[i];
			}

		}
		flag = 0;
		
	}

	for (i = 0; i < n; i++) {
		printf("%d ", d[i]);
	}
}

/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

struct A {
	int data; // ���Ұ�
	int pos;  // ���Ұ� ��ġ�� �ε���
};

int main() {
	// cin, cout ����� �ӵ� ��� 
ios::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

int N, L;
cin >> N >> L;
vector<int> arr(N);
for (int i = 0; i < N; ++i)
	cin >> arr[i];

deque<A> dq;
for (int i = 0; i < N; ++i) {
	if (!dq.empty() && i == dq.front().pos + L) // ���� Ÿ�̹��� �� ģ���� �տ��� ������������ �������ش�. pop_front()
		dq.pop_front();
	while (!dq.empty() && dq.back().data > arr[i]) // arr[i] �� ������ �����ν� arr[i]���� Ŀ�� ������ �ּҰ� �� ���� ���� ���� ���� deque ���� ���ҵ��� �������ش�. pop_back()
		dq.pop_back();
	dq.push_back({ arr[i], i }); // arr[i] �� �߰��Ѵ�. (�� pop_back()���� ���Ͽ� arr[i]���� �� ū�� �� ���������Ƿ� �������� ������ ������ ä�� �ڿ� �߰��ǰ� �ȴ�.)
	cout << dq.front().data << " "; // deque �� �Ǿ� ���Ҹ� ����ϸ� �װ� �ٷ� ���� ����(i-L+1 ~ i)������ �ּҰ� 
}
}

*/