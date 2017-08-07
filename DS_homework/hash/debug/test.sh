#! /bin/bash

echo "Please type the number of words"
read param1

echo "Please type the number of stop words"

read param2
./input_maker $param1 >input
./stop_words_maker $param2 >stop_words
echo "Please type initial length"

read initial_length

echo "Please type load factor"

read load_factor

./hash1 -w input -s stop_words -l $initial_length -f $load_factor >output_reference
./hash -w input -s stop_words -l $initial_length -f $load_factor >output_your_program

diff output_reference output_your_program -c
echo "Done"
