#include "common.h"

void prime_stats(int p)
{
  static int previous = 1;
  static int max_diff = 0;
  int diff = p - previous;

  if ( diff > max_diff )
    max_diff = diff;

  printf(" diff = %8d, max_diff = %8d\n", diff, max_diff);

  previous = p;
}

int main(void)
{
  int i;
  int found = 0;

  for (i=1; ; i++)
  {
    if (IsPrime(i))
    {
      found++;
      printf(" %d is the %d%s Prime\n", i, found, th(found));
      //prime_stats(i);
    }
  }

  return 0;
}
