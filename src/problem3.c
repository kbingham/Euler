#include "common.h"

int factor(long x)
{
  /* Start with the first prime */
  int prime = 2;

  if (IsPrime(x))
  {
    printf("Found prime factor %ld\n", x);
    return x;
  }

  /* Find the next prime that divides cleanly */
  while ( x % prime != 0 )
    prime = NextPrime(prime);

  printf("Factoring %ld, found prime %d\n", x, prime);

  x /= prime; /* Divide the value by the prime factor */

  /* Shall we continue? */
  if (!IsPrime(x))
    factor(x);
  else
    printf("Found prime factor %ld\n", x);

  return x;
}

int problem3(int argc, char **argv)
{
  factor( 600851475143 );

  return 0;
}

SINGLETON_MAIN( problem3 );
