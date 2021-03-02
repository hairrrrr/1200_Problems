http://poj.org/problem?id=1581

#include<cstdio>
#include<cstring>

char win_name[100];
int win_ac = INT_MIN;
int win_pan = INT_MAX;

int main(void)
{
    int n;
    scanf("%d", &n);
 
   
    while(n-- > 0)
    {
        char name[100];
        int sub[4] = {0}, time[4] = {0};
        scanf("%s %d %d %d %d %d %d %d %d", name, &sub[0], &time[0], 
        &sub[1], &time[1], &sub[2], &time[2], &sub[3], &time[3]); 
        
        int ac = 0, time = 0;
        for(int i = 0; i < 4; ++i)
        {
            if(time[i])
            {
                ++ac;
                time += time[i];
                if(sub[i] > 1) time += 40;
            } 
        }
        
        if(ac > win_ac || ac == win_ac && time < win_time)
        {
            win_ac = ac;
            win_pan = time;
            strcpy(win_name, name);
        }
    }

    printf("%s %d %d\n", win_name, win_ac, win_pan);

    return 0;
}