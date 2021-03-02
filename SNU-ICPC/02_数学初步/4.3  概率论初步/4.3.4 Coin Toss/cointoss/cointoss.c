#include <stdio.h>
#include <math.h>
#include <assert.h>

int main(void)
{
  FILE *in, *out;
  const double pi = acos(-1);

  long long m, n, t, c;
  int cases, i, k;
  double total;
  int corner, interior, edge;
  double prob[5];

  in = fopen("cointoss.in", "r");
  out = fopen("cointoss.out", "w");
  assert(in && out);

  fscanf(in, "%d", &cases);
  for (i = 1; i <= cases; i++) {
    fscanf(in, "%lld %lld %lld %lld", &m, &n, &t, &c);
    total = (double)m * n * t * t;
    
    for (k = 1; k <= 4; k++) {
      prob[k] = 0;
    }

    if (m == 1 && n == 1) {
      /* this is the easy case, there is only one tile */
      prob[1] = 1;

    } else if (m == 1) {
      /* only one row */
   
      /* you can only cover one or two tiles */
      prob[1] = (n*t - c*(n-1))*t/total;
      prob[2] = c*(n-1)*t/total;

    } else if (n == 1) {
      /* only one column, same as above but flipped */
      
      prob[1] = (m*t - c*(m-1))*t/total;
      prob[2] = c*(m-1)*t/total;

    } else {
      /* general case */

      /* calculate the number of tiles that are on the edges */
      corner = 4;
      interior = (m-2) * (n-2);
      edge = m*n - corner - interior;

      /* work in the contribution from the corners */
      prob[1] = corner * (t-c/2.0)*(t-c/2.0);
      prob[2] = corner * 2 * (c/2.0) * (t-c/2.0);
      prob[3] = corner * (c/2.0) * (c/2.0) * (1-pi/4);
      prob[4] = corner * (c/2.0) * (c/2.0) * pi/4;

      /* work in the contribution for the edges */
      prob[1] += edge * (t-c) * (t-c/2.0);
      prob[2] += edge * (c/2.0) * (3*t - 2*c);
      prob[3] += edge * 2 * (c/2.0) * (c/2.0) * (1-pi/4);
      prob[4] += edge * (c/2.0) * (c/2.0) * pi/2;

      /* work in the contribution for the interior */
      prob[1] += interior * (t-c) * (t-c);
      prob[2] += interior * (t-c) * (c/2.0) * 4;
      prob[3] += interior * (c * c - pi * (c/2.0) * (c/2.0));
      prob[4] += interior * pi * (c/2.0) * (c/2.0);

      for (k = 1; k <= 4; k++) {
	prob[k] /= total;
      }
    }

    if (i > 1) {
      fprintf(out, "\n");
    }
    fprintf(out, "Case %d:\n", i);
    for (k = 1; k <= 4; k++) {
      assert(0 <= prob[k] && prob[k] <= 100);
      if ((int)floor(prob[k]*100*10000000+0.5) % 1000 == 500) {
	fprintf(out, "First digits after output is 500\n");
      }
      fprintf(out, "Probability of covering %d tile%s = %.4f%%\n", k, 
	     ((k == 1) ? " " : "s"), prob[k]*100);
    }
	     
  }
  
  return 0;

}
