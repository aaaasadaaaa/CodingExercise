#!/bin/bash
for((k=1;k<4;k++))
do
  for((j=0;j<100;j++))
  do
    python3 gen$k.py > input/$k/input$j.txt
    INPUT=`cat input/$k/input$j.txt`
    ./calendar $INPUT > output/$k/output$j.txt
  done
done

for((q=0;q<100;q++))
do
  cp output/3/output$q.txt input/4/input$q.txt
  INPUT=`cat output/3/output$q.txt`
  ./calendar $INPUT > output/4/output$q.txt
done
