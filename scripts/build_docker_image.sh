#!/bin/bash
set -euo pipefail

project_name=stm32-i2c-cpp-driver
script_dir=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)
repo_root=$(cd "${script_dir}/.." && pwd)

docker build -f ${repo_root}/docker/builder.Dockerfile -t ${project_name}-builder:latest .