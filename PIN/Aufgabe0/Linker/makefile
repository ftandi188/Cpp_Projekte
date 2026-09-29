CC=gcc
BINARY=maincode.exe

$(BINARY): maincode.o libcode.o
	$(CC) -o $@ maincode.o libcode.o

maincode.o: maincode.c libcode.h
	$(CC) -c -o $@ $<

libcode.o: libcode.c libcode.h
	$(CC) -c -o $@ $<