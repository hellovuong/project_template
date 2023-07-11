FROM ghcr.io/hellovuong/damn_you_realsense_base:1.0
COPY ./ /tmp/damn_you_realsense

RUN cd /tmp/damn_you_realsense && \
  mkdir build && \
  cmake -S . -B build -GNinja && \
  cmake --build build

