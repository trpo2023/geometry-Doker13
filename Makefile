main: main.o PaS.o parser.o
	gcc -Wall -O0 -g  -o main main.o PaS.o parser.o
PaS.o: PaS.c
	gcc -Wall -O0 -g  -c -o PaS.o PaS.c
parser.o: parser.c
	gcc -Wall -O0 -g  -c -o parser.o parser.c
main.o: main.c
	gcc -Wall -O0 -g  -c -o main.o main.c

clean: 
	rm *.o
