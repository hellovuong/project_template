FROM --platform=linux/arm64 ghcr.io/hellovuong/damn_you_realsense_base:v1
COPY ./ /tmp/damn_you_realsense

RUN cd /tmp/damn_you_realsense && \
  mkdir build && \
  cmake -S . -B build -GNinja && \
  cmake --build build

