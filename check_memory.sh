#!/bin/bash
set -xe

mkdir -p bin/

PROG_NAME="main"
FILES="main.c "
LIBS="./"
INCLUDES="./"

# compile with address sanitization (asan)
gcc -g -fsanitize=address -Wall -Werror -std=c99 -L $LIBS  -o bin/$PROG_NAME $FILES -I $INCLUDES
./bin/$PROG_NAME

# check for memory leaks
valgrind bin/$PROG_NAME