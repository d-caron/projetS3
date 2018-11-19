#makefile pile dynamique
CC = cc
CFLAGS =-Wall -g

EXECS = \
	build/rev_party

all : $(EXECS)

clean:
	rm -rf $(EXECS) *.o

build/rev_party: obj/main.o
	$(CC) -o $@ $^ $(CFLAGS)

#obj/pile.o: head/pile.h
#obj/main.o: head/pile.h head/test.h

obj/%.o: src/%.c
	$(CC) -c $< -o $@ $(CFLAGS)
