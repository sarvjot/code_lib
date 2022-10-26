#!/usr/bin/env bash

if [ -d tester ]; then
    rm -rf tester 
fi

cp -r $lib_path/templates/cp_templates/tester_templates ./tester
cp -r $lib_path/scripts/tester.sh ./tester/tester.sh
