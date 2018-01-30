#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct StudentInfo
{
    string id;
    int score;
    int l_id;
    int l_rank;
    int rank;

    StudentInfo(string id_, int score_, int l_id_)
    {
        id = id_;
        score = score_;
        l_id = l_id_;
    }
};

bool cmp(StudentInfo a, StudentInfo b)
{
    if(a.score != b.score)
        return a.score > b.score;
    else
        return a.id < b.id;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int l_num;
    int s_num;
    string id;
    int score;
    vector<StudentInfo> s_vec;
    vector<StudentInfo>::iterator it;
    cin >> l_num;
    for(int i = 0; i < l_num; i++)
    {
        cin >> s_num;
        for(int j = 0; j < s_num; j++)
        {
            cin >> id >> score;
            StudentInfo student(id, score, i + 1);
            s_vec.push_back(student);
        }
        it = s_vec.end() - s_num;
        sort(it, s_vec.end(), cmp);
        for(int k = 1; it != s_vec.end(); it++, k++)
        {
            if(k != 1)
            {
                if((it->score) != (it - 1)->score)
                    it->l_rank = k;
                else
                    it->l_rank = (it - 1)->l_rank;
            }
            else
                it->l_rank = k;
        }
    }
    sort(s_vec.begin(), s_vec.end(), cmp);
    it = s_vec.begin();
    cout << s_vec.end() - s_vec.begin() << endl;
    for(int h = 1; it != s_vec.end(); it++, h++)
    {
        if(h != 1)
        {
            if((it->score) != (it - 1)->score)
                it->rank = h;
            else
                it->rank = (it - 1)->rank;
        }
        else
            it->rank = h;
        cout << it->id << " " << it->rank << " " << it->l_id << " " << it->l_rank << endl;
    }
    return 0;
}
