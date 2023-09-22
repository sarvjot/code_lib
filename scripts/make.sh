#!/usr/bin/env bash

template="$lib_path/snippets/cp_snippets/template.cpp"

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
