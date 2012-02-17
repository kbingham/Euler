#include "common.h"

/*
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.

Solved in 90ms

*/

int IsPalindromeString( char * s )
{
  char * s1 = s;
  char * s2 = s;

  while( *s2 != '\0' )
    s2++; /* Increment to the end of the string */

  /* Move back to the last char */
  s2--;

  /* Iterate through the string and check */
  while (s2 >= s)
  {
    if (*s1++ != *s2--)
      return 0; /* Fail on Difference */
  }

  return 1; /* Is a Palindrome String */
}

char * TrueOrFalse( int v )
{
  return v ? "True" : "False";
}

int problem4(int argc, char ** argv)
{
  char string[7]; /* 999 * 999 */

  int x = 100;
  int y = 100;

  int max_product = 0;
  int max_x = 0;
  int max_y = 0;

  for ( x = 100; x < 1000; x++)
  {
    for ( y = 100; y < 1000; y++)
    {
      int product = x * y;

      sprintf(string, "%d", product);

      if (IsPalindromeString( string ))
      {
        if (product > max_product)
        {
          max_product = product;
          max_x = x;
          max_y = y;
        }
      }

    }
  }

  printf("%d is a palindrome from %d and %d\n", max_product, max_x, max_y);

  return 0;
}

SINGLETON_MAIN( problem4 );
