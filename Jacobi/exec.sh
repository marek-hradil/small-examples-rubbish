#!/bin/bash

make jacobi
chmod +x jacobi
./jacobi --iterations 100 --accuarcy 0.5
rm -rf ./*.o