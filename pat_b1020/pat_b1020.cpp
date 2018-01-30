#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Mooncake
{
    double store;
    double price;
    double s_price;
    
    Mooncake(){}

    Mooncake(double store_)
    {
        store = store_;
    }
};

bool cmp(Mooncake mc1, Mooncake mc2)
{
    return mc1.s_price > mc2.s_price;
}

int main()
{
    std::ios::sync_with_stdio(false);

    int type;
    double require;
    vector<Mooncake> mc_vec;
    double store, price;
    int count = 0;
    double result = 0;

    cin >> type >> require;
    
    for(int i = 0; i < type; i++)
    {
        cin >> store;
        Mooncake mooncake(store);
        mc_vec.push_back(mooncake);
    }

    for(int i = 0; i< type; i++)
    {
        cin >> price;
        mc_vec[i].price = price;
        mc_vec[i].s_price = price / mc_vec[i].store;
    }

    sort(mc_vec.begin(), mc_vec.end(), cmp);

    for(int i = 0; i < type; i++)
    {
        if((require - count) <= mc_vec[i].store)
        {
            result += (require - count) * mc_vec[i].s_price;
            break;
        }
        else
        {
            result += mc_vec[i].price;
            count += mc_vec[i].store;
        }
    }

    cout << fixed << setprecision(2) << result << endl;
    
    return 0;
}
