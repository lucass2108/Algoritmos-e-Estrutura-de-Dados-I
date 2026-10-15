#include <stdio.h>

int fat(int a);

int main()
{
    int a = 5;
    scanf("%d", &a);

    printf("%d", fat(a));
    return 0;
}

int fat(int a)
{
    if (a == 0)
        return 1;

    int res = a * fat(a - 1);

    return res;
}