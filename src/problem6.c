#include "common.h"

/*

The sum of the squares of the first ten natural numbers is,
12 + 22 + ... + 102 = 385

The square of the sum of the first ten natural numbers is,
(1 + 2 + ... + 10)2 = 552 = 3025

Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

*/

int problem6(int argc, char ** argv)
{
  int i;
  int find = 100;

  unsigned long long sumsquares = 0;
  unsigned long long sum = 0;
  unsigned long long squaresums = 0;
  unsigned long long difference = 0;

  if (argc > 1)
    find = atoi(argv[1]);

  for (i = 1; i <= find; i++)
  {
    sumsquares += (i*i); /* Add the sqaure */
    sum += i;            /* Total the sums */
  }

  /* Now we can square the sum */
  squaresums = (squaresums*squaresums);

  /* Method 2 - After working out the maths with Andy 
   *  This should all be possible without a loop...
   *  Which improves the linear calculations ...
   */

  /* The sum of the Squares */
  /* Ok, I don't know how to do this bit yet.... */

  /* The Square of the sums */
  /* Sum of sequential numbers (from 1) (N^2+N)/2 */
  squaresums = ( ((find*find)+find)/2 );
  /* Then square it ... */
  squaresums = (squaresums*squaresums);

  /* Final part ... get the difference */
  difference = squaresums - sumsquares;

  printf(" To the first %d natural numbers, the sum of squares is %llu, the square of sums is %llu. The difference is %llu\n",
	find, sumsquares, squaresums, difference );

  return 0;
}

SINGLETON_MAIN( problem6 );
