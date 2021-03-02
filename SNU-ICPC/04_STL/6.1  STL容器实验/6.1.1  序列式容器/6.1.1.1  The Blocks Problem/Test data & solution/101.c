
    
/**************
 solution to problem 2, Duke ACM Internet programming contest
 by: Owen Astrachan
 date: 10/19/90


 The solution here is certainly not the most efficient, but it is
 clear.  Each stack is maintained as a doubly linked list.

 An array of pointers, table[], is maintained such that table[i]
 points to block i (which may be in another blocks's stack).
 
**************/


#include <stdio.h>
#define MAXB 100                     /* maximum number of blocks */
    
typedef struct block{
	struct block *above;
	struct block *below;
	int name;
} block;

block blocks[MAXB];                  /* storage for the blocks */
block *table[MAXB];                  /* pointers to each block */
int numBlocks;	                     /* the actual number of blocks */


void
InitBlocks()
/* initially table[i] --> blocks[i], one block per stack */     
{
    int i;
    for(i=0;i<numBlocks;i++){
	blocks[i].name = i;
	blocks[i].above = (block *) NULL;
	blocks[i].below = (block *) NULL;
	table[i] = &blocks[i];
    }
}


block *
BlockTop(n)
     int n;
/* return a pointer to the block on top of the stack in which block */
/* n is located */     
{
    block *temp = table[n];

    while (temp->above != (block *) NULL){
	temp = temp->above;
    }
    return temp;
}


void
ClearStackAbove(n)
     int n;
/* return all blocks stacked above block n to their original spot */     
{
    block *top,*next;

    top = BlockTop(n);
    while (top != table[n]){	  /* until we reach block n */
	next = top->below;

	/* unlink block from stack */
	top->above = (block *) NULL;
	top->below = (block *) NULL;
	
	top = next;
    }
    table[n]->above = (block *) NULL;
}

void
MoveOnto(n,k)
     int n,k;
{
    ClearStackAbove(n);
    ClearStackAbove(k);
    table[k]->above = table[n];		/* move n onto k */
    if (table[n]->below)          	/* be safe when relinking */
	table[n]->below->above = (block *) NULL;
    table[n]->below = table[k];
}

void
PileOnto(n,k)
     int n,k;
{
    ClearStackAbove(k);
    table[k]->above = table[n];	    	/* move n onto k  */
    if (table[n]->below)		/* be safe when relinking */
	table[n]->below->above = (block *) NULL;
    table[n]->below = table[k];
}

int
IsOver(n,k)
     int n,k;
/* return 1 if block n is "over" block k (same stack), else 0 */     
{
    block *temp;

    temp = table[k];
    while (temp){
	if (temp->name == n)
	    return 1;
	temp = temp->above;
    }
    return 0;
}

    
void
MoveOver(n,k)
     int n,k;
{

    block *top;
    
    ClearStackAbove(n);
    top = BlockTop(k);			/* top of block k's stack */
    top->above = table[n];
    if (table[n]->below)    		/* be safe when relinking */
	table[n]->below->above = (block *) NULL;
    table[n]->below = top;
}

void
PileOver(n,k)
     int n,k;
{
    block *top;
    
    top = BlockTop(k);			/* top of block k's stack */
    top->above = table[n];	
    if (table[n]->below)    		/* be safe when relinking */
	table[n]->below->above = (block *) NULL;    
    table[n]->below = top;
}

main()
{

    char ch;
    int n,k;
    block *bottom;
    char b1[10],b2[10];	       	/* b1 = move/pile, b2 = onto/over */
    char *w1 = &b1[0];
    char *w2 = &b2[0];

    scanf("%d\n",&numBlocks);
    InitBlocks();
    while (1){
	scanf("%s",w1);
	if (w1[0] == 'q')   /* quit? */
	    break;
	scanf("%d %s %d\n",&n,w2,&k);

	/* is command a legal command? */
	if (n == k || IsOver(k,n) || IsOver(n,k)){
	    continue;
	}
	
	switch (w1[0]){
	  case 'm':
	    switch (w2[1]){
	      case 'n':	/* onto */
		MoveOnto(n,k);
		break;
	      case 'v':	/* over */
		MoveOver(n,k);
		break;
	      default:
		fprintf(stderr,"illegal command %s\n",w2);
	    }
	    break;
	  case 'p':
	    switch (w2[1]){
	      case 'n':	/* onto */
		PileOnto(n,k);
		break;
	      case 'v':	/* over */
		PileOver(n,k);
		break;
	      default:
		fprintf(stderr,"illegal command %s\n",w2);
	    }
	    break;
	  default:
	    fprintf(stderr,"illegal command %s\n",w2);
	}
    }

    /* print stacks */
    
    for(k=0;k<numBlocks;k++){
	printf("%2d: ",k);

	/* is block in another stack?, if so, nothing to print */
	
	if (table[k]->below != (block *) NULL){
	    printf("\n");
	}
	else{
	    bottom = table[k];
	    while (bottom){
		printf(" %d",bottom->name);
		bottom = bottom->above;
	    }
	    printf("\n");
	}
    }
    
}
