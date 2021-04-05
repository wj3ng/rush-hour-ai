#!/bin/bash

TOTIME=20

for f in tests/L*.txt ; do 
    for i in {1..5} ; do
        if ! timeout $TOTIME ./a.out $i $(basename $f) ; then
            echo Timed out after $TOTIME seconds
        fi
        echo 
    done
done