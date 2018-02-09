#include <iostream>
#include <vector>

using namespace std;

int main()
{
    double arry[1001] = {0};
    double res[2001] = {0};
    int exp;
    double coe;
    int num;
    int count = 0;

    cin >> num;
    while(num--)
    {
        cin >> exp >> coe;
        arry[exp] += coe;
    }

    cin >> num;
    while(num--)
    {
        cin >> exp >> coe;
        for(int i = 1000; i != -1; i--)
        {
            if(arry[i] != 0)
            {
                if(res[exp + i] == 0)
                    count++;
                res[exp + i] += coe * arry[i];
                if(res[exp + i] == 0)
                    count--;
            }
        }
    }

    cout << count;
    for(int i = 2000; i != -1; i--)
    {
        if(res[i])
            printf(" %d %.1lf", i, res[i]);
            //cout << " " << i << " " << res[i];
    }
    cout << endl;
    return 0;
}
