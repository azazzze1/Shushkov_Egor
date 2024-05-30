all: main.o read_text.o tasks.o mutual_act.o
	gcc main.o read_text.o tasks.o mutual_act.o -o main
main.o: main.c main.h read_text.h tasks.h mutual_act.h
	gcc -c main.c
read_text.o: read_text.c main.h read_text.h
	gcc -c read_text.c
tasks.o: tasks.c main.h tasks.h
	gcc -c tasks.c
mutual_act.o: mutual_act.c main.h mutual_act.h
	gcc -c mutual_act.c
clean:
	rm *.o