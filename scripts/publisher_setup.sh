#!/usr/bin/env bash

if [ -d publisher ]; then
    rm -rf publisher
fi

cp -r ~/programming/cp/code_lib/templates/cp_templates/publisher_templates ./publisher
cp -r ~/programming/cp/code_lib/scripts/publisher.sh ./publisher/publisher.sh
