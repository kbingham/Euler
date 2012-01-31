#include "common.h"

int verbose = 0;

void SetVerbose(int v)
{
  verbose = v;
}

void ParseArgs(int argc, char ** argv)
{
  if (argc > 1) SetVerbose(1);
}

/* This will be a useful function in Euler Problems */
int IsPrime(int x)
{
  int i;

  /* http://en.wikipedia.org/wiki/Prime_number#Primality_of_one */
  if (1 == x)
    return 0;

  /* 
   * We only need to check up to the square root of x
   * As square root operations are expensive, we instead
   * parse until i squared is greater than x
   */
  for (i = 2; (i*i<=x); i++)
  {
    /* Determine if i is a divisor ... no remainder; no prime! */
    if (0 == x % i)
      return 0; /* We have a divisor - so we aren't prime */
  }
 
  return 1; /* If we get here we must be a prime number! */  
}

/* Just a useful helper to get the 'ending' of a number */
char * th(long long x)
{
  switch (x % 10)
  {
    case 1: return "st"; break;
    case 2: return "nd"; break;
    case 3: return "rd"; break;
    default: return "th"; break;
  }
}
