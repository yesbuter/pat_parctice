#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int v1;
    int v2;
    //最短距离
    int s_dt;

    Node(int begin_, int end_, int s_dt_)
    {
        v1 = begin_;
        v2 = end_;
        s_dt = s_dt_;
    }
};


int main()
{
    std::ios::sync_with_stdio(false);
    vector<int> dt_v;
    vector<Node> n_v;
    int temp, v1, v2, b2e, e2b;
    int num_n, num_m;
    int sum = 0;

    dt_v.push_back(0);

    cin >> num_n;
    while(num_n--)
    {
        cin >> temp;
        //关键步骤
        //不存距离而是存1-v点的距离，省一个循环
        //否则有超时错误
        dt_v.push_back(sum);
        sum += temp;
    }

    cin >> num_m;
    while(num_m--)
    {
        b2e = 0;
        cin >> v1 >> v2;
        
        if(v1 > v2){
            temp = v1;
            v1 = v2;
            v2 = temp;
        }

        //for(int i = v1; i < v2; i++)
        b2e = dt_v[v2] - dt_v[v1];
        
        e2b = sum - b2e;

        Node node(v1, v2, ((b2e < e2b) ? b2e : e2b));
        
        n_v.push_back(node);
    }

    for(int i = 0; i < n_v.size(); i++)
        /*
    {
        b2e = 0;
        for(int j = n_v[i].v1; j < n_v[i].v2; j++)
            b2e += dt_v[j];
        e2b = sum - b2e;
        cout << ((b2e < e2b) ? b2e : e2b) << endl;
    }*/
        cout << n_v[i].s_dt << endl;
    return 0;
}
