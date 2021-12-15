#!/usr/bin/env bash

path="/home/sarvjot/programming/cp/code_lib/templates/cp_templates/template.cpp"

for var in "$@"
do
    file="$var.cpp"
    [ -f $file ] && rm $file
    touch $file 
    cp $path $file
done
