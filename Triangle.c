#include "common.h"

int triangle(int argc, char ** argv)
{
  int t = 1;

  if (argc > 1)
    t = atoi( argv[1] );

  printf("The %d%s Triangle Number is %d\n", t, th(t), TriangleNumber(t) );

  return 0;
}

SINGLETON_MAIN( triangle );
