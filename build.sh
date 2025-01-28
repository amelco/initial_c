#!/bin/bash
set -xe

mkdir -p bin/

PROG_NAME="main"
FILES="main.c "
LIBS="./"
INCLUDES="./"

# development version
gcc -g -Wall -Werror -std=c99 -L $LIBS  -o bin/$PROG_NAME $FILES -I $INCLUDES

# release version
#gcc -O3 -L $LIBS  -o $PROG_NAME $FILES -I $INCLUDES
