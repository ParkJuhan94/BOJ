/*
https://www.acmicpc.net/problem/10872
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int factorial(int n) {
	if (n == 0) {
		return 1;
	}
	else {
		return n * factorial(n - 1);
	}
}


int main() {
	int N;
	scanf("%d", &N);

	printf("%d\n", factorial(N));
}