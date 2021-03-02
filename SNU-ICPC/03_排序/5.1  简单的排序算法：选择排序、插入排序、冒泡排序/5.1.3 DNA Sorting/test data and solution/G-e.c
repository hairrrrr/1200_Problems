/* Copyright Edmund Dengler (ACM ICPC ECNA 98) */


#include <stdio.h>

#define DEBUG 1

void
getit( char * buf, int len )
{
	fgets( buf, len, stdin );
	if ( feof( stdin ) )
	{
		printf( "ERROR: Input ended too early\n" );
		exit( -1 );
	}
}

int
main()
{
	char buf [200];
	int n;
	int i;

	int N;
	int M;
	char string [200][200];
	int sortedness [200];
	int index [200];

	getit( buf, 199 );
	n = sscanf( buf, "%d %d", &N, &M );

	for ( i = 0; i < M; i += 1 )
	{
		int seen [4];
		int j, j2, k;

		index [i] = i;
		sortedness [i] = 0;

		for ( j = 0; j < 4; j += 1 )
		{
			seen [j] = 0;
		}

		getit( string [i], 199 );

		for ( j2 = 0; j2 < N; j2 += 1 )
		{
			switch ( string [i][j2] )
			{
			case 'A': j = 0; break;
			case 'C': j = 1; break;
			case 'G': j = 2; break;
			case 'T': j = 3; break;
			default:
				printf( "ERROR: invalid character in string %d\n", i );
				exit( -1 );
			}
			for ( k = j+1; k < 4; k += 1 )
			{
				sortedness [i] += seen [k];
			}
			seen [j] += 1;
		}
	}

	for ( i = 0; i < M; i += 1 )
	{
		int j;

		for ( j = i+1; j < M; j += 1 )
		{
			if ( sortedness [index [i]] > sortedness [index [j]] )
			{
				int t = index [i];
				index [i] = index [j];
				index [j] = t;
			}
		}
	}

	for ( i = 0; i < M; i += 1 )
	{
		printf( "%s", string [index [i]] );
	}
}
