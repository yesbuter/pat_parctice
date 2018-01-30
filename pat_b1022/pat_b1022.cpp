#include <cstdio>

int main()
{
    int a, b, d, quot, res;
    int result[31];
    int count = 0;
    scanf("%d %d %d", &a, &b, &d);
    quot = a + b;
    if(quot == 0)
        printf("0");
    while(quot != 0)
    {
        result[count] = quot % d;
        quot = quot / d;
        count++;
    }
    while(count--)
    {
        printf("%d", result[count]);
    }
    printf("\n");
    return 0;
}
