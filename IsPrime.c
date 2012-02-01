#include "common.h"

int main(int argc, char **argv)
{
  if (argc > 1)
  {
    unsigned int val = atoi (argv[1]);
    int prime = IsPrime(val);

    printf("%s: %u is%s a prime number\n", argv[0], val, (prime ? "" : " not"));

    return prime;
  }

  return -1;
}
