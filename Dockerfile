FROM ubuntu:24.04

ARG RAYLIB_VERSION="4.2.0"

RUN apt-get update && apt-get install -y \
    software-properties-common \
    wget \
    cmake \
    git

# Install a selected LLVM toolchain
RUN wget https://apt.llvm.org/llvm.sh && chmod +x ./llvm.sh && ./llvm.sh all

# Install selected gcc versions
RUN apt-get update && apt-get install -y gcc-12 gcc-13 gcc-14

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

# Install newer cmake
RUN apt-get purge --auto-remove -y cmake
RUN wget https://github.com/Kitware/CMake/releases/download/v4.2.0/cmake-4.2.0-linux-x86_64.sh && \
    mkdir -p /opt/cmake && \
    sh cmake-4.2.0-linux-x86_64.sh --skip-license --prefix=/opt/cmake && \
    ln -s /opt/cmake/bin/cmake /usr/local/bin/cmake && \
    cmake --version
