#!/usr/bin/env bash
# downloads, builds and makes weld + benchmarks ready

echo ">> fetching weld"
git clone https://github.com/weld-project/weld.git && cd weld && git checkout v0.4.0

export PATH=$HOME/.cargo/bin:$PATH

rustup default nightly
export WELD_HOME=`pwd`
cargo build --release
cargo test

cd weld-python

pip3 install numpy pandas matplotlib seaborn python-config setuptools_rust
python3 setup.py install


# # get the benchmarks
# #WORKDIR /code
# #RUN apt-get install -y python3-pip python-dev python3-dev
# #RUN pip3 install numpy pandas matplotlib seaborn python-config setuptools_rust
# #RUN curl https://bootstrap.pypa.io/get-pip.py -o get-pip.py
# #RUN python2 -m pip install numpy pandas matplotlib seaborn python-config setuptools_rust
# RUN git clone https://github.com/weld-project/weld-benchmarks.git
# RUN cd weld-benchmarks
# ENV TEST_HOME=/code/weld-benchmarks
# RUN ./download-data.sh
#RUN cd /code/weld/python/grizzly && python3 setup.py install
#RUN cd /code/weld/weld-python && python3 setup.py install
