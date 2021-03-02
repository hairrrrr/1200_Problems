#include <stdlib.h>
typedef struct {
    char english[12];
    char french[12];
} sd;

sd d[101000];

int comp( const sd* a, const sd* b ) {
    return strcmp( a->french, b->french );
}

main() {
    char* c;
    char buf[1000];
    int nw=0;
    sd s;
    sd* found;

    while(1) {
	gets( buf );
	if( !*buf ) break;
	for( c=buf; *c; c++ ) {
	    if( *c == ' ' ) { *c = 0; break; }
	}
	strcpy( d[nw].english, buf );
	strcpy( d[nw].french, c+1 );
	nw++;
    }
    qsort( d, nw, sizeof(sd), comp );
    while(gets(buf)) {
	strcpy( s.french, buf );
	found = bsearch(&s, d, nw, sizeof(sd), comp );
	if( !found ) puts( "eh" );
	else puts(found->english);
    }
}
