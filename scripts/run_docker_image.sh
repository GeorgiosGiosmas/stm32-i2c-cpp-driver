#!/bin/bash
set -euo pipefail

project_name=stm32-i2c-cpp-driver

docker run --rm -it --platform linux/amd64 --workdir /workdir --user "$(id -u):$(id -g)" -v ~/${project_name}:/workdir ${project_name}-builder:latest /bin/bash