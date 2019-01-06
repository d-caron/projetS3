#makefile projetS3 : REV'PARTY
CC = cc
CFLAGS =-Wall -g

EXECS = \
	build/rev_party \
	build/test

all : $(EXECS)

clean:
	rm -rf $(EXECS) *.o

build/rev_party: \
	obj/main.o \
	obj/args.o \
	obj/utils_sd.o \
	obj/lecture_csv.o \
	obj/csv_to_duel.o \
	obj/uni.o \
	obj/liste.o \
	obj/elementliste.o \
	obj/duel_to_liste.o \
	obj/graphe_python.o \
	obj/condorcet.o \
	obj/vote_alternatif.o

	$(CC) -o $@ $^ $(CFLAGS)

build/test: \
	obj/test.o \
	obj/args.o \
	obj/utils_sd.o \
	obj/lecture_csv.o \
	obj/csv_to_duel.o \
	obj/uni.o \
	obj/liste.o \
	obj/elementliste.o \
	obj/duel_to_liste.o \
	obj/graphe_python.o \
	obj/condorcet.o \
	obj/vote_alternatif.o

	$(CC) -o $@ $^ $(CFLAGS)

obj/uni.o: head/uni.h
obj/args.o: head/args.h
obj/utils_sd.o: head/squelette.h
obj/lecture_csv.o: head/lecture_csv.h 
obj/csv_to_duel: head/csv_to_duel.h
obj/liste.o: head/liste.h
obj/elementliste.o: head/elementliste.h
obj/duel_to_liste.o: head/duel_to_liste.h
obj/graphe_python.o: head/graphe_python.h
obj/condorcet.o: head/condorcet.h
obj/vote_alternatif.o: head/vote_alternatif.h

obj/%.o: src/%.c
	$(CC) -c $< -o $@ $(CFLAGS)
