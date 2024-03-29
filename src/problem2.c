#include "common.h"

/*
Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:

1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.

Solved in 'under a millisecond'

*/

inline unsigned int FibonacciNext(unsigned int *first, unsigned int *second)
{
  unsigned int next = *first + *second;

  /* Move the number window */
  *first = *second;
  *second = next;

  return next;
}


int problem2(int argc, char ** argv)
{
#define FOURMILLION 4000000

  unsigned int first = 1;
  unsigned int second = 1;
  unsigned long long sum = 0;

  int target = FOURMILLION;

  if (argc > 1)
    target = atoi(argv[1]);

  while ( FibonacciNext(&first, &second) <= target )
  {
    /* The 'second' value is now our next value */
    if ((second & 0x1) == 0)
       sum += second;
  }

  printf("Sum = %lld\n", sum);

  return sum;
}

SINGLETON_MAIN( problem2 );
