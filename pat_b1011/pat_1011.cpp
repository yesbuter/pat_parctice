#include <iostream>
#include <vector>

using namespace std;

class Case
{
private:
    long long a, b, c;
    int id;
public:
    Case(long long a_, long long b_, long long c_, int id_)
    {
        a = a_;
        b = b_;
        c = c_;
        id = id_;
    }

    void Output()
    {
        cout << "Case #" << id << ": " << boolalpha << ((a + b) > c) << endl;
    }
};

int main()
{
    int input_num;
    long long a, b, c;
    vector<Case> c_vec;
    cin >> input_num;
    for(int i = 0; i < input_num; i++)
    {
        cin>> a >> b >> c;
        Case ca(a, b, c, i + 1);
        c_vec.push_back(ca);
    }
    for(int i = 0; i < input_num; i++)
    {
        c_vec[i].Output();
    }
    return 0;
}
