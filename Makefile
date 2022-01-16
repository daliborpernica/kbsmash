CC = gcc
FLAGS = -O2 -Wall -Wextra -ansi -pedantic

all: kbsmash

%.o: %.c
	$(CC) -c -o $@ $< $(FLAGS)
kbsmash: kbsmash.c render.o list.o shape.o
	$(CC) -o $@ $^ -lglut -lGL $(FLAGS)

clean:
	rm -f kbsmash ./*.o
