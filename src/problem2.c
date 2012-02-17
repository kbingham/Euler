#include "common.h"

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
