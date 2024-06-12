FROM alpine:3.17.0

# Install toolchain
RUN apk update && \
    apk upgrade && \
    apk add git \
            python3 \
            py3-pip \
            cmake \
            build-base \
            libusb \
            libusb-dev \
            bsd-compat-headers \
            newlib-arm-none-eabi \
            gdb-multiarch \
            gcc-arm-none-eabi && \
    apk add --update openssh dos2unix tar rsync ninja autoconf && \
    apk add curl && apk add --upgrade curl && \
    rm -rf /tmp/* /var/cache/apk/*

RUN echo "root:root" | chpasswd



# OpenOCD installation
RUN apk add openocd

# install tio
# Documentation for tio: https://github.com/tio/tio
RUN apk add tio


# Raspberry Pi Pico SDK
ARG SDK_PATH=/usr/share/pico_sdk
RUN git clone --branch master https://github.com/raspberrypi/pico-sdk.git ${SDK_PATH} 

# Updating submodules sometimes fails.
RUN cd $SDK_PATH \
    && git submodule update --init --recursive --remote 

ENV PICO_SDK_PATH=${SDK_PATH}



# Picotool installation
RUN git clone --depth 1 --branch 1.1.2 https://github.com/raspberrypi/picotool.git /home/picotool \
    && cd /home/picotool \
    && mkdir build \
    && cd /home/picotool/build \
    && cmake .. \
    && make \
    && cp /home/picotool/build/picotool /bin/picotool \
    && rm -rf /home/picotool