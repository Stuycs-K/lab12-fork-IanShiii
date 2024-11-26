.PHONY: run compile clean

run: program
	@./program
compile program: main.c
	@gcc -o program main.c
clean:
	@rm -f program
