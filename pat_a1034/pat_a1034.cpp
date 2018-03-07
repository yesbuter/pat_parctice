#include <iostream>
#include <map>
#include <string>

using namespace std;

struct Node{
    int id, value;
};

const int MAXN = 2010;

int G[MAXN][MAXN] = {0};

int weight[MAXN];

int K;
int num = 0; //顶点数
int maxid = 0; //最大的id，记录head
int sum = 0; //边权的和
int count = 0; //图点计数

bool isvisit[MAXN] = {false};

map<string, int> head;

map<string, int> string2int;
map<int, string> int2string;

int func(string str)
{
    if(string2int.find(str) == string2int.end())
    {
        string2int[str] = num;
        int2string[num] = str;
        return num++;
    }
    else
    {
        return string2int[str];
    }
}

void DFS(int i)
{
    //cout << "===========" << i << endl;
    count++;
    isvisit[i] = true;
    maxid = weight[i] > weight[maxid] ? i : maxid ;
    //cout << " maxid " << maxid << " maxweight " << weight[maxid] << " now" << i << " weighti " << weight[i] << endl;
    //cout << "-sum-" << sum << endl;
    for(int j = 0; j < num; j++)
    {
        if(G[i][j] > 0)
        {
            sum += G[i][j];
            G[i][j] = G[j][i] = 0;
            if(isvisit[j] == false)
            {
                //sum += G[i][j];
                //cout << G[i][j] << " " << i << " " << j << endl;
                //cout << "--sum--" << sum << endl;
                DFS(j);
            }
        }
    }

    void DFSTrave()
    {
        for(int i = 0; i < num; i++)
        {
            if(!isvisit[i])
            {
                //cout << "----------" << i << endl;
                sum = 0;
                count = 0;
                maxid = i;
                DFS(i);
                //cout << "sum " << sum << " count " << count << " maxid " << maxid << endl;
                if(sum > K && count >2){
                    head[int2string[maxid]] = count;
                }
            }
    }
}

int main()
{
    int N;       //行数，判断gang的最大数字
    cin >> N >> K;
    
    string str1, str2;

    int value, id1, id2;
    for(int i = 0; i < N; i++)
    {
        cin >> str1 >> str2 >> value;
        id1 = func(str1);
        id2 = func(str2);
        G[id1][id2] += value;
        G[id2][id1] += value;
        weight[id1] += value;
        weight[id2] += value;
    }
    //cout <<"1111111111111111" << endl;
    DFSTrave();
    int size = head.size();
    //sort(head.begin(), sort.end(), cmp);
    cout << size << endl;
    for(map<string, int>::iterator it = head.begin(); it != head.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
}
