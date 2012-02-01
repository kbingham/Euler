#include <stdio.h>
#include <stdlib.h>

int verbose;

void ParseArgs(int argc, char ** argv);
void SetVerbose(int v);
int IsPrime(int x);
char * th(long long x);
unsigned long getCurTimeInMsec();
char xtod(char c);
unsigned long MeasureTime( void );
void banner(char * txt);
