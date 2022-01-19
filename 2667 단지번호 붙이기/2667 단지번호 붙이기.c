// https://www.acmicpc.net/problem/2667

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int** map;
int n;
int i, j;

int numEstate(int** map) {
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {

		}
	}
}

int main() {
	scanf("%d", &n);
	map = (int*)malloc(sizeof(int) * n * n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}




}