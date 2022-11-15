-----------------------------------

**NOTE from michaelfiber**: This fork has the following changes:

- .github/workflows/build-wasm.yml - Automatically builds and publishes a WASM version of the project on Github. The final files are sent to a branch called gh-pages. You can set up Github pages to publish this to access them from YOUR_USERNAME.github.io/REPO_NAME

- docker-scripts - There are linux scripts to build and run a Docker container that produces WASM files. The Docker container will write the resulting data to a directory called **dist** in the root of the project. **docker-build.sh** uses the Dockerfile to create a Docker image. **docker-run.sh** runs that image in a container passing in the root of the project for it to work on.

- github-scripts/config - this config file lets you set some options related to the Github Actions workflow as well as the docker build container.

- minshell.html - this has been updated to import pwa-bootstrap.js which registers sw.js. This all adds a service worker that caches all requests to make the result work better offline. More PWA add-ons are coming soon

---

_DISCLAIMER:_

Welcome to **raylib game template**!

This template provides a base structure to start developing a small raylib game in plain C. The repo is also pre-configured with a default `LICENSE` (zlib/libpng) and a `README.md` (this one) to be properly filled by users. Feel free to change the LICENSE as required.

All the sections defined by `$(Data to Fill)` are expected to be edited and filled properly. It's recommended to delete this disclaimer message after editing this `README.md` file.

This template has been created to be used with raylib (www.raylib.com) and it's licensed under an unmodified zlib/libpng license.

_Copyright (c) 2014-2022 Ramon Santamaria ([@raysan5](https://twitter.com/raysan5))_

-----------------------------------

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
