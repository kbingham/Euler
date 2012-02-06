#include "common.h"

int problem10(int argc, char ** argv)
{
  unsigned long long sum = 0;
  unsigned int prime = 1;
  unsigned int target = 2000000;

  if ( argc > 1 )
    target = atoi(argv[1]);

  /* Get the first prime */
  prime = NextPrime(prime);

  while (prime < target)
  {
    sum += prime;
    prime = NextPrime(prime);
  }

  printf("The sum of all primes below %d is %llu\n", target, sum);

  return 0;
}

SINGLETON_MAIN( problem10 );
