#!/usr/bin/env bash

#set -Eeuo pipefail

###

source $GITHUB_WORKSPACE/raylib-game-template/github-scripts/config

cd $GITHUB_WORKSPACE/raylib-game-template/src

echo "running makefile."

if [[ $PWA == "true" ]]; then
	echo "Building with PWA enabled"
fi

# remove the release link unless specified.
if [[ $RELEASE_LINK_IN_HTML != "true" ]]; then
	sed -i 's/<a href="release.zip">Download Release ZIP<\/a>//g' $HTML_TEMPLATE
fi

BUILD_WEB_SHELL=minshell.html EMSDK_PYTHON=/usr/bin/python3 RAYLIB_PATH=$GITHUB_WORKSPACE/raylib PROJECT_NAME=index make -e all

# make the dir in case it doesn't exist.
mkdir -p $GITHUB_WORKSPACE/raylib-game-template/site

# move all the index.* files from src to the site directory.
mv ./index.* $GITHUB_WORKSPACE/raylib-game-template/site/

# optionally configure and move the PWA files.
if [[ $PWA == "true" ]]; then
	
	# each new build will reset caching in the PWA.
	sed -i "s/RAYLIB_GAME_TEMPLATE_FORK_CACHE_NAME/cache_name_$GITHUB_SHA/g" sw.js
	
	# Update the path to the service worker assuming it's using the repo name as a subdirectory.
	if [[ $OVERRIDE_PWA_PATH == "false" ]]; then
		IFS='/' read -ra PARTS <<< "$REPO"
		sed -i "s/PATH_TO_PWA/${PARTS[1]}/g" pwa-bootstrap.js
	else
		sed -i "$/PATH_TO_PWA/$OVERRIDE_PWA_PATH/g" pwa-bootstrap.js
	fi 

	mv ./sw.js $GITHUB_WORKSPACE/raylib-game-template/site/
	mv ./pwa-bootstrap.js $GITHUB_WORKSPACE/raylib-game-template/site/

else

	sed -i 's/<script src=pwa-bootstrap.js><\/script>//g' $GITHUB_WORKSPACE/raylib-game-template/site/index.html

fi
