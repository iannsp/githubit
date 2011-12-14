all:
	gcc src/githubit.c src/ghstuff.c src/ghissue.c -o bin/githubit

clean:
	rm bin/githubit
