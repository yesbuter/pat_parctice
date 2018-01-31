#include <iostream>
using namespace std;

int main()
{
    int a1, a2, b1, b2;
    int num;
    int count[2] = {0, 0};
    cin >> num;
    while(num--)
    {
        cin >> a1 >> a2 >> b1 >> b2;
        if((a1 + b1) == a2 && (a1 + b1) != b2)
            count[1]++;
        if((a1 + b1) == b2 && (a1 + b1) != a2)
            count[0]++;
    }
    cout << count[0] << " " << count[1] << endl;
    return 0;
}
