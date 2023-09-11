#!/bin/bash

# compile the Word Counter Function with Makefile
echo 'Executing the Word Counter Function Makefile...'
make clean
make word-counter

# execute the Word Counter Function
echo 'Executing the Word Counter Function program...'
./word-counter