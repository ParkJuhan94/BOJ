#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>

//  �� ū ������ ��ȯ�ϴ� �Լ�
int bigger(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

//  �� ���� ������ ��ȯ�ϴ� �Լ�
int smaller(int a, int b) {
    if (a > b) {
        return b;
    }
    return a;
}

//  �� ������ �ִ������� ��ȯ�ϴ� �Լ�
int max(int a, int b) {
    int res;

    for (int i = 1; i <= smaller(a, b); i++) {
        if (a % i == 0 && b % i == 0) {
            res = i;
        }
    }

    return res;
}

//  �� ������ �ּҰ������ ��ȯ�ϴ� �Լ�
int min(int a, int b) {
    int res;

    if (a != 0 && b != 0) {
        for (int i = bigger(a, b); i < 10000000; i++) {
            if (i % a == 0 && i % b == 0) {
                res = i;
                return res;
            }
        }
    }
    else {
        return 0;
    }

}

int main()
{
    int i;
    int sum = 0;
    double avg = 0;
    int num;
    int arr[20] = { 0 };

    scanf("%d", &num);
    for (i = 0; i < num; i++) {
        scanf("%d", &arr[i]);
    }

    if (num % 2 == 0) {     //  num�� ¦���� ��� ������ �� ���� ¦�� �̷� ��
        for (i = 0; i < num; i += 2) {
            int m = bigger(arr[i], arr[i + 1]) / smaller(arr[i], arr[i + 1]);

            if (m > max(arr[i], arr[i + 1])) {
                sum += min(arr[i], arr[i + 1]);
                printf("%d�� %d�� �ּҰ����: %d\n", arr[i], arr[i + 1], min(arr[i], arr[i + 1]));
            }
            else {
                sum += max(arr[i], arr[i + 1]);
                printf("%d�� %d�� �ִ�����: %d\n", arr[i], arr[i + 1], max(arr[i], arr[i + 1]));
            }
        }
        avg = (double)sum / num * 2;
        printf("��հ� : %lf\n", avg);
    }
    else {      //  num�� Ȧ���� ������ ������ ���� �Ǿ���� ��
        for (i = 0; i < num - 3; i += 2) {
            int m = bigger(arr[i], arr[i + 1]) / smaller(arr[i], arr[i + 1]);

            if (m > max(arr[i], arr[i + 1])) {
                sum += min(arr[i], arr[i + 1]);
                printf("%d�� %d�� �ּҰ����: %d\n", arr[i], arr[i + 1], min(arr[i], arr[i + 1]));
            }
            else {
                sum += max(arr[i], arr[i + 1]);
                printf("%d�� %d�� �ִ�����: %d\n", arr[i], arr[i + 1], max(arr[i], arr[i + 1]));
            }
        }
        int m = bigger(bigger(arr[i], arr[i + 1]), arr[i + 2]) / smaller(smaller(arr[i], arr[i + 1]), arr[i + 2]);

        if (m > max(arr[i], arr[i + 1])) {
            sum += min(arr[i], arr[i + 1]);
            printf("%d�� %d�� �ּҰ����: %d\n", arr[i], arr[i + 1], min(arr[i], arr[i + 1]));
        }
        else {
            sum += max(arr[i], arr[i + 1]);
            printf("%d�� %d�� �ִ�����: %d\n", arr[i], arr[i + 1], max(arr[i], arr[i + 1]));
        }
        avg = (double)sum / (num - 1) * 2;
        printf("��հ� : %lf\n", avg);
    }
}