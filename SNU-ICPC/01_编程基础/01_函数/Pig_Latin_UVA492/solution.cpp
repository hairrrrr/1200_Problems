#include<cstdio>
#include<string>
#include<iostream>

using namespace std;

inline bool isVowel(char c)
{
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
    if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') return true;
    return false;
}

inline bool isLetter(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int main(void)
{
    string s;
    // 按行读取
    while(getline(cin, s))
    {
        int len = s.length();
        for(int i = 0; i < len; )
        {
            // 如果是字母判断是否是元音字母
            if(isLetter(s[i]))
            {
                if(isVowel(s[i]))
                {
                    // 输出整个单词，尾部加上 ay
                    while(isLetter(s[i])) printf("%c", s[i++]);
                    printf("ay");
                }
                else
                {
                    // 保存第一个字符
                    char first = s[i];
                    ++i;
                    while(isLetter(s[i])) printf("%c", s[i++]);
                    // 尾部加上第一个字符和ay
                    printf("%cay", first);
                }
            }
            // 不是字母直接输出并且 i++
            else
                printf("%c", s[i++]);
        }
        // 输出行尾换行
        printf("\n");
    }

    return 0;
}