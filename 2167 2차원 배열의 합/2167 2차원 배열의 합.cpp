#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
	
int arr[300][300];

int arrSum(int x1, int y1, int x2, int y2) {
	//	1 1 2 3 ¿œ∂ß
	//	1 2 1 2
	//	1 3 2 3
	int i, j;
	int sum = 0;

	// [0][0] [0][1] [0][2]		 [1][0] [1][1] [1][2] 
	// [0][1]
	// [0][2]  [1][2]
	for (i = x1 - 1; i <= x2 - 1; i++)
	{			
		for (j = y1 - 1; j <= y2 - 1; j++) 
		{
			sum += arr[i][j];	
		}
	}

	return sum;
}

int main() {	
	int n, m;
	int i, j;
	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	int numSum;
	int x1, y1, x2, y2;

	scanf("%d", &numSum);
	for (i = 0; i < numSum; i++) {
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			printf("%d\n", arrSum(x1, y1, x2, y2));
	}
} 