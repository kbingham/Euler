#include "common.h"

unsigned int problem1(void)
{
  int result = 0;
  int i;

  for (i = 0; i < 1000; i++)
  {
    if (i % 3 == 0 || i % 5 == 0)
    {
        result += i;
        if (verbose) printf(" Adding %d, result = %d\n", i, result);
    }
  }

  return result;
}

int main(int argc, char ** argv)
{
  ParseArgs(argc, argv);
  
  printf("Problem1 : The sum of natural numbers up to 1000 which are multiples of 3 and 5 is %d\n", problem1());
  
  return 0;
}
