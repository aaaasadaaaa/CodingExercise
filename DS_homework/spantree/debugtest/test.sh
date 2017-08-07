#!/bin/sh
echo -n "Please insert your city number:"
read city_number
echo -n "Please insert your road number:"
read road_number

./roads_maker $city_number $road_number >roads_input

./spantree_ref <roads_input>output_reference
./spantree<roads_input>output_your_program
diff output_reference output_your_program

./json2dot < output_reference > reference.dot
dot -Tps -o reference.ps reference.dot

./json2dot < output_your_program > your_program.dot
dot -Tps -o your_program.ps your_program.dot

