#!/bin/bash


g++ test.cpp -o test

for i in {1..100}
do
  STR2=$(echo "-" | python3 testGen.py | ./test | python3 testCheck.py)
  echo $STR2
  STR3="Test passed"
  
  if [ "$STR2" != "$STR3" ]
  then
    break
  fi
done

unlink ./test
