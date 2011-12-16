all:
	gcc src/ghstuff.c src/ghissue.c src/ghcurl.c src/githubit.c -o bin/githubit -lcurl
debug:
	gcc src/ghstuff.c src/ghissue.c src/ghcurl.c src/githubit.c -o bin/githubit -lcurl -g

clean:
	rm bin/githubit
