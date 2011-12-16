all:
	gcc src/ghstuff.c src/ghissue.c src/ghcurl.c src/ghjson.c  src/githubit.c -o bin/githubit -lcurl -ljansson
debug:
	gcc src/ghstuff.c src/ghissue.c src/ghcurl.c src/ghjson.c  src/githubit.c -o bin/githubit -lcurl -ljansson -g

clean:
	rm bin/githubit
