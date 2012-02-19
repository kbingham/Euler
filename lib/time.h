/*
 * time.h
 *
 *  Created on: 19 Feb 2012
 *      Author: kbingham
 */

#include <stdio.h>
#include <sys/time.h>

#ifndef TIME_H_
#define TIME_H_

typedef int 	(*fmain)			( int, char ** );

unsigned long 	getCurTimeInMsec	( );
unsigned long 	MeasureTime			( void );
int 			MeasureFunctionTime	( fmain func, int argc, char ** argv );

#endif /* TIME_H_ */
