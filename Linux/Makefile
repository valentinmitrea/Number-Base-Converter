CC = g++ -std=c++11
INCLUDE = -I./include
CFLAGS = -Wall
EXECUTABLE = bin/NumberBaseConverter
MKDIR = mkdir
RM = rm -rf

.PHONY: clean

all: clean main

main: src/main.o src/number_utils/Number.o src/number_utils/NumberInBase2.o src/number_utils/NumberInBase10.o src/exceptions/InvalidBaseException.o src/exceptions/InvalidNumberException.o
	$(MKDIR) bin
	$(CC) $(CFLAGS) $^ -o $(EXECUTABLE)

src/main.o: src/main.cpp
	$(CC) $(CFLAGS) $(INCLUDE) src/main.cpp -c -o src/main.o

src/number_utils/Number.o: src/number_utils/Number.cpp
	$(CC) $(CFLAGS) $(INCLUDE) src/number_utils/Number.cpp -c -o src/number_utils/Number.o

src/number_utils/NumberInBase2.o: src/number_utils/NumberInBase2.cpp
	$(CC) $(CFLAGS) $(INCLUDE) src/number_utils/NumberInBase2.cpp -c -o src/number_utils/NumberInBase2.o

src/number_utils/NumberInBase10.o: src/number_utils/NumberInBase10.cpp
	$(CC) $(CFLAGS) $(INCLUDE) src/number_utils/NumberInBase10.cpp -c -o src/number_utils/NumberInBase10.o

src/exceptions/InvalidBaseException.o: src/exceptions/InvalidBaseException.cpp
	$(CC) $(CFLAGS) $(INCLUDE) src/exceptions/InvalidBaseException.cpp -c -o src/exceptions/InvalidBaseException.o

src/exceptions/InvalidNumberException.o: src/exceptions/InvalidNumberException.cpp
	$(CC) $(CFLAGS) $(INCLUDE) src/exceptions/InvalidNumberException.cpp -c -o src/exceptions/InvalidNumberException.o

clean:
	$(RM) $(EXECUTABLE) src/*.o src/number_utils/*.o src/exceptions/*.o
	$(RM) bin
