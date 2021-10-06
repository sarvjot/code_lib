#!/usr/bin/env bash

for file in "in" "out" "ans"
do
    [ -f $file ] && rm $file
    touch $file
done

path="/home/sarvjot/programming/cp/code_lib/templates/cp_templates/template.cpp"
gf_path="/home/sarvjot/programming/cp/code_lib/templates/cp_templates/template_google.cpp"

[ $1 = "gf" ] && path=$gf_path

for var in ${@:2}
do
    file="$var.cpp"
    [ -f $file ] && rm $file
    touch $file 
    cp $path $file
done
