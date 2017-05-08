CXX=clang++
# CXX=g++

all:
	$(MAKE) clean
	$(MAKE) run

run: Main.o
	${CXX} Main.o -o mcst
	./mcst

test1: Main.o
	${CXX} Main.o -o mcst
	./mcst < tests/test1 > tests/output1

test2: Main.o
	${CXX} Main.o -o mcst
	./mcst < tests/test2 > tests/output2

test3: Main.o
	${CXX} Main.o -o mcst
	./mcst < tests/test3 > tests/output3

test4: Main.o
	${CXX} Main.o -o mcst
	./mcst < tests/test4 > tests/output4

test5: Main.o
	${CXX} Main.o -o mcst
	./mcst < tests/test5 > tests/output5

clean:
	/bin/rm -f *.o mcst

Main.o: Main.cpp
	${CXX} -c Main.cpp