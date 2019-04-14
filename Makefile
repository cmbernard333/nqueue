#----------------------------------------------------------------------------------------------------------------------
#
# SETTINGS
#
#----------------------------------------------------------------------------------------------------------------------

CFLAGS=-ansi -pedantic -Wall
CXX_FLAGS=-ansi -pedantic -Wall -std=c++17
CXX:=$(or ${CXX}, clang++)
CC:=$(or ${CC}, clang)
INCLUDE_PATH=.
TARGET=stack_test

all: build

.PHONY: build
build: 
	mkdir -p build
	${CXX} -I ${INCLUDE_PATH} -o build/${TARGET} main.cpp

.PHONY: clean
clean:
	rm -rf build
