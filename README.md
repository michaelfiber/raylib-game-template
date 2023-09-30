-----------------------------------

**NOTE from michaelfiber**: This fork has the following changes:

## Select browser features available to WASM builds:
Very quick and dirty integration of some web browser features available in WASM builds by including my-library.h and using the functions from it:

**Speech Synthesis** - works on modern browsers except Firefox.  `Say("Hello there");` in C will say "Hello there" in the default synthesis voice of your browser.

**Vibration** - works on Mobile Chrome and maybe others? Triggers your phone to vibrate. The pattern passed alternates between vibration and non-vibration.  The sample below should vibrate for 100ms, then stop for 100ms, then vibrate for 100ms again.
```C
	int pattern[] = {100, 100, 100};
	Vibrate(pattern, 3);
```

**Device Rotation** - Works on most modern mobile browsers. Pass in pointers to floats for beta (tilting your phone forward and back) and gamma (tilting your phone left and right). Orientation are in degrees. 
```C
	float beta = 0.0;
	float gamma = 0.0;
	RegisterOrientationPointers(&beta, &gamma);
```

## Github workflows

**Github Workflows** - The `./github/workflows/build-wasm.yml` file tells Github to automatically build a WASM version using the docker-build and docker-run commands in the docker-script directory. That WASM version is pushed to a branch called gh-pages. The branch is created if necessary. You can then publish that branch as Github Pages and have static hosting for your WASM project.

**Tiny bit of build config** - There's a little config in github-scripts/config - this config file lets you set some options related to the Github Actions workflow as well as the docker build container.

## PWA Features
**PWA** - minshell.html has been modified to add some basic PWA features.

## Also note
This template is compatible with mikes-raylib-wasm-builder:

```
	docker pull michaelfiber/mikes-raylib-wasm-builder
	docker run --rm -v $(pwd):/app/project -u $(id -u):$(id -g) michaelfiber/mikes-raylib-wasm-builder:latest
```

This will create a "dist" folder inside your project that contains a WASM build of your game. It uses the Makefile in ./src so as long as that is updated for your game and doesn't contain radical changes it should work.

---

_DISCLAIMER:_

Welcome to **raylib game template**!

This template provides a base structure to start developing a small raylib game in plain C. The repo is also pre-configured with a default `LICENSE` (zlib/libpng) and a `README.md` (this one) to be properly filled by users. Feel free to change the LICENSE as required.

All the sections defined by `$(Data to Fill)` are expected to be edited and filled properly. It's recommended to delete this disclaimer message after editing this `README.md` file.

This template has been created to be used with raylib (www.raylib.com) and it's licensed under an unmodified zlib/libpng license.

_Copyright (c) 2014-2023 Ramon Santamaria ([@raysan5](https://twitter.com/raysan5))_

-----------------------------------
## Getting Started with this template
- After extracting the zip, the parent folder `raylib-game-template` should exist in the same directory as `raylib` itself.  So your file structure should look like this:
    - Some parent directory
        - `raylib`
            - the contents of https://github.com/raysan5/raylib
        - `raylib-game-template`
            - this `README.md` and all other raylib-game-template files
- If using Visual Studio, open projects/VS2022/raylib-game-template.sln
- Select on `raylib_game` in the solution explorer, then in the toolbar at the top, click `Project` > `Set as Startup Project`
- Now you're all set up!  Click `Local Windows Debugger` with the green play arrow and the project will run.

## $(Game Title)

![$(Game Title)](screenshots/screenshot000.png "$(Game Title)")

### Description

$(Your Game Description)

### Features

 - $(Game Feature 01)
 - $(Game Feature 02)
 - $(Game Feature 03)

### Controls

Keyboard:
 - $(Game Control 01)
 - $(Game Control 02)
 - $(Game Control 03)

### Screenshots

_TODO: Show your game to the world, animated GIFs recommended!._

### Developers

 - $(Developer 01) - $(Role/Tasks Developed)
 - $(Developer 02) - $(Role/Tasks Developed)
 - $(Developer 03) - $(Role/Tasks Developed)

### Links

 - YouTube Gameplay: $(YouTube Link)
 - itch.io Release: $(itch.io Game Page)
 - Steam Release: $(Steam Game Page)

### License

This game sources are licensed under an unmodified zlib/libpng license, which is an OSI-certified, BSD-like license that allows static linking with closed source software. Check [LICENSE](LICENSE) for further details.

$(Additional Licenses)

*Copyright (c) $(Year) $(User Name) ($(User Twitter/GitHub Name))*
