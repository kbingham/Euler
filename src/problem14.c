#include "common.h"

/*

The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:
13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1

It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.

 Solved in 890 ms

*/

unsigned long long iterate( unsigned long long n )
{
  if ( n % 2 == 0 )
    return (n / 2);
  else
    return ((3 * n) + 1);
}

unsigned int CountIterations ( unsigned int target )
{
  unsigned int count = 0;
  unsigned long long number = target;

  while ( number > 2 )
  {
    number = iterate (number);
    count++;
  }

  return count;
}

int problem14( int argc, char ** argv )
{
  unsigned int number     = 0;
  unsigned int count      = 0;
  unsigned int max_number = 0;
  unsigned int max_count  = 0;
  unsigned int target = 1000000;

  if (argc > 1)
    target = atoi( argv[1] );

  while ( number < target )
  {
    count = CountIterations ( number );
    if ( count > max_count )
    {
      max_count = count;
      max_number = number;

      if (verbose) printf(" Number %d has a chain of %d\n", number, count );
    }

    number++;
  }

  printf(" %d has a chain of %d \n", max_number, max_count );

  return 0;
}

SINGLETON_MAIN( problem14 );
