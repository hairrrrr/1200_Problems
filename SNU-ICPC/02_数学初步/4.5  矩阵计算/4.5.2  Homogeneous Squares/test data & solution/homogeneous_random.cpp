// Problem   Homogeneous squares
// Author    Adrian Kuegel
// Date      2006.07.09

#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

#define MAXN 1024

int s[MAXN][MAXN]; // square of numbers

int main() {
	freopen("homogeneous.in","r",stdin);
	int n;
	while(scanf("%d",&n) == 1 && n) {
		for (int i=0; i<n; ++i)
			for (int j=0; j<n; ++j)
				scanf("%d",&s[i][j]);
		bool homogeneous = true;
		if (n > 1) {
			// determine number of paths to check such that we fail to detect
			// "not homogeneous" with only 0.5 % probability
			int N = (int)(log(0.005)/(log(n-1)-log(n)));
			int p[MAXN];
			int sum = 0;
			for (int i=0; i<n; i++) {
				p[i] = i;
				sum += s[i][i];
			}
			while(homogeneous && N > 0) {
				--N;
				random_shuffle(p,p+n);
				int tsum = 0;
				for (int i=0; i<n; i++)
					tsum += s[i][p[i]];
				if (tsum != sum)
					homogeneous = false;
			}
		}
		if (!homogeneous)
			printf("not ");
		puts("homogeneous");
	}
	return 0;
}
