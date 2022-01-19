/*
 https://www.acmicpc.net/problem/2447
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int x, y;
int n;
char* map;

void putStar(int x, int y, int cnt) {
	if (cnt == 1) {
		map[x + y * n] = '*';
		map[x + y * n + 1] = '*';
		map[x + y * n + 2] = '*';
		map[x + y * n + n] = '*';
		map[x + y * n + n + 2] = '*';
		map[x + y * n + 2 * n] = '*';
		map[x + y * n + 2 * n + 1] = '*';
		map[x + y * n + 2 * n + 2] = '*';
	}
	else {
		putStar(n / 3, n / 3, cnt / 3);
	}
}

int main() {
	scanf("%d", &n);
	map = (char*)malloc(sizeof(char) * n * n);

	for (int i = 0; i < n * n; i++) {
		map[i] = ' ';
	}

	putStar(n, n, n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%c", map[i * n + j]);
		}
		printf("\n");
	}
}