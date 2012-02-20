#include "common.h"

/*
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
a^2 + b^2 = c^2

For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.

Solved in 60ms

*/

int IsPythagoreanTriplet(unsigned int Py, unsigned int a, unsigned int b, unsigned int c)
{

 if ( a + b + c != Py )
   return 0;

 a *= a;
 b *= b;
 c *= c;

 return ( ( a + b == c ) );
}

int problem9( int argc, char ** argv )
{
  unsigned int Py = 1000;
  unsigned int a;
  unsigned int b;
  unsigned int c;

  if ( argc > 1 )
    Py = atoi(argv[1]);

  for ( c = 1; c < Py; c++ )
    for ( b = 1; b < c; b++ )
      for ( a = 1; a < b; a++ )
      {
        if (IsPythagoreanTriplet ( Py, a, b, c ))
	{
          printf(" a[%d]^2 + b[%d]^2 = c[%d]^2 where a+b+c = %d. The product abc is %d\n", a, b, c, Py, a*b*c);

	  if (Py == 1000)
		return 0;
	}
      }

  return 0;
}

SINGLETON_MAIN( problem9 );
