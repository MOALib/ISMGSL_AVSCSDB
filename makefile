.PHONY: all build cls test


all: cls build

cls:
	clear

build:


test:
	g++ test/test.cpp -o test/bin/test.exe -fdiagnostics-color