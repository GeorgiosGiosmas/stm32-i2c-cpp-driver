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

#################################
###### Install clang tools ######
#################################

ARG base_tag=bookworm
ARG llvm_version=16

RUN apt-get update --fix-missing && apt-get -y upgrade
RUN apt-get install -y --no-install-recommends \
    gnupg2 \
    gnupg-agent \
    ca-certificates \
    && rm -rf /var/lib/apt/lists/*

RUN curl --fail --silent --show-error --location https://apt.llvm.org/llvm-snapshot.gpg.key | apt-key add -
RUN echo "deb http://apt.llvm.org/$base_tag/ llvm-toolchain-$base_tag-$llvm_version main" >> /etc/apt/sources.list.d/llvm.list

RUN apt-get update --fix-missing && apt-get -y upgrade
RUN apt-get install -y --no-install-recommends \
    clang-format-${llvm_version} \
    clang-tidy-${llvm_version} \
    && rm -rf /var/lib/apt/lists/*

RUN ln -s /usr/bin/clang-format-${llvm_version} /usr/local/bin/clang-format
RUN ln -s /usr/bin/clang-tidy-${llvm_version} /usr/local/bin/clang-tidy

VOLUME ["/workdir"]
WORKDIR /workdir