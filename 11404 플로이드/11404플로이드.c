

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 101
#define INF 987654321

int i, j;
int graph[MAX][MAX];

/*
ex)
int before[MAX][MAX];		: ����ġ �Ӹ��� �ƴ� ��α��� �˱� ����, ������ ������ �����ϴ� ��� ����

1���� 2������ ��� : 1 5 4 3 2
1���� 3������ ��� : 1 5 4 3
*/

void floyd(int n) {		//	n : ������ ����
	for (int mid = 1; mid <= n; mid++) {
		for (int start = 1; start <= n; start++) {
			for (int end = 1; end <= n; end++) {
				if (graph[start][mid] != INF && graph[mid][end] != INF)
					graph[start][end] = min(graph[start][end], graph[start][mid] + graph[mid][end]);
			}
		}
	}
}

int main() {
	int n, m;
	int from, to, fee;

	// n: ������ ��, m: ������ ��
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) {        // graph �ʱ�ȭ
		for (j = 1; j <= n; j++) {
			graph[i][j] = INF;
		}
	}

	for (i = 0; i < m; i++) {		//	����ġ �Է�
		scanf("%d %d %d", &from, &to, &fee);
		graph[from][to] = min(graph[from][to], fee);		
	}

	floyd(n);

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (i == j || graph[i][j] == INF) {
				printf("0 ");
			}
			else {
				printf("%d ", graph[i][j]);
			}			
		}
		printf("\n");
	}
}