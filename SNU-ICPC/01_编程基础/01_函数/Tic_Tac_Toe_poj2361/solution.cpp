// 本题关键：x 先手
// 在 poj 上提交可能会 wa 
// http://poj.org/problem?id=2361

#include<iostream>
#include<cstdio>

using namespace std;

char table[3][3];

inline bool win(char c)
{
    if(table[0][0] == c && table[0][1] == c && table[0][2] == c) return true;
    if(table[1][0] == c && table[1][1] == c && table[1][2] == c) return true;
    if(table[2][0] == c && table[2][1] == c && table[2][2] == c) return true;
    if(table[0][0] == c && table[1][0] == c && table[2][0] == c) return true;
    if(table[0][1] == c && table[1][1] == c && table[2][1] == c) return true;
    if(table[0][2] == c && table[1][2] == c && table[2][2] == c) return true;
    if(table[0][0] == c && table[1][1] == c && table[2][2] == c) return true;
    if(table[0][2] == c && table[1][1] == c && table[2][0] == c) return true;
    return false;

}

int main(void)
{
    int n;
    cin >> n;
    while(n--)
    {
        int xnum = 0, onum = 0;
        for(int i = 0; i < 3; ++i)
        {
            for(int j = 0; j < 3; ++j)
            {
                scanf(" %c", &table[i][j]);
                if(table[i][j] == 'X') xnum++;
                else if(table[i][j] == 'O') onum++;
            }
            int flg = 1;
            // x 和 o 不会同时获胜
            if(win('X') && win('O')) flg = 0;
            // x 不会比 o 多下 2 子，o 不会比 x 多下 1 子
            else if(xnum - onum >= 2 || xnum - onum < 0) flg = 0;
            // 如果 X 获胜，那么 X 数量比 O 多 1
            else if(win('X') && xnum - onum != 1) flg = 0;
            // 如果 O 获胜，那么 X 和 O 的数量相等
            else if(win('O') && xnum != onum) flg = 0;
            if(flg) printf("yes\n");
            else printf("no\n");
        }

    }

    return 0;
}