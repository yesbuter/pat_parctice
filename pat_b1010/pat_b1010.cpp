#include <iostream>
#include <vector>

using namespace std;

struct Term
{
    int coefficient, a_coefficient, exponent, a_exponent;

    Term(int coefficient_, int exponent_)
    {
        coefficient = coefficient_;
        exponent = exponent_;

        if(exponent == 0)
        {
            a_exponent = 0;
            a_coefficient = 0;
        }

        else
        {
            a_exponent = exponent - 1;
            a_coefficient = exponent * coefficient;
        }
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    int exp, coe;
    vector<Term> t_v;
    //计算系数不为0的个数，如果都为0，输出0 0 
    int count = 0;

    while(cin >> coe >> exp)
    {
        Term term(coe, exp);
        t_v.push_back(term);
    }

    for(int i = 0; i < t_v.size(); i++)
    {
        if(t_v[i].a_coefficient != 0)
        {
            count++;
            if(i != 0)
                cout << " ";
            cout << t_v[i].a_coefficient << " " << t_v[i].a_exponent;
        }
    }
    if(!count)
        cout << "0 0";
    cout << endl;

    return 0;
}
