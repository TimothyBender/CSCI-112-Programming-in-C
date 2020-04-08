Program1: calcgrades.o main.o print.o readgrades.o
	gcc -o Program1 calcgrades.o main.o print.o readgrades.o

calcgrades.o: calcgrades.c student.h
	gcc -c -Wall calcgrades.c

main.o: main.c student.h
	gcc -c -Wall main.c

readgrades.o: readgrades.c student.h
	gcc -c -Wall readgrades.c

print.o: print.c student.h
	gcc -c -Wall print.c
