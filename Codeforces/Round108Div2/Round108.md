## A. Red and Blue Beans

time limit per test 1 second

memory limit per test 256 megabytes

You have r red and b blue beans. You'd like to distribute them among several (maybe, one) packets in such a way that each packet:

- has at least one red bean (or the number of red beans ri≥1);
- has at least one blue bean (or the number of blue beans bi≥1);
- the number of red and blue beans should differ in no more than d (or |ri−bi|≤d)

Can you distribute all beans?

#### Input

The first line contains the single integer t  (1≤t≤1000) — the number of test cases.

The first and only line of each test case contains three integers r, b, and d (1≤r,b≤1091≤r,b≤109; 0≤d≤1090≤d≤109) — the number of red and blue beans and the maximum absolute difference in each packet.

#### Output

For each test case, if you can distribute all beans, print YES. Otherwise, print NO.

You may print every letter in any case you want (so, for example, the strings yEs, yes, Yes and YES are all recognized as positive answer).

####  Example

input

```
4
1 1 0
2 7 3
6 1 4
5 4 0
```

output

```
YES
YES
NO
NO
```



```cpp
#include<iostream>
#include<cstdio>
 
using namespace std;
 
int main()
{
    int n;
    cin >> n;
    
    while(n--)
    {
        int r, b, d;
        
        cin >> r >> b >> d;
        
        int num = min(r, b);
        int diff = abs(r - b);
        
        if(diff == 0) printf("YES\n");
        else if(d == 0) printf("NO\n");
        else
        {
            int x = diff / num;
            if(diff % num) x++;
            if(x > d) printf("NO\n");
            else printf("YES\n");
        }
    }

    return 0;
}
```



## B. The Cake Is a Lie

time limit per test 2 seconds

memory limit per test 256 megabytes

There is a n×m grid. You are standing at cell (1,1) and your goal is to finish at cell (n,m).

You can move to the neighboring cells to the right or down. In other words, suppose you are standing at cell (x,y)(x,y). You can:

- move right to the cell (x,y+1) — it costs x burles;
- move down to the cell (x+1,y) — it costs y burles.

Can you reach cell (n,m)(n,m) spending **exactly** k burles?

#### Input

The first line contains the single integer t (1≤t≤100) — the number of test cases.

The first and only line of each test case contains three integers n, m, and k (1≤n,m≤100; 0≤k≤10^4) — the sizes of grid and the exact amount of money you need to spend.

#### Output

For each test case, if you can reach cell (n,m)(n,m) spending **exactly** k burles, print YES. Otherwise, print NO.

You may print every letter in any case you want (so, for example, the strings yEs, yes, Yes and YES are all recognized as positive answer).

#### Example

input

```
6
1 1 0
2 2 2
2 2 3
2 2 4
1 4 3
100 100 10000
```

output

```
YES
NO
YES
NO
YES
NO
```

Note

In the first test case, you are already in the final cell, so you spend 0 burles.

In the second, third and fourth test cases, there are two paths from (1,1) to (2,2): (1,1) → (1,2) → (2,2) or (1,1) → (2,1) → (2,2). Both costs 1+2=3 burles, so it's the only amount of money you can spend.

In the fifth test case, there is the only way from (1,1 to (1,4) and it costs 1+1+1=3 burles.



```cpp
#include<iostream>
#include<cstdio>
 
using namespace std;
 
int main()
{
    int n;
    cin >> n;
    
    while(n--)
    {
        int a, b, k;
        cin >> a >> b >> k;
        
        if((a - 1) + (b - 1) * a == k) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    return 0;
}
```





## C. Berland Regional

time limit per test 2 seconds

memory limit per test 256 megabytes

Polycarp is an organizer of a Berland ICPC regional event. There are n universities in Berland numbered from 1 to n. Polycarp knows all competitive programmers in the region. There are n students: the i-th student is enrolled at a university ui and has a programming skill si.

Polycarp has to decide on the rules now. In particular, the number of members in the team.

Polycarp knows that if he chooses the size of the team to be some integer k, each university will send their k strongest (with the highest programming skill s) students in the first team, the next k strongest students in the second team and so on. If there are fewer than k students left, then the team can't be formed. Note that there might be universities that send zero teams.

The strength of the region is the total skill of the members of all present teams. If there are no teams present, then the strength is 00.

Help Polycarp to find the strength of the region for each choice of k from 1 to n.

Input

The first line contains a single integer t (1≤t≤1000) — the number of testcases.

The first line of each testcase contains a single integer n (1≤n≤2⋅10^5) — the number of universities and the number of students.

The second line of each testcase contains n integers u1,u2,…,un (1≤ui≤n) — the university the i-th student is enrolled at.

The third line of each testcase contains n integers s1,s2,…,sn (1≤si≤10^9) — the programming skill of the i-th student.

The sum of n over all testcases doesn't exceed 2⋅1052⋅105.

Output

For each testcase print n integers: the strength of the region — the total skill of the members of the present teams — for each choice of team size k.

Example

input

Copy

```
4
7
1 2 1 2 1 2 1
6 8 3 1 5 1 5
10
1 1 1 2 2 2 2 3 3 3
3435 3014 2241 2233 2893 2102 2286 2175 1961 2567
6
3 3 3 3 3 3
5 9 6 7 9 7
1
1
3083
```

output

Copy

```
29 28 26 19 0 0 0 
24907 20705 22805 9514 0 0 0 0 0 0 
43 43 43 32 38 43 
3083 
```

Note

In the first testcase the teams from each university for each k are:

- k=1:
  - university 1: `[6],[5],[5],[3]`;
  - university 2: `[8],[1],[1]`;
- k=2:
  - university 1: `[6,5]`;
  - university 2: `[8,1]`;
- k=3:
  - university 1:` [6,5,5]`;
  - university 2: `[8,1,1]`;
- k=4
  - university 1: `[6,5,5,3]`;



```cpp

```

