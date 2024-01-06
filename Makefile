AR = ar
CC = gcc
CFLAGS = -c -O2 -Wall

all: libhdb.a

libhdb.a: db.o tx.o
	$(AR) rcs $@ $^
	
%.o: %.c
	$(CC) $(CFLAGS) $@ $<

test: test.c libhdb.a
	$(CC) -o $@ test.c -I. -lhdb

clean:
	rm *.o
	rm *.a
