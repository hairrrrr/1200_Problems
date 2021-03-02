http://poj.org/problem?id=1579

#include<cstdio>

int w[21][21][21];

int f(int a, int b, int c)
{
    if(a <= 0 || b <= 0 || c <= 0) return 1;
    if(a > 20 || b > 20 || c > 20) 
        return f(20, 20, 20);
    if(w[a][b][c]) 
        return w[a][b][c];
    if(a < b && b < c) 
        return w[a][b][c] = f(a, b, c-1) + f(a, b-1, c-1) - f(a, b-1, c);
    else 
        return w[a][b][c] = f(a-1, b, c) + f(a-1, b-1, c) + f(a-1, b, c-1) - f(a-1, b-1, c-1);
}

int main(void)
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    while(a != -1 || b != -1 || c != -1)
    {
        printf("w(%d, %d, %d) = %d\n", a, b, c, f(a, b, c));
        scanf("%d%d%d", &a, &b, &c);
    }

    return 0;
}