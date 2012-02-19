/*
 * text.c
 *
 *  Created on: 19 Feb 2012
 *      Author: kbingham
 */

#include "text.h"

/* Just a useful helper to get the 'ending' of a number */
char * th(long long x)
{
  switch (x % 10)
  {
    case 1: return "st"; break;
    case 2: return "nd"; break;
    case 3: return "rd"; break;
    default: break;
  }

  return "th";
}

char xtod(char c) {
  if (c>='0' && c<='9') return c-'0';
  if (c>='A' && c<='F') return c-'A'+10;
  if (c>='a' && c<='f') return c-'a'+10;
  return c=0;
}

void banner(char * txt)
{
 printf("**********************************************\n");
 printf("%s\n", txt);
 printf("**********************************************\n");
}
