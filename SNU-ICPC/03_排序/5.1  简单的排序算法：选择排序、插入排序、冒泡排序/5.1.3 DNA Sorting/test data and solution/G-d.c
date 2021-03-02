/* Copyright Derek Kisman (ACM ICPC ECNA 98) */


typedef struct {
	char str[100];
	int s;
} S;

S dna[1000];

int scmp( void *a, void *b ) {
	return ((S*)a)->s-((S*)b)->s;
}

main() {
	int i, j, k, x, y, z, n, m;

	scanf( " %d %d", &n, &m );
	for( i = 0; i < m; i++ ) scanf( " %s", dna[i].str );
	for( i = 0; i < m; i++ ) {
		x = 0;
		for( j = 0; j < n; j++ ) for( k = j+1; k < n; k++ )
			if( dna[i].str[j] > dna[i].str[k] ) x++;
		dna[i].s = x;
	}
	qsort( dna, m, sizeof( S ), scmp );
	for( i = 0; i < m; i++ ) {
		printf( "%s\n", dna[i].str );
	}
}
