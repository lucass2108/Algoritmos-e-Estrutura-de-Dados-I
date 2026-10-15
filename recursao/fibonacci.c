#include <stdio.h>

int fibo(int a);

int main()
{
    int a;
    scanf("%d", &a);
    printf("%d", fibo(a));
    return 0;
}

int fibo(int a)
{
    if (a == 0)
        return 0;

    if (a == 1)
        return 1;

    int res = fibo(a - 1) + fibo(a - 2);

    return res;
}