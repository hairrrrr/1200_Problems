#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT "orders.in"
#define OUTPUT "orders.out"

#define MAXSIZE 300
#define CHARS 26

char Word[MAXSIZE];	/* Vstupni/vystupni slovo */
int CC[CHARS];		/* Pocty jednotlivych znaku */
int Len;		/* Delka vstupniho slova */
FILE *Out;		/* Vystupni soubor */

/* Nacte vstup */
void ReadInp(void)
{
  FILE *In;

  if (!(In = fopen(INPUT, "r")))
  {
    puts("Can't open input file.");
    exit(1);
  }
  fgets(Word, MAXSIZE, In);
  fclose(In);
  Len = strlen(Word) - 1;
  Word[Len] = '\0';	/* Smazeme konec radku */
}

/* Spocte pocty znaku ve vstupnim slove */
void ParseInp(void)
{
  int i;

  memset(CC, 0, CHARS);
  for (i = 0; i < Len; i++)
    CC[Word[i]-'a']++;
}

/* Vytiskne vsechny anagramy */
void Anagram(int Done)
{
  int i;

  for (i = 0; i < CHARS; i++)
    if (CC[i])	/* Nepouzity znak? */
    {
      Word[Done] = 'a' + i;
      if (Done == Len - 1)	/* Pouzili jsme posledni znak? */
      {
        /* Vypiseme radek */
        Word[Len] = '\n';
        Word[Len+1] = '\0';
        fputs(Word, Out);
      }
      else
      {
        /* Rekurzivne zkousime dalsi znaky */
        CC[i]--;
        Anagram(Done + 1);
        CC[i]++;
      }
    }
}

int main(void)
{
  ReadInp();	/* Nacte vstup */
  ParseInp();	/* Spocte pocty znaku ve vstupnim slove */
  if (!(Out = fopen(OUTPUT, "w")))
  {
    puts("Can't open output file.");
    return 1;
  }
  Anagram(0);	/* Vypise vsechny anagramy */
  fclose(Out);
  return 0;
}

