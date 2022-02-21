#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int i;
    int comma;
    int a, b;

    for (i = 0; i < n; i++) {
        scanf("%d %d %d", &a, &comma, &b);
        printf("%d\n", a + b);
    }
}