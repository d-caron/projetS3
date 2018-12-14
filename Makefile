#makefile pile dynamique
CC = cc
CFLAGS =-Wall -g

EXECS = \
	build/rev_party

all : $(EXECS)

clean:
	rm -rf $(EXECS) *.o

build/rev_party: obj/main.o obj/args.o
	$(CC) -o $@ $^ $(CFLAGS)

obj/args.o: head/args.h

obj/%.o: src/%.c
	$(CC) -c $< -o $@ $(CFLAGS)
