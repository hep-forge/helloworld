#! /bin/bash

[ -z "$PREFIX" ] && PREFIX="$PWD/install"

mkdir -p build
cd build

cmake .. -DCMAKE_INSTALL_PREFIX=$PREFIX
make -j8

make tests
[ $? -eq 1 ] && exit 1
 
make install
