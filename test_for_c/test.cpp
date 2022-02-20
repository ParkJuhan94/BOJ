#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
a�� ù ���̰�, b�� �� ��° ���̴�.
ó���� �� �� 1�� �����ϹǷ� ������ ���� a�� b�� 1�� �ȴٸ� �� �ֱⰡ �ϼ��� ���̴�.
m���� ���� �������� ���ؼ��� ����ϸ� �ǹǷ� a+b�� �ϰ� �׻� %m�� ���ش�.
*/
int main() {
    int P, N, M;
    scanf("%d", &P);

    int cnt, a, b;
    for (int i = 0; i < P; i++) {
        scanf("%d %d", &N, &M);
        cnt = 0;
        a = b = 1;

        while (1) {
            int tmp = (a + b) % M;
            a = b;
            b = tmp;
            cnt++;

            //�ֱ⸦ ã���� break
            if (a == 1 && b == 1) break;
        }
        printf("%d %d\n", N, cnt);
    }
    return 0;
}