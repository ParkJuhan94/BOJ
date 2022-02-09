#define _RT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    int number, repeat;
    int i,j,k;

    char s[21];
    scanf("%d", &number);

    for (i = 0; i < number; i++)
    {
        scanf("%d", &repeat);
        scanf("%s", s);

        for (int i = 0; s[i] != 0; i++)
        {
            for (j = 0; j < repeat; j++)
            {
                printf("%c", s[i]);
            }
        }
        printf("\n");
    }



    return 0;
}