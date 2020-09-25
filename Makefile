output: shell.o
	gcc -o sh shell.o
shell.o: shell.c
	gcc -c shell.c
clean:
	rm *.o sh