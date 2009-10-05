EXE = brainfick

all: $(EXE)

$(EXE): main.o options.o files.o translation.o
	gcc $^ -o$(EXE)

main.o: main.c
	gcc -c main.c

options.o: options.c options.h
	gcc -c options.c

files.o: files.c files.h
	gcc -c files.c

translation.o: translation.c translation.h
	gcc -c translation.c

clean:
	rm *.o $(EXE)

