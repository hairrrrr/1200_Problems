// Haab   365 days 
// 19 monthes  
//     [1, 18] (20 days)  name: pop, no, zip, zotz, tzec, xul, yoxkin, mol, chen, yax, 
//                                zac, ceh, mac, kankin, muan, pax, koyab, cumhu
//         days  0 to 19 

//     [19]   (5 days)    name: uayet 
//         0, 1, 2, 3, 4


// Tzolkin  thirteen periods, each 20 days long. year 360 
// They used 20 names: imix, ik, akbal, kan, chicchan, cimi, manik, lamat, muluk, ok, chuen, 
// eb, ben, ix, mem, cib, caban, eznab, canac, ahau and 13 numbers; both in cycles.
// 1 imix, 2 ik, 3 akbal,....

// Years (both Haab and Tzolkin) were denoted by numbers 0, 1, : : : , 
// where the number 0 was the beginning of the world. Thus, the first day was:

// Haab: 0. pop 0

// Tzolkin: 1 imix 0

// 1.一开始我使用的是 unordered_map 来存储 <const char*, int> 但是发现哈希表不能很好的存储 char* 到 int 的映射
// （开始是段错误，然后发现 haab[m] 总是 0）所以改用 <string, int> 来存储
// 经过思考找到问题所在，哈希表中存储的指针是 Haab 中的字符指针，而我们传入函数的 m 并不是这个指针，而是栈上开辟的临时变量 month 的地址
// 2. Tzolkin 计算错误，13 * 20 算成了 360 （淦--我真笨
// 3. POJ 上面 C++ 版本比价旧，不支持 unordered_map 所以改为 map

#include<cstdio>
#include<map>
#include<iostream>
#include<cstring>
#include<string>

using namespace std;

#define HAABDAYS 365
#define TZOLKINDAYS 260

const char* Haab[] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", 
                    "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};
const char* Tzolkin[] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", 
"muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};

map<const char*, int> haab;

int to_days(int y, const char* m, int d)
{
    int res = 0;
    res += y * HAABDAYS;
    // 天数从 0 计算
    res += d + 1;
    res += haab[m] * 20;
    return res;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    
    // 建立 Haab 月份名称到月的映射
    for(int i = 0; i < 19; ++i)
        haab[Haab[i]] = i;
        
    printf("%d\n", n);
    while(n--)
    {
        int day, year;
        char month[10];
        scanf("%d. %s %d", &day, month, &year);
        int days = to_days(year, month, day);
        //cout << "days = " << days << endl;
        // 能整除说明这一天是一年的最后一天
        // 360 % 360 = 0, 说明这是第 0 年的最后一天
        if(days % TZOLKINDAYS == 0)
        {
            day = 13;
            strcpy(month, Tzolkin[19]);
            year = (days / TZOLKINDAYS) - 1;
        }
        else
        {
            int _days = days % TZOLKINDAYS;
            day = (_days - 1) % 13 + 1;
            strcpy(month, Tzolkin[(_days - 1) % 20]);
            year = days / TZOLKINDAYS;
        }
        printf("%d %s %d\n", day, month, year);
    }

    return 0;
}

// 3
// 3 chuen 0
// 1 imix 0
// 9 cimi 2801

