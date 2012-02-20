#!/bin/bash

OUTPUT=$1.c

if [ -e $OUTPUT ]
then
  echo "Output file [$OUTPUT] already exists"
  exit 1;
fi

NAME=`basename $1 .c`

cat << EOF > $OUTPUT

#include "common.h"

/*

*/

int $NAME( int argc, char ** argv )
{
  return 0;
}

SINGLETON_MAIN( $NAME );

EOF
