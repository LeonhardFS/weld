FROM ubuntu:bionic

MAINTAINER Leonhard Spiegelberg

RUN apt-get update
RUN apt-get install -y wget gnupg2 apt-utils software-properties-common curl
RUN wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key | apt-key add -
RUN apt-add-repository "deb http://apt.llvm.org/xenial/ llvm-toolchain-xenial-6.0 main"
RUN apt-get install -y llvm-6.0-dev clang-6.0 zlib1g-dev git build-essential manpages-dev
RUN apt-get install -y python3-pip python-dev python3-dev

RUN ln -s /usr/bin/llvm-config-6.0 /usr/local/bin/llvm-config

# Install Rust (without the stupid prompt)
RUN curl https://sh.rustup.rs -sSf | sh -s -- -y

RUN echo "export PATH=\$HOME/.cargo/bin:\$PATH" >> $HOME/.bashrc
RUN export PATH="$HOME/.cargo/bin:$PATH"

# clone weld
WORKDIR /code

ADD build-weld.sh /code/build-weld.sh

RUN bash build-weld.sh
