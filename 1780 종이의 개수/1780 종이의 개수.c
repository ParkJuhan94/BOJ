/*
https://www.acmicpc.net/problem/1780

���� ���� ���� ��� ���ڵ��� ���� �����, �������� �ʽ��ϴ�.

������, ���� ���� �ٸ� ���ڰ� �ϳ��� ���Եȴٸ�, 9���� ���̷� �ڸ���,
�߸� ���̸��� ���ڰ� ��� ������ �ƴ����� �ݺ��Ͽ� �Ǵ��մϴ�.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int res[3] = { 0 };
int map[2200][2200];	//�Է��� �ִ밪�� 2143
int i, j;

// ���� �� ��� ĭ���� ��� ������ �Ǵ�
bool check(int row, int col, int num) {

	// ������
	int start = map[row][col];
	for (int i = row; i < row + num; i++) {
		for (int j = col; j < col + num; j++) {
			if (start != map[i][j])		//start�� ���Ұ� �ٸ��� return false �ϸ鼭 ����(Ż��)
				return false;
		}
	}
	return true;
}

// ���: 9���ҷ� �����ְ� res�� �����ϴ� �Լ�
void divide(int row, int col, int num) {

	if (check(row, col, num)) {		// ���� ���� �� ��� ĭ���� ���� ���ٸ�
		res[map[row][col]]++;
	}
	else {		// ��� ĭ���� ���� ���� �ʴٸ� -> ���ο� ���� ����� �����.		
		int size = num / 3;

		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				divide(row + size * i, col + size * j, size);	//�������� num�� �����
			}
		}
	}
}

int main() {
	int N;
	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {

			int input;
			scanf("%d", &input);
			input++; // -1,0,1 �� 0,1,2�� ���� : res�� index�� ���߷���
			map[i][j] = input;
		}
	}

	divide(0, 0, N);
	printf("%d\n%d\n%d\n", res[0], res[1], res[2]);
}
