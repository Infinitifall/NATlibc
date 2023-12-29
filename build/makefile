CC=gcc
CFLAGS= -Wall -g


all: example
debug: example  # TODO: add logic for different flags


# Start n-ary-trees

record.o: ../record.c
	$(CC) $(CFLAGS) -c ../record.c

bt.o: ../bt/bt.c
	$(CC) $(CFLAGS) -c ../bt/bt.c

bt_print.o: ../bt/bt_print.c
	$(CC) $(CFLAGS) -c ../bt/bt_print.c

bt_read.o: ../bt/bt_read.c
	$(CC) $(CFLAGS) -c ../bt/bt_read.c

bst.o: ../bt/bst/bst.c
	$(CC) $(CFLAGS) -c ../bt/bst/bst.c

# End n-ary-trees


example: example.o bst.o bt_read.o bt_print.o bt.o record.o
	$(CC) $(CFLAGS) -o example example.o bst.o bt_read.o bt_print.o bt.o record.o

example.o: ../example.c
	$(CC) $(CFLAGS) -c ../example.c


.PHONY: clean
clean:
	$(RM) record.o
	$(RM) bt.o
	$(RM) bt_read.o
	$(RM) bt_print.o
	$(RM) bst.o

	$(RM) example
	$(RM) example.o

	$(RM) simple
	$(RM) simple.o
