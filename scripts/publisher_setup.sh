#!/usr/bin/env bash

if [ -d publisher ]; then
    rm -rf publisher
fi

cp -r $lib_path/snippets/cp_snippets/publisher_snippets ./publisher
cp -r $lib_path/scripts/publisher.sh ./publisher/publisher.sh
