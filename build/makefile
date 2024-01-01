CC=gcc
CFLAGS= -Wall -g


all: example
debug: example  # TODO: add logic for different flags


# Start n-ary-trees

record.o: ../record.c
	$(CC) $(CFLAGS) -c ../record.c

bt.o: ../bt/bt.c
	$(CC) $(CFLAGS) -c ../bt/bt.c

bt_io.o: ../bt/bt_io.c
	$(CC) $(CFLAGS) -c ../bt/bt_io.c

bst.o: ../bt/bst/bst.c
	$(CC) $(CFLAGS) -c ../bt/bst/bst.c

avl.o: ../bt/bst/avl/avl.c
	$(CC) $(CFLAGS) -c ../bt/bst/avl/avl.c

# End n-ary-trees


example: example.o bst.o bt_io.o bt.o record.o
	$(CC) $(CFLAGS) -o example example.o bst.o bt_io.o bt.o record.o

example.o: ../example.c
	$(CC) $(CFLAGS) -c ../example.c


.PHONY: clean
clean:
	$(RM) record.o
	$(RM) bt.o
	$(RM) bt_io.o
	$(RM) bst.o
	$(RM) avl.o

	$(RM) example
	$(RM) example.o
	
	$(RM) bt_print.o
	$(RM) bt_print
	$(RM) bt_read.o
	$(RM) bt_read
