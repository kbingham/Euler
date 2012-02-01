CFLAGS += -g -Wall -Werror

LDFLAGS += common.o

TARGETS = common.o prime
TARGETS += problem1 problem2

all: ${TARGETS}

clean:
	rm ${TARGETS}

common.o: common.c

