#!/bin/bash -f
dir=$1
for file in `ls $dir`
do
echo $file
done
