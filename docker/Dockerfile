FROM ubuntu:bionic 

MAINTAINER Leonhard Spiegelberg

RUN apt-get update
RUN apt-get install -y wget gnupg2 apt-utils software-properties-common curl
RUN wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key | apt-key add -
RUN apt-add-repository "deb http://apt.llvm.org/xenial/ llvm-toolchain-xenial-6.0 main"
RUN apt-get install -y llvm-6.0-dev clang-6.0 zlib1g-dev git build-essential manpages-dev

RUN ln -s /usr/bin/llvm-config-6.0 /usr/local/bin/llvm-config

# Install Rust (without the stupid prompt)
RUN curl https://sh.rustup.rs -sSf | sh -s -- -y

RUN echo "export PATH=\$HOME/.cargo/bin:\$PATH" >> $HOME/.bashrc

# clone weld
WORKDIR /code
RUN git clone https://github.com/weld-project/weld.git
RUN cd weld
RUN git checkout v0.4.0
RUN rustup update stable
ENV WELD_HOME=/code/weld
RUN cargo build --release
RUN cargo test


# get the benchmarks
WORKDIR /code
RUN apt-get install -y python3-pip python-dev python3-dev
RUN pip3 install numpy pandas matplotlib seaborn python-config setuptools_rust
RUN curl https://bootstrap.pypa.io/get-pip.py -o get-pip.py
RUN python2 -m pip install numpy pandas matplotlib seaborn python-config setuptools_rust
RUN git clone https://github.com/weld-project/weld-benchmarks.git
RUN cd weld-benchmarks
ENV TEST_HOME=/code/weld-benchmarks
RUN ./download-data.sh
 
RUN cd /code/weld/python/grizzly && python3 setup.py install 
RUN cd /code/weld/weld-python && python3 setup.py install
