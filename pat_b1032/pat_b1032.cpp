#include <cstdio>

int main()
{
    int num = 0;
    int maxid = 0, max = 0;
    int sch_id, score;
    
    const int maxn = 100000;
    int school[maxn] = {0};
    
    scanf("%d", &num);
    
    int id[num] = {0};

    for(int i = 0; i < num; i++)
    {
        scanf("%d%d", &sch_id, &score);
        id[i] = sch_id;
        school[sch_id] += score;
    }
    for(int i = 0; i < num; i++)
    {
        if(school[id[i]] > max)
        {
            max = school[id[i]];
            maxid = id[i];
        }
        //printf("%d\n", id[i]);
    }

    printf("%d %d\n", maxid, max);

    return 0;
}
