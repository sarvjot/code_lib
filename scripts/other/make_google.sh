#!/usr/bin/env bash

for var in "$@" 
do
    touch "$var.cpp"
    cp /home/sarvjot/programs/cp/templates/cp_snips/template_google.cpp "$var.cpp"
done
