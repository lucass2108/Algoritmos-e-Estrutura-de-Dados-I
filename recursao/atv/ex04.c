#include <stdio.h>

int soma(int n)
{
    if (n <= 0)
        return 0;

    int res = n;
    res += soma(n - 1);

    return res;
}

int main()
{
    int n, res = 0;
    scanf("%d", &n);

    for (int i = 0; i <= n; i++)
    {
        res += i;
    }

    printf("%d\n%d", res, soma(n));

    return 0;
}