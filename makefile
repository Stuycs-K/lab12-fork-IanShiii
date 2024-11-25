.PHONY: run compile clean

run: program
	@./program
compile program: main.o instructions.o
	@gcc -o program main.o instructions.o
main.o: main.c instructions.c instructions.h
	@gcc -c main.c
instructions.o: instructions.c instructions.h
	@gcc -c instructions.c
clean:
	@rm -f program *.o
