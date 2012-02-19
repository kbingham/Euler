#include "common.h"

/*
 * By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
 *
 * What is the 10 001st prime number?
 */

int problem7(int argc, char ** argv)
{
  int i = 0;
  int found = 0;
  int find = 10001;

  if (argc > 1)
    find = atoi(argv[1]);

  while(found < find)
  {
    if (IsPrime(++i))
      found++;
  }

  printf(" %d is the %d%s Prime\n", i, found, th(found));

  return 0;
}

SINGLETON_MAIN( problem7 );
