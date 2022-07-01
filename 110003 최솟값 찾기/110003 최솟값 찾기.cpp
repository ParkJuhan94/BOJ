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
		//	flag 가 1로 바뀌어있으면 해당 윈도우에 같은 min이 존재하는 것.
		if (arr[i] == min) {
			flag = 1;
		}
		tmpMin = min;
		if (arr[i] < min) {
			min = arr[i];			
		}		
	}	
	d[first] = min;

	//	슬라이딩 윈도우 한칸씩 이동
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
		else {	//	이전 윈도우에서 중복 min 없었을때
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
	int data; // 원소값
	int pos;  // 원소가 위치한 인덱스
};

int main() {
	// cin, cout 입출력 속도 향상 
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
	if (!dq.empty() && i == dq.front().pos + L) // 나갈 타이밍이 된 친구는 앞에서 빠져나가도록 삭제해준다. pop_front()
		dq.pop_front();
	while (!dq.empty() && dq.back().data > arr[i]) // arr[i] 가 들어오게 됨으로써 arr[i]보다 커서 앞으로 최소값 될 일이 절대 없는 기존 deque 안의 원소들은 삭제해준다. pop_back()
		dq.pop_back();
	dq.push_back({ arr[i], i }); // arr[i] 을 추가한다. (위 pop_back()으로 인하여 arr[i]보다 더 큰건 다 삭제했으므로 오름차순 정렬을 유지한 채로 뒤에 추가되게 된다.)
	cout << dq.front().data << " "; // deque 의 맨앞 원소를 출력하면 그게 바로 현재 구간(i-L+1 ~ i)에서의 최소값 
}
}

*/