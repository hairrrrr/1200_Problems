#include <stdio.h>
#include <stdlib.h>

struct ddd {
   char eng[12], pig[12];
} d[100000];

int nd, i,j,k;
char buf[10000];

compar(struct ddd *a, struct ddd *b) {
   return strcmp(a->pig, b->pig);
}

main(){
   while (gets(buf) && buf[0]) {
      sscanf(buf,"%s %s",d[nd].eng,d[nd].pig);
      nd++;
   }
   qsort(d,nd,sizeof(struct ddd),compar);
   while (gets(buf)) {
      struct ddd b, *p;
      strcpy(b.pig,buf);
      p = bsearch(&b,d,nd,sizeof(struct ddd),compar);
      if (p != NULL) printf("%s\n",p->eng);
      else printf("eh\n");
   }
}
