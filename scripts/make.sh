#!/usr/bin/env bash

rm in out ans
touch in out ans
for var in "$@" 
do
    touch "$var.cpp"
    cp /home/sarvjot/programs/cp/templates/cp_snips/template.cpp "$var.cpp"
done
