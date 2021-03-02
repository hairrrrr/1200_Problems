#include<stdio.h>
#include<stdlib.h>
#define rnd(p) (random()%(p))
#define N 250
int i,j,k;
int r,c;
int main() {
 for (i=0; i<N; i++) {
	r=1+rnd(30);
	c=1+rnd(30);
	printf("%d %d\n",r,c);
	for (j=0; j<r; j++)
		for (k=0; k<c; k++)
			printf(k==c-1?"%d\n":"%d ",-10+rnd(191));
	printf("%d\n",1+rnd(25000));
	}
 printf("0 0\n");
 return 0;
 }
