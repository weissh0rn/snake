CC = gcc
CFLAGS = -g -std=c11 -Wall -Werror

snake.o: snake.c
	$(CC) $(CFLAGS) -c snake.c -o snake.o

apple.o: apple.c
	$(CC) $(CFLAGS) -c apple.c -o apple.o

main: main.c snake.o apple.o
	$(CC) $(CFLAGS) main.c snake.o apple.o -o main -lncurses


