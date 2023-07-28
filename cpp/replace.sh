#!/bin/bash
fs=`find . -name "*.cpp"`
for f in $fs
do
    sed -i  's/\t/    /g' $f
    echo "replaced "$f
done
