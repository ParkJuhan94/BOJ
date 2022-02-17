#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
    int x, y, w, h;
    int goX, goY;

    scanf("%d %d %d %d", &x, &y, &w, &h);
    if (w > 2 * x) {
        goX = x;
    }
    else {
        goX = w - x;
    }

    if (h > 2 * y) {
        goY = y;
    }
    else {
        goY = h - y;
    }

    int min;
    if (goX > goY) {
        min = goY;
    }
    else {
        min = goX;
    }
    printf("%d\n", min);
}