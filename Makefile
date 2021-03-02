.POSIX:

SRC_DIR = ./src

SRC = ${SRC_DIR}/network.c \
      ${SRC_DIR}/main.c

OBJ = ${SRC:.c=.o}

CPPFLAGS = -D_POSIX_C_SOURCE=200809L
CFLAGS   = -std=c99 -pedantic -Wall -Wextra -Os ${CPPFLAGS}
LDFLAGS  = -lcurl

PRG_NAME = mkv_c

# creates executable
all: ${OBJ}
	${CC} -o ${PRG_NAME} ${OBJ} ${LDFLAGS}

# creates .o files from .c files with same names
${SRC_DIR}/.c.o:
	${CC} -c ${CFLAGS} $<

clean: 
	rm -rf ${OBJ} ${PRG_NAME}

.PHONY: all clean

