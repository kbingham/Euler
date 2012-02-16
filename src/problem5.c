#include "common.h"
/*

2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

*/

int evenly_divisible(int value, int target)
{
  int i;

  for (i = 1; i <= target; i++)
  {
    if ( value % i != 0)
      return 0; /* Its not evenly divisble by all numbers */
  }

  return 1;
}

int problem5(int argc, char ** argv)
{
  int target = 20;
  int current = 0;
  int found = 0;

  if (argc > 1)
    target = atoi ( argv[1] );

  while (found == 0)
  {
    found = evenly_divisible( ++current, target );
  }

  printf(" %d is evenly divisible by every natural number to %d\n", current, target);

  return 0;
}

SINGLETON_MAIN( problem5 );
