#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct Card
{
    int pos;
    int num;
    char letter;
    Card(int pos_, int num_, char letter_)
    {
        pos = pos_;
        num = num_;
        letter = letter_;
    }
};

bool cmp(Card c1, Card c2)
{
    return c1.pos < c2.pos;
}

int main()
{
    int arry[54] = {0};
    vector<Card> c_vec;
    int time;
    int temp;
    cin >> time;
    int k = 0;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 13; j++)
        {
            cin >> temp;
            arry[k] = temp;
            if(i == 0)
            {
                Card card(k, j + 1, 'S');
                c_vec.push_back(card);
            }
            else if(i == 1)
            {
                Card card(k, j + 1, 'H');
                c_vec.push_back(card);
            }
            else if(i == 2)
            {
                Card card(k, j + 1, 'C');
                c_vec.push_back(card);
            }
            else if(i == 3)
            {
                Card card(k, j + 1, 'D');
                c_vec.push_back(card);
            }
            k++;
        }
    }
    cin >> arry[52];
    Card cardj1(k, 1, 'J');
    c_vec.push_back(cardj1);
    cin >> arry[53];
    Card cardj2(k + 1, 2, 'J');
    c_vec.push_back(cardj2);

    for(int i = 0; i < time; i++)
    {
        for(int j = 0; j < 54; j++)
            c_vec[j].pos = arry[j];
        sort(c_vec.begin(), c_vec.end(), cmp);
    }

    for(int i = 0; i < 53; i++)
        cout << c_vec[i].letter << c_vec[i].num << " ";
    cout << c_vec[53].letter << c_vec[53].num << endl;
    return 0;
}
