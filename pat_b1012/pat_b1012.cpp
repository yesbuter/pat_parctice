#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main()
{
    int a[5] = {0};
    vector<int> vi;
    int len;
    int temp;
    bool flag = true;
    bool flag2 = false;
    int count = 0;
    cin >> len;
    for(int i = 0; i < len; i++)
    {
        cin >> temp;
        vi.push_back(temp);
    }
    for(int i = 0; i < len; i++)
    {
        if(vi[i] % 5 == 0 && vi[i] % 2 == 0)
            a[0] += vi[i];
        if(vi[i] % 5 == 1)
        {
            if(!flag2)
                flag2 = true;
            if(flag)
                a[1] += vi[i];
            else
                a[1] -= vi[i];
            flag = !flag;
        }
        if(vi[i] % 5 == 2)
            a[2]++;
        if(vi[i] % 5 == 3)
        {
            count++;
            a[3] += vi[i];
        }
        if(vi[i] % 5 == 4)
        {
            if(vi[i] > a[4])
                a[4] = vi[i];
        }
    }
    for(int i = 0; i < 5; i++)
    {
        if(a[i] == 0)
        {
            if(i == 1 && flag2)
                printf("0");
            else
                printf("N");
        }
        else if(i == 3)
            printf("%.1lf", double(a[3]) / double(count));
        else
            printf("%d", a[i]);
        if(i != 4)
            printf(" ");
    }
    printf("\n");
    return 0;
}
