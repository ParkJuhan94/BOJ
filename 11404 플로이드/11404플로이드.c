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
//int before[MAX][MAX];		// 가중치 뿐만이 아닌 경로를 알기위해 직전의 정점 행렬 선언
/*
ex)
1부터 2까지의 경로 : 1 5 4 3 2
1부터 3까지의 경로 : 1 5 4 3
1부터 4까지의 경로 : 1 5 4
1부터 5까지의 경로 : 1 5
2부터 1까지의 경로 : 2 4 1
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
					// 더 가까운 경로가 있을 경우 최신화
					graph[start][end] = graph[start][mid] + graph[mid][end];
				}
			}
		}
	}
}

int main() {
	int n, m;
	int row, col, fee;

	// n: 정점의 수, m: 간선의 수
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