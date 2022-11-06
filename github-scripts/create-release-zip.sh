#!/usr/bin/env bash

set -Eeuo pipefail

###

cd $GITHUB_WORKSPACE

zip ./release.zip $GITHUB_WORKSPACE/raylib-game-template/site/index.*