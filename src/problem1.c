#include "common.h"

int problem1(int argc, char **argv)
{
  int result = 0;
  int i;
  unsigned int target = 1000;

  if (argc > 1)
    target = atoi(argv[1]);

  for (i = 0; i < target; i++)
  {
    if (i % 3 == 0 || i % 5 == 0)
    {
        result += i;
        if (verbose) printf(" Adding %d, result = %d\n", i, result);
    }
  }

  printf("Problem1 : The sum of natural numbers up to %u which are multiples of 3 and 5 is %d\n", target, result);

  return result;
}

SINGLETON_MAIN( problem1 );
