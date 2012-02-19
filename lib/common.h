#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "prime.h"

extern int verbose;

typedef int (*fmain)(int, char **);

void ParseArgs(int argc, char ** argv);
void SetVerbose(int v);
char * th(long long x);
unsigned long getCurTimeInMsec();
char xtod(char c);
unsigned long MeasureTime( void );
void banner(char * txt);
int Factor(long x);
int MeasureFunctionTime( fmain func, int argc, char ** argv);
unsigned int SumOfSequentialNumbers( unsigned int From, unsigned int To );
unsigned int TriangleNumber( unsigned int Number );
unsigned int lcg(void);

#define SINGLETON_MAIN( target ) \
int __attribute__((weak))        \
main (int argc, char ** argv)    \
{                                \
  return MeasureFunctionTime(target, argc, argv); \
}
