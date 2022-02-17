#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int isPrimeNum(int n) {
    int cnt = 0;

    if (n == 2) {
        return 1;
    }

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            cnt++;
        }
        if (cnt > 1) {
            return 0;
        }
    }

    if (cnt == 1) {
        return 1;
    }
}

int main() {
    int i, j, k;
    int n, evenNum;
    int max = 0, min = 10000;
    

    scanf("%d", &n);
    for (i = 0; i < n;i++) {
        scanf("%d", &evenNum);
        max = 0;
        min = 10000;

        for (j = 2; j <= evenNum / 2; j++) {
            if (isPrimeNum(j) && isPrimeNum(evenNum - j)) {
                if (j > max) {
                    max = j;
                }
            }
        }

        printf("%d %d\n", max, evenNum - max);
    }    
}