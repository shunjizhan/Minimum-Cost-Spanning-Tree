CXX=clang++
# CXX=g++

all: Main.o
	${CXX} Main.o -o mcst
	./mcst

Main.o: Main.cpp
	${CXX} -c Main.cpp

clean:
	/bin/rm -f *.o mcst

