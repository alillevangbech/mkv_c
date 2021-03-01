



CPPFLAGS = -D_POSIX_C_SOURCE=200809L
CFLAGS   = -std=c99 -pedantic -Wall -Wextra -Os ${CPPFLAGS}
LDFLAGS  = -lcurl

run: main.o network.o
	${CC} -o run main.o network.o ${LDFLAGS}

main.o: main.c network.h
	${CC} -c main.c 

network.o: network.c network.h
	${CC} -c network.c 

clean: 
	rm -rf network.o main.o run
