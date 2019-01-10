#!/bin/bash
rm -f input.txt
for (( c=0; c<1000; c++ ))
do
	./randompath >> input.txt
done

