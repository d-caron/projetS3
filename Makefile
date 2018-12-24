#makefile pile dynamique
CC = cc
CFLAGS =-Wall -g

EXECS = \
	build/rev_party \
	build/test

all : $(EXECS)

clean:
	rm -rf $(EXECS) *.o

build/rev_party: obj/main.o obj/args.o obj/utils_sd.o obj/lecture_csv.o obj/csv_to_duel.o
	$(CC) -o $@ $^ $(CFLAGS)

build/test: obj/test.o obj/args.o obj/utils_sd.o obj/lecture_csv.o obj/csv_to_duel.o
	$(CC) -o $@ $^ $(CFLAGS)

obj/args.o: head/args.h
obj/utils_sd.o: head/squelette.h
obj/lecture_csv.o: head/lecture_csv.h 
obj/csv_to_duel: head/csv_to_duel.h

obj/%.o: src/%.c
	$(CC) -c $< -o $@ $(CFLAGS)
	
