FROM --platform=linux/arm64 nvcr.io/nvidia/l4t-base:r35.1.0

RUN apt-get update && apt-get install --no-install-recommends -y \
  gnupg2 \
  lsb-release \
  curl \
  cuda-toolkit-11-4 \
  cmake \
  build-essential \
  ninja-build \
  vim \
  git \
  libssl-dev libusb-1.0-0-dev libudev-dev pkg-config libgtk-3-dev

RUN cd /tmp && \
  git clone https://github.com/IntelRealSense/librealsense.git && \
  cd librealsense && \
  mkdir build && \
  cmake -S . -B build -GNinja \
  -DBUILD_EXAMPLES=true \
  -DCMAKE_BUILD_TYPE=release \
  -DFORCE_RSUSB_BACKEND=false \
  -DBUILD_WITH_CUDA=true \
  -DCHECK_FOR_UPDATES=false \
  -DCMAKE_CUDA_COMPILER=/usr/local/cuda/bin/nvcc && \
  cmake --build build && cmake --install build

RUN ./ /tmp/damn_you_realsense

RUN cd /tmp/damn_you_realsense && \
  mkdir build && \
  cmake -S . -B build -GNinja && \
  cmake --build build

