all:
	gcc src/githubit.c src/ghstuff.c -o bin/githubit

clean:
	rm bin/githubit
