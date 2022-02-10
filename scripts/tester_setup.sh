#!/usr/bin/env bash

if [ -d tester ]; then
    rm -rf tester 
fi

cp -r ~/programming/cp/code_lib/templates/cp_templates/tester_templates ./tester
cp -r ~/programming/cp/code_lib/scripts/tester.sh ./tester/tester.sh
