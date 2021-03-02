#include <stdio.h>
#include <stdlib.h>

#define SZ 100000

struct ddd {
   char eng[12], pig[12];
} d[SZ];

main(){
   int i;
   char buf[1000];
   for (i=0;i<SZ;i++) {
      sprintf(buf,"%c%c%c%c",i%26+'a',i/26%26+'a',i/26/26%26+'a',i/26/26/26%26+'a');
      sprintf(d[i].eng,"eeeeee%s",buf);
      sprintf(d[i].pig,"pppppp%s",buf);
      printf("%s %s\n",d[i].eng, d[i].pig);
   }
   printf("\n");
   for (i=0;i<SZ;i++) {
      if (random()%10 == 1) printf("%s\n",d[random()%SZ].eng);
      else printf("%s\n",d[random()%SZ].pig);
   }
}
