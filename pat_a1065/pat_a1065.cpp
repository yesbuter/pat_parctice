#include <iostream>
#include <vector>

using namespace std;

//判断是否同号
bool func(long long a, long long b)
{
    if(a > 0)
    {
        if(b > 0)
            return true;
        return false;
    }
    else
    {
        if(b < 0)
            return true;
        return false;
    }
}

//判断有没有=0的元素
bool func2(long long a, long long b, long long c)
{
    return (a == 0 || b == 0 || c == 0);
}


//有0元素时做出判断
bool func3(long long a, long long b, long long c)
{
    if(a == 0)
        return b > c;
    if(b == 0)
        return a > c;
    if(c == 0)
    {
        if(func(a, b))
        {
            if(a > 0)
                return true;
            else
                return false;
        }
        else
            return a + b > 0;
    }
}

//没0元素时判断
bool func4(long long a, long long b, long long c)
{
    bool res = false;
    if(!func(a, b))
        res = (a + b) > c;
    else
    {
        if(func(b, c))
            res = (c - b) < a;
        else
        {
            if(c < 0)
                res = true;
        }
    }
    return res;
}
struct Case
{
    int id;
    bool res;
    Case(long long a, long long b, long long c, int i)
    {
        id = i;
        if(func2(a, b, c))
            res = func3(a, b, c);
        else
            res = func4(a, b, c);
    }
};

int main()
{
    long long a, b, c;
    int t;
    vector<Case> c_vec;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        cin >> a >> b >> c;
        Case cs(a, b, c, i + 1);
        c_vec.push_back(cs);
    }

    for(int i = 0; i < t; i++)
        cout << "Case #" << c_vec[i].id << ": " << boolalpha << c_vec[i].res << endl;
    return 0;
}


