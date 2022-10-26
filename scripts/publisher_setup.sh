#!/usr/bin/env bash

if [ -d publisher ]; then
    rm -rf publisher
fi

cp -r $lib_path/templates/cp_templates/publisher_templates ./publisher
cp -r $lib_path/scripts/publisher.sh ./publisher/publisher.sh
