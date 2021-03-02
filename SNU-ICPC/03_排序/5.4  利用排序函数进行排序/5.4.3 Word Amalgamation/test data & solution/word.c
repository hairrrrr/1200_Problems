/* 1998 ACM Mid-Central Regional Programming Contest
 * Problem 6: Word Amalgamation
 * by C.R. Van Dyke, Missouri Western
 */

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define DICTSIZE 0x64 /*maximum number of words in dictionary*/
#define WORDSIZE 0x07 /*maximum number of letters in word plus 1*/

/*define structures*/
typedef struct {
    char word[WORDSIZE];
	int  wordSize;
}dictType;

/*define global variables*/
FILE *input;
FILE *output;
dictType dictionary[DICTSIZE];


/* Scramble.c */

void alphabetizeDictionary(int numWords){
    int limit;
    int j;
    int swapped;
    dictType temp;

    for(limit=numWords-1;limit>0;limit--){
        swapped=0;
        for(j=0;j<limit;j++)
            if(strcmp(dictionary[j].word,dictionary[j+1].word)>=0){
                temp=dictionary[j];
                dictionary[j]=dictionary[j+1];
                dictionary[j+1]=temp;
                swapped=1;
            }/*end of if*/
        if(!swapped)
            break;
    }/*end of for loop*/
}/*void alphabetizeDictionary*/

int LoadDictionary(void){
    char temp[WORDSIZE];
    int i=0;
    fgets(temp,WORDSIZE+1,input);
    strcpy(dictionary[i].word,strtok(temp,"\n"));
    /*dictionary[i].word[WORDSIZE]='\0');*/
	dictionary[i].wordSize=strlen(dictionary[i].word);
    i++;
    while(strcmp(dictionary[i].word,"XXXXXX")&&i<=DICTSIZE){
        fgets(temp,WORDSIZE+1,input);
        strcpy(dictionary[i].word,strtok(temp,"\n"));
        dictionary[i].wordSize=strlen(dictionary[i].word);
		/*dictionary[i].word[WORDSIZE]='\0');*/
        if(!strcmp(dictionary[i].word,"XXXXXX"))
			break;
		i++;
    }/*end while loop*/
    
    alphabetizeDictionary(i);
    return i;
}/*LoadDictionary*/

int GetWord(char word[]){
    char temp[WORDSIZE];
	char tempLetter;
    int limit;
    int N;
    int j;
    int swapped;

    fgets(temp,WORDSIZE+1,input);
    strcpy(word,strtok(temp,"\n"));
	N=strlen(word);

    for(limit=N-1;limit>0;limit--){
        swapped=0;
        for(j=0;j<limit;j++)
            if(word[j]>word[j+1]){
                tempLetter=word[j];
                word[j]=word[j+1];
                word[j+1]=tempLetter;
                swapped=1;
            }/*end of if*/
        if(!swapped)
            break;
    }/*end of for loop*/
    return N;
}/*GetWord*/

void PrintOutput(char word[] ,int isWord){
    if(isWord)
        fprintf(output,"%s\n",word);
    else
        fprintf(output,"NOT A VALID WORD\n");
}/*PrintOutput*/

int CheckWord(char word[],int dictSize,int numletters){
    int i;
    int j=0;
    int k;
    int l;
	int q;
    int checked[WORDSIZE];
    int match=0;
	int flag=0;

    for(i=0;i<dictSize&&j<numletters;i++){
        while(word[j]<dictionary[i].word[0]&&j<numletters)
			j++;
		if(j>=numletters)
			break;
		while(word[j]>dictionary[i].word[0]&&i<dictSize)
			i++;
		if(i>=dictSize)
			break;
        for(q=0;q<numletters;q++)
            checked[q]=0;
        if(word[j]==dictionary[i].word[0]){
            if(dictionary[i].wordSize==numletters){
                checked[j]=1;
                for(k=1;k<numletters;k++)
                    for(l=0;l<numletters;l++)
                        if(dictionary[i].word[k]==word[l]&&!checked[l]){
                            checked[l]=1;
							break;
						}/*end of if*/
            }/*end of if*/
            match=1;
        }/*end of if*/
        for(k=0;k<numletters;k++)
            match*=checked[k];
        if(match){
           flag=1;
           PrintOutput(dictionary[i].word,match);
        }
    }/*end of for loop*/

    return flag;
}/*CheckWord*/

int main (){
    char     word[WORDSIZE];
    int  isWord;
    int dictSize;
	int wordSize;

    /*open input file*/
    input=fopen("word.in","r");
    assert(input);
    
    dictSize=LoadDictionary();

    /*open output file*/
    output=fopen("word.out","wt");
    assert(output);

    wordSize=GetWord(word);
    
	while(strcmp(word, "XXXXXX") != 0){
        isWord=CheckWord(word,dictSize,wordSize);
		if(!isWord)
		    PrintOutput(word,isWord);
		fprintf(output,"******\n");
        wordSize=GetWord(word);
    }/* end while loop*/
    /*close files*/
    fclose(input);
    fclose(output);
    return 0;
}
