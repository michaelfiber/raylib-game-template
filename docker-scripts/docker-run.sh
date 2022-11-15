#!/usr/bin/env bash

cd $( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )/..

docker run --rm -v $(pwd):/app/project -u $(id -u):$(id -g) mikes-raylib-wasm-builder:latest