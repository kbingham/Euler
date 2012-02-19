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

unsigned int SumOfSequentialNumbers( unsigned int From, unsigned int To )
{
  unsigned int Qty = To - From + 1;
  unsigned int Dbl = From + To;
  unsigned int Sum = ( ( Dbl * Qty ) / 2 );

  return Sum;
}

unsigned int TriangleNumber( unsigned int Number )
{
  /* Triangle Numbers are the sum of the sequential numbers from 1 */
  return (SumOfSequentialNumbers(1, Number));
}

/* This is the famous LCG based pseudorandom number generator from
 * 'Numerical Recipies in C'. It will do...
 */
unsigned int lcg(void)
{
  static unsigned int pattern = 0;
  return (pattern = 1664525 * pattern + 1013904223);
}
