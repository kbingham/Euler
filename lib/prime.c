/*
 * prime.c
 *
 *  Created on: 17 Feb 2012
 *      Author: kbingham
 */

#include <stdio.h>
#include "prime.h"

/* This will be a useful function in Euler Problems */
int IsPrime(unsigned int x)
{
  int i;

  /* http://en.wikipedia.org/wiki/Prime_number#Primality_of_one */
  if (1 == x)
    return 0;

  if (2 == x)
    return 1; /* 2 is prime - but will fail the next check */

  /* First Check */
  if (0 == x % 2)
    return 0; /* Divisible by 2 */

  /*
   * We only need to check up to the square root of x
   * As square root operations are expensive, we instead
   * parse until i squared is greater than x
   */
  for (i = 3; (i*i<=x); i+= 2)
  {
    /* Determine if i is a divisor ... no remainder; no prime! */
    if (0 == x % i)
      return 0; /* We have a divisor - so we aren't prime */
  }

  return 1; /* If we get here we must be a prime number! */
}

unsigned int NextPrime(unsigned int current)
{
  /* Iterate to the next prime number */
  while (!IsPrime(++current));

  return current;
}

int PrimeFactor(long x)
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
    PrimeFactor(x);
  else
    printf("Found prime factor %ld\n", x);

  return x;
}

