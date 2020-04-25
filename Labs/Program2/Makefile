pgm1: main.o readg.o inserthead.o printg.o calcg.o sort.o 
	gcc -o Program2 main.o readg.o inserthead.o printg.o calcg.o sort.o

main.o: grades.h main.c
	gcc -c -Wall main.c

inserthead.o: grades.h inserthead.c
	gcc -c -Wall inserthead.c

readg.o: grades.h readg.c
	gcc -c -Wall readg.c

printg.o: grades.h printg.c
	gcc -c -Wall printg.c

calcg.o: grades.h calcg.c
	gcc -c -Wall calcg.c

sort.o: grades.h sort.c
	gcc -c -Wall sort.c
