all: q1 q2

q1: q1.c nodeM.c
	gcc -Wall -std=c99 -pedantic q1.c nodeM.c -o q1

q2: q2.c stack.c
	gcc -Wall -std=c99 -pedantic q2.c stack.c -o q2

clean:
	rm -rf *o q1 q2
