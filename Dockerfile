FROM ubuntu:24.04

ARG RAYLIB_VERSION="4.2.0"

# Install basic dependencies
RUN apt-get update && apt-get install -y \
    cmake \
    git \
    libgoogle-glog-dev \
    libunwind-dev \
    libsqlite3-dev

# Install selected gcc versions
RUN apt-get update && apt-get install -y gcc-12 gcc-13 gcc-14

# Install selected clang versions
RUN apt-get update && apt-get install -y \
    llvm-19 clang-19 libc++abi-19-dev libc++abi1-19 libc++-19-dev libc++1-19

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
