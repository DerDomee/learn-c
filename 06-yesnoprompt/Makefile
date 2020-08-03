CC = gcc
CFLAGS = -std=c11 -pedantic -D_XOPEN_SOURCE=600 -Wall

PROG = yesno
SOURCE = $(PROG).c
OBJS = $(SOURCE:%.c=%.o)
HEADER = $(SOURCE:%.c=%.h)

.PHONY: all install uninstall clean


all: $(PROG)


$(PROG): libprompt.o $(PROG).o
	mkdir -p build
	$(CC) $(CFLAGS) -o build/$(PROG) build/libprompt.o build/$(PROG).o


%.o: %.c
	mkdir -p build
	$(CC) $(CFLAGS) -c -o build/$@ $< 


install:
	cp build/$(PROG) /usr/bin


uninstall:
	rm -f /usr/bin/$(PROG)


clean:
	rm -rf build
