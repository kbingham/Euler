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


unsigned long getCurTimeInMsec()
{
  struct timeval tv;

  if (gettimeofday(&tv, NULL) < 0)
    return 0;

  return tv.tv_sec * 1000 + tv.tv_usec/1000;
}


char xtod(char c) {
  if (c>='0' && c<='9') return c-'0';
  if (c>='A' && c<='F') return c-'A'+10;
  if (c>='a' && c<='f') return c-'a'+10;
  return c=0;
}

unsigned long MeasureTime( void )
{
  static unsigned long start = 0;
  static unsigned long now   = 0;
  unsigned long difference   = 0;

  if (start == 0)
  {
    start = getCurTimeInMsec();
  }
  else
  {
    now = getCurTimeInMsec();
    difference = now - start;

    start = now;
  }

  return difference;
}

typedef int (*fmain)(int, char **);

int MeasureFunctionTime( fmain func, int argc, char ** argv)
{
  int ret;
  unsigned long duration;

  MeasureTime(); /* Initialise */
  ret = func(argc, argv);
  duration = MeasureTime();

  printf("Execution took %lu ms\n", duration);

  return ret;
}

void banner(char * txt)
{
 printf("**********************************************\n");
 printf("%s\n", txt);
 printf("**********************************************\n");

}

unsigned int NextPrime(unsigned int current)
{
  /* Iterate to the next prime number */
  while (!IsPrime(++current));

  return current;
}

int Factor(long x)
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
    Factor(x);
  else
    printf("Found prime factor %ld\n", x);

  return x;
}
