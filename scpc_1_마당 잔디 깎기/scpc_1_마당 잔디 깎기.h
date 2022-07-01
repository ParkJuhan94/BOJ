#pragma once

int main() {
	int test, n, m, d, i, j, sum = 0, idx = 0, res = 0;
	int a, b, c;
	scanf("%d", &test);
	for (a = 1; a <= test; a++) {
		scanf("%d %d %d", &n, &m, &d);
		vector<vector<int>> arr(n + 1, vector<int>(m + 1, 0));
		vector<int> one_arr(n * m);
		vector<int> oil(d + 1);
		vector<int> max(d + 1);

		for (i = 1; i <= n; i++) {
			for (j = 1; j <= m; j++) {
				scanf("%d", &arr[i][j]);
			}
		}

		for (i = 1; i <= d; i++) {
			scanf("%d", &oil[i]);
		}

		res = 0;
		//로직 시작
		for (b = 1; b <= d; b++) {
			idx = 0;
			for (i = 1; i <= n; i++) {
				for (j = 1; j <= m; j++) {
					one_arr[idx++] = arr[i][j];
				}
			}
			sort(one_arr.begin(), one_arr.end());

			idx = 0;
			for (i = n * m - 1; i >= n * m - 1 - oil[b]; i--) {
				max[idx++] = one_arr[i];
			}

			sum = 0;
			for (c = 1; c <= oil[b]; c++) {
				for (i = 1; i <= n; i++) {
					for (j = 1; j <= m; j++) {
						if (arr[i][j] == max[c]) {
							sum += (arr[i][j] - 1);
							arr[i][j] = 1;
							continue;
						}
					}
				}
			}
			res += sum * b;
		}

		printf("#%d %d\n", a, res);
	}
}
