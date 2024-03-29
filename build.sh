#! /usr/bin/bash

cd libs/Anemone
meson setup build/
cd build
meson install
cd ../../..
meson setup build
