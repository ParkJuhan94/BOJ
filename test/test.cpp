#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int a[4];
    int i, j;
    int sum = 0;

    for (i = 0; i < 3; i++) {
        sum = 0;
        scanf("%d %d %d %d", &a[0], &a[1], &a[2], &a[3]);
        

        for (j = 0; j < 4; j++) {
            sum += a[j];
        }
        if(sum == 3){
            printf("A\n");
        }
        else if (sum == 2) {
            printf("B\n");
        }
        else if (sum == 1) {
            printf("C\n");
        }
        else if (sum == 4) {
            printf("E\n");
        }
        else if (sum == 0) {
            printf("D\n");
        }
    }
}
