@echo off
cd build
cmake ../cmake -G"Unix Makefiles"
make
cd ../bin
start calculator.exe