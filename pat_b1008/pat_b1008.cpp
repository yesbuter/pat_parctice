#include <iostream>
#include <vector>

using namespace std;

void convert(vector<int>::iterator begin, vector<int>::iterator end)
{
    int temp;
    while(begin < end)
    {
        temp = *begin;
        *begin = *(end - 1);
        *(end - 1) = temp;
        begin++;
        end--;
    }
}

int main()
{
    int n, m, temp;
    vector<int> vi;
    cin >> n >> m;
    m = m % n;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        vi.push_back(temp);
    }
    m = n - m;
    vector<int>::iterator it = vi.begin();
    convert(it, it + m);
    convert(it + m, vi.end());
    convert(vi.begin(), vi.end());

    for(int i = 0; i < n; i++)
    {
        cout << vi[i];
        if(i != n - 1)
            cout << " ";
    }
    cout << endl;
    return 0;
}
