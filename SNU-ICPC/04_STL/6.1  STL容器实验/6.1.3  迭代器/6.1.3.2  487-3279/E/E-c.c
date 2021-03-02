/* Copyright Charlie Clarke (ACM ICPC ECNA 1999) */

#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <ctype.h>

char pn[100000][8];

main ()
{
  int i, j, n, c;
  int none = 1;

  scanf ("%d", &n);
  for (i = 0; i < n; i++)
    {
      j = 0;
      while (j < 7)
	{
	  if (!isalnum (c = getchar ())) continue;
	  if (c == 'A' || c == 'B' || c == 'C') c = '2';
	  if (c == 'D' || c == 'E' || c == 'F') c = '3';
	  if (c == 'G' || c == 'H' || c == 'I') c = '4';
	  if (c == 'J' || c == 'K' || c == 'L') c = '5';
	  if (c == 'M' || c == 'N' || c == 'O') c = '6';
	  if (c == 'P' || c == 'R' || c == 'S') c = '7';
	  if (c == 'T' || c == 'U' || c == 'V') c = '8';
	  if (c == 'W' || c == 'X' || c == 'Y') c = '9';
	  pn[i][j++] = c;
	}
      pn[i][7] = '\0';
    }

  qsort (pn, n, 8, (int (*) (const void *, const void *)) strcmp);

  j = 0;
  for (i = 1; i < n; i++)
  {
    if (strcmp (pn[i], pn[j]) != 0)
      {
	if (i - j > 1)
	  {
	    printf (
	      "%c%c%c-%s %d\n", pn[j][0], pn[j][1], pn[j][2], pn[j] + 3, i - j
	    );
	    none = 0;
	  }
	j = i;
      }
  }
  if (i - j > 1)
    {
      printf (
	"%c%c%c-%s %d\n", pn[j][0], pn[j][1], pn[j][2], pn[j] + 3, i - j
      );
      none = 0;
    }
  if (none)
    printf ("No duplicates.\n");
}
