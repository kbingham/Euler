#include "common.h"

int main(int argc, char **argv)
{
  if (argc > 1)
  {
    unsigned int val = atoi (argv[1]);

    PrimeFactor(val);
  }

  return 1;
}
