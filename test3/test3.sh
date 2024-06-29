#!/bin/bash

rm log.txt
echo "Test 3" >> log.txt
a=0

while [ $a -lt 1000 ]
do 
    ./ex3 &
    wait $last_pid
    echo $(tail -n 1 logfile.txt) >> log.txt
    a=`expr $a + 1`
done
