#include <stdio.h>
#include <stdlib.h>

int i,j,k,len,m;
char f[100];

main(){
   for (len=1,m=10;len < 10;len++,m*=10){
      for (i=0;i<10;i++) {
         sprintf(f,"0.%%0%dd...\n",len);
         printf(f,random()%m);
      }
      if (len == 1000000000) break;
   }
   printf("0\n");
}
