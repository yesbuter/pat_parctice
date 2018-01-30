#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a[80];
    int index = 0;
    while(cin >> a[index])
    {
        index++;
    }
    while(index--)
    {
        cout << a[index];
        if(index != 0)
            cout << " ";
        else
            cout << endl;
    }
    return 0;
}
