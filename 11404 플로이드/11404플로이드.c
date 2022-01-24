/*
https://www.acmicpc.net/problem/11404
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 101

int i, j;
int graph[MAX][MAX];
//int before[MAX][MAX];		// ����ġ �Ӹ��� �ƴ� ��θ� �˱����� ������ ���� ��� ����
/*
ex)
1���� 2������ ��� : 1 5 4 3 2
1���� 3������ ��� : 1 5 4 3
1���� 4������ ��� : 1 5 4
1���� 5������ ��� : 1 5
2���� 1������ ��� : 2 4 1
*/

/*
typedef struct bus {
	int start;
	int end;
	int fee;
}bus;
*/

void floyd(int n) {
	for (int mid = 1; mid <= n; mid++) {
		for (int start = 1; start <= n; start++) {
			for (int end = 1; end <= n; end++) {
				if (graph[start][end] > graph[start][mid] + graph[mid][end]) {
					// �� ����� ��ΰ� ���� ��� �ֽ�ȭ
					graph[start][end] = graph[start][mid] + graph[mid][end];
				}
			}
		}
	}
}

int main() {
	int n, m;
	int row, col, fee;

	// n: ������ ��, m: ������ ��
	scanf("%d %d", &n, &m);
	//bus* b = (bus*)malloc(sizeof(bus) * m);

	for (i = 0; i < m; i++) {
		//scanf("%d %d %d", &b[i].start, &b[i].end, &b[i].fee);
		scanf("%d %d %d", &row, &col, &fee);
		row -= 1;
		col -= 1;
		graph[row][col] = fee;
	}

	floyd(n);

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%d ", graph[i][j]);
		}
		printf("\n");
	}
}