#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    double arry[1001] = {0};
    double coe;
    int exp;
    int num;
    int count = 0;
    while(cin >> num)
    {
        while(num--)
        {
            cin >> exp >> coe;
            if(arry[exp] == 0)
                count++;
            arry[exp] += coe;
            //关键操作，相加等于0的项要考虑到
            if(arry[exp] == 0)
                count--;
        }
    }

    cout << count;
    for(int i = 1000; i != -1; i--)
    {
        if(arry[i])
            //保留一位小数，刷题涉及到double最好还是用printf而不是double吧、
            printf(" %d %.1lf", i, arry[i]);
    }
    cout << endl;
    return 0;
}
