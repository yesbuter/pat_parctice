#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
    int v, w; //v为序号，w为权重
    vector<int> child;
    //Node(){}
    Node(int v_, int w_) : v(v_), w(w_){}
};

vector<Node> tree;
vector<int> path;
int S;//给定的和

bool cmp(int a, int b)
{
    int aw = tree[a].w;
    int bw = tree[b].w;
    if(aw == bw)
        return a > b;
    else
        return aw > bw; 
}

void DFS(Node root, int sum)
{
    sum += root.w;
    path.push_back(root.w);
    if(sum > S)
    {
        path.pop_back();
        return;
    }
    if(root.child.size() == 0)   //到达叶子节点
    {
        if(sum == S)
        {
            cout << path[0];
            for(int i = 1; i < path.size(); i++)
                cout << " " << path[i];
            cout << endl;
        }
        path.pop_back();
        return;
    }
    for(int i = 0; i < root.child.size(); i++)
        DFS(tree[root.child[i]], sum);
    path.pop_back();
}

int main()
{
    int n, n_leaf;   //总节点数，非叶结点数，给定的和
    cin >> n >> n_leaf >> S;
    //scanf("%d %d %d", &n, &n_leaf, &S);

    int weight;

    //初始化所有结点序号和权重
    for(int i = 0; i < n; i++)
    {
        cin >> weight;
        //scanf("%d", &tree[i].w);
        Node node(i, weight);
        tree.push_back(node);
    }

    int f_v, c_num, c_v;    //非叶子结点，子节点数目，子节点序号
    for(int i = 0; i < n_leaf; i++)
    {
        cin >> f_v >> c_num;
        //scanf("%d %d", &f_v, &c_num);
        for(int j = 0; j < c_num; j++)
        {
            cin >> c_v;
            //scanf("%d", &c_v);
            tree[f_v].child.push_back(c_v);
        }
    }
    for(int i = 0; i < n; i++)
    {
        sort(tree[i].child.begin(), tree[i].child.end(), cmp);
    }
    DFS(tree[0], 0);
    return 0;
}
