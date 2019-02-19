CC=g++
IPATH=./TxtGameEngine/
LPATH=-
LIBS=-
CFLAGS= -I $(IPATH) 

main:
	$(CC) main.cpp TxtGameEngine/*.cpp -o out $(CFLAGS)
