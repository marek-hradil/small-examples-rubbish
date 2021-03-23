#!/bin/bash

make gauss_seidel
chmod +x gauss_seidel
./gauss_seidel 0.5 100
rm -rf ./*.o