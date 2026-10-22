#include <stdio.h>

void num(int i)
{
    if (i > 50)
        return;

    printf("%d ", i);

    num(i + 1);
}

int main()
{
    for (int i = 1; i <= 50; i++)
    {
        printf("%d ", i);
    }

    printf("\n");

    num(1);

    return 0;
}