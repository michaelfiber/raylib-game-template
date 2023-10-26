#!/usr/bin/env bash

GITHUB_CONFIG=/app/project/github-scripts/config
source $GITHUB_CONFIG

if [[ $PWA == "true" ]]; then
	echo "Building with PWA enabled"	
fi

if [[ $MOBILE_CONTROLS == "true" ]]; then
	echo "Building with on screen controls for mobile"
fi

cd /app/project/src

BUILD_WEB_SHELL=minshell.html PROJECT_NAME=index RAYLIB_PATH=/app/raylib PLATFORM=PLATFORM_WEB make -e

mkdir -p /app/project/dist

mv index.* /app/project/dist/

# Automatically strip the release zip because this is built in docker locally.
sed -i 's/<div><a href=release.zip>Download Release ZIP<\/a><\/div>//g' /app/project/dist/index.html

if [[ $PWA == "true" ]]; then

	TIMESTAMP=$(date '+%s')

	cp ./sw.js /app/project/dist/
	cp ./pwa-bootstrap.js /app/project/dist/

	# each new build will reset caching in the PWA.
	sed -i "s/RAYLIB_GAME_TEMPLATE_FORK_CACHE_NAME/cache_name_$TIMESTAMP/g" /app/project/dist/sw.js

	# when built in docker assume root directory.
	sed -i "s/\/PATH_TO_PWA//g" /app/project/dist/pwa-bootstrap.js

else

	sed -i 's/<script src=pwa-bootstrap.js><\/script>//g' /app/project/dist/index.html

fi

if [[ -f ./minshell.css ]]; then
	cp ./minshell.css /app/project/dist/
fi

if [[ -f ./virtual-gamepad.js ]]; then
	cp ./virtual-gamepad.js /app/project/dist/
fi

make clean