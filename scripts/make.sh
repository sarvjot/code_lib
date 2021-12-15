#!/usr/bin/env bash

template="/home/sarvjot/programming/cp/code_lib/templates/cp_templates/template.cpp"

for var in "$@"
do
    file="$var.cpp"
    [ -f $file ] && rm $file
    touch $file 
    touch tmp

    
    d=$(date)
    echo "// Author: Sarvjot Singh" > tmp
    echo "// Date: $d" >> tmp
    echo "" >> tmp
    cat $template >> tmp

    cp tmp $file
    rm tmp
done

[ -f in ] || touch in 
