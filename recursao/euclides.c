#include <stdio.h>

int mdc(int a, int b);

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int res = mdc(a, b);
    printf("%d", res);
    return 0;
}

int mdc(int a, int b)
{
    if (b == 0)
        return a;

    int res = mdc(b, a % b);

    return res;
}