.PHONY: clean
CC=gcc
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
DEP=$(SRC:.c=.d)
-include $(DEP)
a.out:$(OBJ)
	gcc $^ -o $@

clean:
	rm -rf *.o *.d a.out
