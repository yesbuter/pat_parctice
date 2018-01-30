#include <cstdio>
int main()
{
    int col = 0, row = 0;
    char letter;

    scanf("%d %c", &col, &letter);
    
    row = col / 2;
    if(col % 2 != 0)
        row += 1;
    
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(j >0 && j < col-1)
            {
                if(i > 0 && i < row -1)
                    printf(" ");
                else
                    printf("%c", letter);
            }
            else
                printf("%c", letter);
        }
        printf("\n");
    }
    return 0;
}
