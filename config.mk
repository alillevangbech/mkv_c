# mkv_c version
VERSION = 0

# customize below to fit your system

CURLINC = /usr/include/curl/
CURLLIB = /usr/lib/libcurl.so

OPENSSLINC = /usr/include/openssl/
OPENSSLLIB = /usr/lib/libevent_openssl.so

LEVELDBINC = /usr/include/leveldb/
LEVELDBLIB = /usr/lib/libleveldb.so

CPPFLAGS = -I$(CURLINC) -I$(OPENSSLINC) -I$(LEVELDBINC) -D_POSIX_C_SOURCE=200809L
CFLAGS   = -std=c99 -pedantic -Wall -Wextra -Os 

LDFLAGS  = -L$(CURLLIB) -L$(OPENSSLLIB) -L$(LEVELDBLIB) -s
LDLIBS   = -lcurl -lcrypto -lleveldb

CC = cc
