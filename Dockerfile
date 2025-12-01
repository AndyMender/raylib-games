FROM ubuntu:24.04

ARG RAYLIB_VERSION="4.2.0"

RUN apt-get update && apt-get install -y \
    cmake \
    git

# Install selected gcc versions
RUN apt-get update && apt-get install -y gcc-12 gcc-13 gcc-14

# Install selected clang versions
RUN apt-get update && apt-get install -y llvm-toolchain-17 llvm-toolchain-18 llvm-toolchain-19

# Build raylib from source
RUN apt-get update && apt-get install -y \
    build-essential \
    libasound2-dev \
    libx11-dev \
    libxrandr-dev \
    libxi-dev \
    libgl1-mesa-dev \
    libglu1-mesa-dev \
    libxcursor-dev \
    libxinerama-dev \
    libwayland-dev \
    libxkbcommon-dev

# TODO: Should raylib be built with the same compiler later used in the project?
RUN git clone --depth 1 --branch ${RAYLIB_VERSION} https://github.com/raysan5/raylib.git raylib && \
    cd raylib && \
    cmake -S . -B build -DBUILD_SHARED_LIBS=ON && \
    cd build && \
    make install && ldconfig
