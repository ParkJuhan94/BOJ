#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
    int score[5] = { 0 };
    int tmp;
    int i, j;
    int max = 0;
    int winner;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 4; j++) {
            scanf("%d", &tmp);
            score[i] += tmp;
        }
    }

    for (i = 0; i < 5; i++) {
        if (score[i] > max) {
            max = score[i];
            winner = i;
        }
    }
    printf("%d %d", winner + 1, score[winner]);
}
