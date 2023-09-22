#!/usr/bin/env bash

if [ -d tester ]; then
    rm -rf tester 
fi

cp -r $lib_path/snippets/cp_snippets/tester_snippets ./tester
cp -r $lib_path/scripts/tester.sh ./tester/tester.sh
