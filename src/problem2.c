#include "common.h"

int problem2(int argc, char ** argv)
{
#define FOURMILLION 4000000

  unsigned int first = 1;
  unsigned int second = 2;
  unsigned long long sum = 0;

  int target = FOURMILLION;

  if (argc > 1)
    target = atoi(argv[1]);

  while (first < target && second < target)
  {
    first += second;

    if ((first & 0x1) == 0) 
       sum += first;

    second += first;
    
    if ((second & 0x1) == 0)
       sum += second;

  }

  printf("Sum = %lld\n", sum);

  return sum;
}

SINGLETON_MAIN( problem2 );
