CXX=clang++
# CXX=g++

all:
	$(MAKE) clean
	$(MAKE) run

run: Main.o
	${CXX} Main.o -o mcst
	./mcst

test: Main.o
	${CXX} Main.o -o mcst
	./mcst < tests/test0

clean:
	/bin/rm -f *.o mcst

Main.o: Main.cpp
	${CXX} -c Main.cpp