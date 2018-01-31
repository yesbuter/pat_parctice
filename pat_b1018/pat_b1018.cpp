#include <iostream>
#include <vector>

using namespace std;

struct Record
{
    char a;
    char b;
    char winner;
    char winletter;
    
    Record(char a_, char b_)
    {
        a = a_;
        b = b_;
        winner = 'b';
        if(a == b)
            winner = 'c';
        else if(a == 'C' && b == 'J')
            winner = 'a';
        else if(a == 'J' && b == 'B')
            winner = 'a';
        else if(a == 'B' && b == 'C')
            winner = 'a';
        if(winner == 'a')
            winletter = a;
        else if(winner == 'b')
            winletter = b;
        else
            winletter = 'H';
    }
};

char change(int i)
{
    if(i == 0)
        return 'B';
    if(i == 1)
        return 'C';
    if(i == 2)
        return 'J';
    return 'W';
}

int main()
{
    int num;
    char a, b;
    vector<Record> r_vec;
    
    int arry[3] = {0};
    int a_max[3] = {0};
    int b_max[3] = {0};

    int maxa = 0;
    int maxb = 0;

    cin >> num;
    for(int i = 0; i < num ; i++)
    {
        cin >> a >> b;
        Record record(a, b);
        r_vec.push_back(record);
    }

    for(int i = 0; i < num; i++)
    {
        if(r_vec[i].winner == 'a')
        {
            arry[0]++;
            if(r_vec[i].winletter == 'B')
                a_max[0]++;
            if(r_vec[i].winletter == 'C')
                a_max[1]++;
            if(r_vec[i].winletter == 'J')
                a_max[2]++;
        }
        else if(r_vec[i].winner == 'b')
        {
            arry[2]++;
            if(r_vec[i].winletter == 'B')
                b_max[0]++;
            if(r_vec[i].winletter == 'C')
                b_max[1]++;
            if(r_vec[i].winletter == 'J')
                b_max[2]++;
        }
        else if(r_vec[i].winner == 'c')
            arry[1]++;
    }
    for(int i = 0; i < 3; i++)
    {
        if(a_max[maxa] < a_max[i])
            maxa = i;
        if(b_max[maxb] < b_max[i])
            maxb = i;
    }
    for(int i = 0; i < 2; i++)
        cout << arry[i] << " ";
    cout << arry[2] << endl;
    for(int i = 2; i > 0; i--)
        cout << arry[i] << " ";
    cout << arry[0] << endl;
    cout << change(maxa) << " " << change(maxb) << endl;
}
