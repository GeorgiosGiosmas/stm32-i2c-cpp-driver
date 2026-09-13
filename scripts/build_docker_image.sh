#!/bin/bash
set -euo pipefail

project_name=stm32-i2c-cpp-driver
project_path=~/stm32-i2c-cpp-driver/docker

docker build -f ${project_path}/builder.Dockerfile -t ${project_name}-builder:latest .