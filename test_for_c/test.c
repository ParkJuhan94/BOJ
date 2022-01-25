#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int test;
	int num_repeat;
	char str[21];

	scanf("%d", &test);

	for (int i = 0; i < test; i++) {		
		scanf("%d", &num_repeat);
		scanf("%s", str);

		for (int i = 0; str[i] != 0; i++) {
			for (int j = 0; j < num_repeat; j++) {
				printf("%c", str[i]);
			}
		}
		printf("\n");
	}
}