CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -pedantic
LIBS=-lm
OBJS=*.o
DEPS=*.h
bindir=/usr/local/bin
area: $(OBJS)
	$(CC) -o $(OBJS) $(LIBS)
area.o: $(DEPS)

clean:
	rm $(OBJS)
