#include "common.h"

int main(int argc, char **argv)
{
  if (argc > 1)
  {
    unsigned int val = atoi (argv[1]);

    printf("%s: The next prime from %u is %u\n", argv[0], val, NextPrime(val));

    return 0;
  }

  return 1;
}
