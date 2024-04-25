CC=g++
CFLAGS=-Wall -std=c++11

SRC=*.cpp  ./include/*.cpp

TARGET=main

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)



clean:
	rm -f $(TARGET)