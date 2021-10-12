#!/usr/bin/env bash

[ -d io ] || mkdir io
for file in "in1" "out1" "ans1" "in2" "out2" "ans2" "in0" "out0" "ans0"
do
    [ -f io/$file ] && rm io/$file
    touch io/$file
done

path="/home/sarvjot/programming/cp/code_lib/templates/cp_templates/template.cpp"

for var in "$@"
do
    file="$var.cpp"
    [ -f $file ] && rm $file
    touch $file 
    cp $path $file
done
