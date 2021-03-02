#include<stdio.h>
#include<stdlib.h>
#define MAX 2048
int i,j,k,m,n,count;
int volume;
int height[MAX];
int sums[MAX];
int intcmp(const void *p, const void *q) {
  return (*(int *)p)-(*(int *)q);
  }
int main() {
 scanf("%d %d",&m,&n);
 for (count=1; m||n; count++) {
  k=m*n;
  for (i=0; i<k; i++) scanf("%d",&height[i]);
  scanf("%d",&volume);
  scanf("%d %d",&m,&n);
  qsort(height,k,sizeof(int),intcmp);
  for (sums[0]=height[0],i=1; i<k; i++) sums[i]=sums[i-1]+height[i];
  for (i=1; (i<k)&&( (height[i]*i-sums[i-1])*100<volume ); i++);
  printf("Region %d\nWater level is %.2f meters.\n%.2f percent of the region is under water.\n\n",count,(volume/100.0+sums[i-1])/i,((float)i)*100/k);
  }
 return 0;
 }

