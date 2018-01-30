#include <cstdio>
int main()
{
    int num;
    int step = 0;
    scanf("%d", &num);
    while(num != 1)
    {
        //奇数
        if((num % 2) != 0)
        {
            num = 3 * num + 1;
            num = num / 2;
        }
        else
            num = num / 2;
        step++;
    }
    printf("%d\n", step);
    return 0;
}
