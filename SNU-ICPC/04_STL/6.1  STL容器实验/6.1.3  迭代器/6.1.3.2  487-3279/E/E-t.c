/* Copyright Viet-Trung Luu (ACM ICPC ECNA 1999) */

#define PRIME 400009

int n;
char buf[2500000];
int hash[PRIME][2];
int new[PRIME][2];

int val(int c) {
    if(c >= '0' && c <= '9') return c - '0';
    switch(c) {
        case 'A': case 'B': case 'C': return 2;
        case 'D': case 'E': case 'F': return 3;
        case 'G': case 'H': case 'I': return 4;
        case 'J': case 'K': case 'L': return 5;
        case 'M': case 'N': case 'O': return 6;
        case 'P': case 'R': case 'S': return 7;
        case 'T': case 'U': case 'V': return 8;
        case 'W': case 'X': case 'Y': return 9;
    }
    return -1;
}

int comp(const void *A, const void *B) {
    const int *a = A, *b = B;
    return a[0] - b[0];
}

main() {
    int i, j, k, l, m;

    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf(" %s", buf);
        for(j = k = 0, l = 54321; buf[j]; j++) {
            if((m = val(buf[j])) >= 0) {
                k = k * 10 + m;
                l = (l * 1234 + m) % PRIME;
            }
        }
        0 && printf("Got value %s, number %d, hash %d\n", buf, k, l);
        for(; hash[l][0] != k && hash[l][1]; l = (l + 1) % PRIME);
        hash[l][0] = k;
        hash[l][1]++;
    }
    for(i = j = 0; i < PRIME; i++) {
        if(hash[i][1] > 1) {
            new[j][0] = hash[i][0];
            new[j][1] = hash[i][1];
            j++;
        }
    }
    qsort(new, j, 2 * sizeof(int), comp);
    for(i = 0; i < j; i++) printf("%03d-%04d %d\n", new[i][0] / 10000, new[i][0]
 % 10000, new[i][1]);
    if (!j) { printf("No duplicates.\n"); }
}

