ARG base_tag=bookworm
ARG base_img=mcr.microsoft.com/devcontainers/base:${base_tag}

FROM --platform=linux/amd64 ${base_img} AS builder-install

RUN apt-get update --fix-missing && apt-get -y upgrade
RUN apt-get install -y --no-install-recommends \
    curl \
    cmake \
    build-essential \
    ninja-build     \
    git \
    ca-certificates \
    gcc-arm-none-eabi   \
    binutils-arm-none-eabi  \
    libnewlib-arm-none-eabi \
    libstdc++-arm-none-eabi-newlib  \
    clang-format    \
    clang-tidy  \
    && rm -rf /var/lib/apt/lists/*

USER vscode

VOLUME ["/workdir"]
WORKDIR /workdir