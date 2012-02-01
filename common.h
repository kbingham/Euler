#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

extern int verbose;

void ParseArgs(int argc, char ** argv);
void SetVerbose(int v);
int IsPrime(unsigned int x);
char * th(long long x);
unsigned long getCurTimeInMsec();
char xtod(char c);
unsigned long MeasureTime( void );
void banner(char * txt);
unsigned int NextPrime(unsigned int current);
int Factor(long x);

#define SINGLETON_MAIN( target ) \
int __attribute__((weak))        \
main (int argc, char ** argv)    \
{                                \
  return target(argc, argv);     \
}
