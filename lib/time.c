/*
 * time.c
 *
 *  Created on: 19 Feb 2012
 *      Author: kbingham
 */

#include "time.h"

unsigned long getCurTimeInMsec()
{
  struct timeval tv;

  if (gettimeofday(&tv, NULL) < 0)
    return 0;

  return tv.tv_sec * 1000 + tv.tv_usec/1000;
}

unsigned long MeasureTime( void )
{
  static unsigned long start = 0;
  static unsigned long now   = 0;
  unsigned long difference   = 0;

  if (start == 0)
  {
    start = getCurTimeInMsec();
  }
  else
  {
    now = getCurTimeInMsec();
    difference = now - start;

    start = now;
  }

  return difference;
}

int MeasureFunctionTime( fmain func, int argc, char ** argv)
{
  int ret;
  unsigned long duration;

  MeasureTime(); /* Initialise */
  ret = func(argc, argv);
  duration = MeasureTime();

  printf("Execution took %lu ms\n", duration);

  return ret;
}
