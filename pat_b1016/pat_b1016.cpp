#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string func(string a, char da, string pa)
{
    for(int i = 0; i < a.length(); i++)
    {
        if(a[i] == da)
            pa.push_back(da);
    }
    return pa;
}

int s2i(string a)
{
    stringstream stream(a);
    int result = 0;
    if(a != "")
    {
        stream >> result;
    }
    return result;
}

int main()
{
    string a, b;
    char da, db;
    string pa = "";
    string pb = "";
    cin >> a >> da >> b >> db;
    pa = func(a, da, pa);
    pb = func(b, db, pb);
    //cout << pa << " " << pb << endl;
    //cout << s2i(pa) << " " << s2i(pb) << endl;
    cout << s2i(pa) + s2i(pb) << endl;
    return 0;
}
