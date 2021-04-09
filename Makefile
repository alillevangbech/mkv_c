.POSIX:

include config.mk

SRC_DIR  = ./src

SRC = ${SRC_DIR}/network.c \
      ${SRC_DIR}/main.c \
      ${SRC_DIR}/base64.c \
      ${SRC_DIR}/md5.c \
      ${SRC_DIR}/lib.c

OBJ = ${SRC:.c=.o}


PRG_NAME = mkv_c

# creates executable
all: ${OBJ}
	${CC} -o ${PRG_NAME} $(LDFLAGS) ${OBJ} $(LDLIBS)

# creates .o files from .c files with same names
${SRC_DIR}/.c.o:
	${CC} -c $(CPPFLAGS) $(CFLAGS) $<

clean: 
	rm -rf ${OBJ} ${PRG_NAME}

.PHONY: all clean

