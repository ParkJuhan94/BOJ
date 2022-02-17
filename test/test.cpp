#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int a, b, c;
    int flagA = 0, flagB = 0, flagC = 0;
    int max = 0;
    int equal_3 = 0, equal_2 = 0;
    int res = 0;
    scanf("%d %d %d", &a, &b, &c);

    if (a > max) {
        max = a;
    }
    if (b > max) {
        max = b;
    }
    if (c > max) {
        max = c;
    }


    if (a == b && b == c) {
        equal_3 = 1;
    }
    else if (a == b) {
        equal_2 = 1;
        flagA = 1;
        flagB = 1;
    }
    else if (b == c) {
        equal_2 = 1;
        flagB = 1;
        flagC = 1;
    }
    else if (c == a) {
        equal_2 = 1;
        flagC = 1;
        flagA = 1;
    }
    //printf("cnt : %d\n", cnt);

    if (equal_3 == 1) {
        res = 10000 + a * 1000;
    }
    if (equal_3 != 1 && equal_2 == 1) {
        if (flagA == 1) {
            res = 1000 + a * 100;
        }
        if (flagB == 1) {
            res = 1000 + b * 100;
        }
        if (flagC == 1) {
            res = 1000 + c * 100;
        }
    }
    if (equal_3 != 1 && equal_2 != 1) {
        res = max * 100;
    }       
    printf("%d\n", res);
}