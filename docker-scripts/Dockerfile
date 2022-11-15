FROM emscripten/emsdk:latest

WORKDIR /app

RUN wget -qO- https://michaelfiber.github.io/raylib-nightly-wasm/raylib.wasm.tar.gz | tar xvz

RUN mkdir -p /app/raylib/src
RUN mv libraylib.a /app/raylib/src/ && mv raylib.h /app/raylib/src/
COPY internal-build.sh /usr/bin/

ENTRYPOINT ["internal-build.sh"]