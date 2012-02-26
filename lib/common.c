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
 * 'Numerical Recipes in C'.
 */
unsigned int lcg(void)
{
  static unsigned int pattern = 0;
  return (pattern = 1664525 * pattern + 1013904223);
}
