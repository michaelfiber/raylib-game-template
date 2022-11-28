#!/usr/bin/env bash

cd $( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )/..

mkdir ./site/
zip ./dist/release.zip ./dist/*
