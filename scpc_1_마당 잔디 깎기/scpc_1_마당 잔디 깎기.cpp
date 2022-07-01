#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int test, n, m, d, i, j, idx = 0;
	long long res = 0, sum = 0;
	int a, b, c, cnt = 1;
	scanf("%d", &test);
	for (a = 1; a <= test; a++) {
		scanf("%d %d %d", &n, &m, &d);
		vector<vector<int>> arr(n + 1, vector<int>(m + 1, 0));
		vector<int> one_arr(n * m);
		vector<int> oilPerDay(d + 1);		

		for (i = 1; i <= n; i++) {
			for (j = 1; j <= m; j++) {
				scanf("%d", &arr[i][j]);				
			}
		}

		for (i = 1; i <= d; i++) {
			scanf("%d", &oilPerDay[i]);
		}

		idx = 0;
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= m; j++) {
				one_arr[idx++] = arr[i][j];
			}
		}
		sort(one_arr.rbegin(), one_arr.rend());

		res = 0;
		cnt = 1;

		//로직 시작
		for (b = 1; b <= d; b++) {			
			for (i = 0; i < one_arr.size(); i++) {
				one_arr[i]++;
			}
						
//			for (c = 0; c < one_arr.size(); c++) {
//				printf("[%d] ", one_arr[c]);
//			}
			
			sum = 0;
			for (c = cnt; c < cnt + oilPerDay[b]; c++) {
				sum += one_arr[(c - 1) % one_arr.size()] - 1;				
				one_arr[(c - 1) % one_arr.size()] = 1;
			}
			cnt += oilPerDay[b];			
			res += sum * b;															
		}

		printf("#%d %lld\n", a, res);
	}
}
