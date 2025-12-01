FROM ubuntu:24.04

ARG RAYLIB_VERSION="4.2.0"

RUN apt-get update && apt-get install -y \
    software-properties-common \
    wget \
    cmake \
    git

# Install selected LLVM toolchains
RUN wget https://apt.llvm.org/llvm.sh && chmod +x ./llvm.sh && ./llvm.sh 
RUN apt-get update && apt-get install -y \
    clang-20 lldb-20 lld-20 \
    libc++-20-dev libc++abi-20-dev

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

RUN git clone --depth 1 --branch ${RAYLIB_VERSION} https://github.com/raysan5/raylib.git raylib && \
    cd raylib && \
    cmake -S . -B build -DBUILD_SHARED_LIBS=ON && \
    cd build && \
    make install && ldconfig
