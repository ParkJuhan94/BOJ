#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>

int dp[100];

int main() {
	int n;
	scanf("%d", &n);

	dp[1] = 9;
	dp[2] = 17;

	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] * 2 - (i - 1);
	}

	printf("%d\n", dp[n]%1000000000);
}