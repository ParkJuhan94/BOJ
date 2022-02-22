#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	int map[8][8];
	int i, j;
	int cnt = 0;

	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			scanf("%c", &map[i][j]);
			if (map[i][j] == 'F' && (i + j) % 2 == 0) {
				cnt++;
			}
		}
	}
	printf("%d", cnt);
}
