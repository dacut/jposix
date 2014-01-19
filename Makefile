-include /etc/lsb-release

ifeq ($(DISTRIB_ID),Ubuntu)
JDK_DIR = /usr/lib/jvm/default-java
JDK_BIN_DIR = $(JDK_DIR)/bin
JAVAC = $(JDK_BIN_DIR)/javac
else
JAVAC = $(shell which javac)
JDK_BIN_DIR = $(dir $(JAVAC))
JDK_DIR = $(JDK_BIN_DIR:%/bin/=%)
endif

TARGET = build/libjposix-0.1.so
CPPFLAGS = -I${JDK_DIR}/include -I${JDK_DIR}/include/linux \
 -D_POSIX_C_SOURCE=200112L -D_XOPEN_SOURCE=600 -D_FILE_OFFSET_BITS=64 \
 -D_BSD_SOURCE -D_REENTRANT -D_GNU_SOURCE \
 -DHAS_FEXECVE -DHAS_GETRESUID -DHAS_GETRESGID -DHAS_GETSID
CFLAGS = ${CPPFLAGS} -g -fPIC -Wall
LDFLAGS = -Wl,-soname -Wl,libjposix-0.1

SRCS = jposix_Utils.c jposix_Posix.c jposix_Posix_constants.c
OBJS = ${SRCS:%.c=build/objects/%.o}

CC = gcc
LD = gcc -shared

all: ${TARGET} build/jposix-0.1-g.jar

${TARGET}: ${OBJS}
	${LD} ${LDFLAGS} -o ${TARGET} ${OBJS} -lcrypt

build/objects/%.o: src/c/%.c
	mkdir -p build/objects
	${CC} ${CFLAGS} -c -o $@ $<

build/jposix-0.1-g.jar: src/java/jposix/*.java src/java/jposix/struct/*.java \
	src/java-tests/jposix/test/*.java
	ant

clean:
	rm -rf build
	find . \( -name \*~ -o -name core.* \) -exec rm {} \;

.PHONY: all clean

