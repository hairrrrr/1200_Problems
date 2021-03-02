/* Copyright Derek Kisman (ACM ICPC ECNA 1999) */

char map[26] = {'2', '2', '2', '3', '3', '3', '4', '4', '4',
				'5', '5', '5', '6', '6', '6', '7', 0, '7', '7', '8', '8', '8', '9', '9', '9', 0};

char ph[100000][9];
int nph;

char buf[1000];

main() {
	int i, j, k, x, y, z, n;
	char ch;

	memset( ph, 0, sizeof(ph) );
	scanf( " %d", &nph );
	for( i = 0; i < nph; i++ ) {
		scanf( " %s", buf );
		x = 0;
		for( j = 0; buf[j]; j++ ) {
			if( buf[j] == '-' ) continue;
			if( buf[j] >= 'A' && buf[j] <= 'Z' ) buf[j] = map[buf[j]-'A'];
			ph[i][x++] = buf[j];
			if( x == 3 ) ph[i][x++] = '-';
		}
	}
	qsort( ph, nph, 9, strcmp );
	x = 1; z = 0;
	for( i = 1; i < nph; i++ ) {
		if( strcmp( ph[i-1], ph[i] ) ) {
			if( x > 1 ) {
				printf( "%s %d\n", ph[i-1], x );
				z = 1;
			}
			x = 1;
		} else {
			x++;
		}
	}
	if( x > 1 ) {
		printf( "%s %d\n", ph[i-1], x );
		z = 1;
	}
	if( !z ) printf( "No duplicates.\n" );
}
