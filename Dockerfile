FROM ubuntu:latest
ENV DEBIAN_FRONTEND noninteractive
RUN apt-get update && \
    apt-get -y install gcc mono-mcs make g++ && \
    apt update && \
    apt install -y antlr4 libantlr4-runtime-dev default-jdk && \
    rm -rf /var/lib/apt/lists/*

COPY ./compiler /usr/bin/compiler
COPY ./tests /usr/bin/tests
RUN cd /usr/bin/compiler && \
    ./runmake_ubuntu.sh
