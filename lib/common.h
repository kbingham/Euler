#include <stdio.h>
#include <stdlib.h>

#include "prime.h"
#include "time.h"
#include "text.h"

extern int verbose;

void ParseArgs(int argc, char ** argv);
void SetVerbose(int v);
int Factor(long x);
unsigned int SumOfSequentialNumbers( unsigned int From, unsigned int To );
unsigned int TriangleNumber( unsigned int Number );
unsigned int lcg(void);

#define SINGLETON_MAIN( target ) \
int __attribute__((weak))        \
main (int argc, char ** argv)    \
{                                \
  return MeasureFunctionTime(target, argc, argv); \
}
