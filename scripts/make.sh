#!/usr/bin/env bash

template="/home/sarvjot/programming/cp/code_lib/templates/cp_templates/template.cpp"

for var in "$@"
do
    file="$var.cpp"
    [ -f $file ] && rm $file
    touch $file 
    cp $template $file
done

[ -f in ] || touch in 
