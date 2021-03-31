.POSIX:

SRC_DIR  = ./src
UTIL_DIR = ${SRC_DIR}/utils

SRC = ${SRC_DIR}/network.c \
      ${SRC_DIR}/main.c \
      ${UTIL_DIR}/base64.c \
      ${UTIL_DIR}/md5.c

OBJ = ${SRC:.c=.o}

CFLAGS   = -std=c99 -pedantic -Wall -Wextra -Os -D_POSIX_C_SOURCE=200809L
LDFLAGS  = -lcurl -L/usr/bin/ 

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

