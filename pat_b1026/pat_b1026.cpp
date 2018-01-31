#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    const int CLK_TCK = 100;
    int c1, c2;
    int second, minute, hour;
    
    cin >> c1 >> c2;
    
    second = (c2 - c1) / CLK_TCK;

    if(((c2 - c1) % CLK_TCK) >= 50)
        second++;
    
    minute = second / 60;
    second = second - minute * 60;
    hour = minute / 60;
    minute = minute - hour * 60;
    
    printf("%02d:%02d:%02d\n", hour, minute, second);
    return 0;
}
