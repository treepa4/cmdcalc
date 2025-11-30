opcalc.o: opcalc.c opcalc.h
	gcc -c opcalc.c
cmdcalc.o: cmdcalc.c
	gcc -c cmdcalc.c
all: opcalc.o cmdcalc.o
	gcc opcalc.o cmdcalc.o -o cmdcalc 
run: 
	./cmdcalc
