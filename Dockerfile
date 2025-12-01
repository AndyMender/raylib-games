FROM ubuntu:24.04

RUN apt-get update && apt-get install -y software-properties-common wget

# Install selected LLVM toolchains
RUN wget https://apt.llvm.org/llvm.sh && chmod +x ./llvm.sh && ./llvm.sh 
RUN apt-get update && apt-get install -y clang-18 clang-19 clang-20 

# Install selected gcc versions
RUN apt-get update && apt-get install -y gcc-12 gcc-13 gcc-14

# Install selected version of raylib
RUN add-apt-repository ppa:texus/raylib && apt-get update && apt-get install -y libraylib4-dev
